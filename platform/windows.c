#include <winsock2.h>
#include <windows.h>
#include <errno.h>
#include "ui.h"
#include "app/app.h"
#include "app/stream.h"
#include "platform/wepoll.h"
#include "platform/windows.h"
#include "util/debug.h"

bool ardillo_io_running = 0;
HANDLE ardillo_iothread = NULL, ardillo_ephnd = -1;
DWORD ardillo_parent_thread;

void ardillo_stream_callback(ardillo_stream_subscription_t *sub)
{
    zval params[1];
    ZVAL_LONG(&params[0], sub->fd);
    zval retval;
    zend_string *method;

    if (!sub->write) {
        method = zend_string_init("onReadEvent", strlen("onReadEvent"), 0);
    } else {
        method = zend_string_init("onWriteEvent", strlen("onWriteEvent"), 0);
    }

    int successful = zend_call_method_if_exists(sub->handler, method, &retval, 1, params);
    zend_string_release(method);
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\StreamEventHandler");
        return;
    }
}

void ardillo_windows_on_stream_event(struct epoll_event *event)
{
    php_socket_t fd = (php_socket_t)(event->data.fd);
    ardillo_stream_subscription_t *read = NULL, *write = NULL;
    uint32_t rearm = 0;

    ardillo_debug("ardillo_windows_on_stream_event() Event received for %d read: %d, write: %d, rdhup: %d, pri: %d, err: %d, hup: %d\n",
        fd, (event->events & EPOLLIN) ? 1 : 0, (event->events & EPOLLOUT) ? 1 : 0,
        (event->events & EPOLLRDHUP) ? 1 : 0, (event->events & EPOLLPRI) ? 1 : 0,
        (event->events & EPOLLERR) ? 1 : 0, (event->events & EPOLLHUP) ? 1 : 0);

    ardillo_stream_subscriptions_find_any(&((ardillo_App_t *)ardillo_default_app)->stream_subscriptions, fd, &read, &write);

    if (!read && !write) {
        ardillo_debug("ardillo_windows_on_stream_event() Cannot find subscriptions for %d\n", fd);
        return;
    }

    if (read && (event->events & EPOLLIN)) {
        ardillo_stream_callback(read);
    }

    if (write && (event->events & EPOLLOUT)) {
        ardillo_stream_callback(write);
    }

    read = NULL;
    write = NULL;

    ardillo_stream_subscriptions_find_any(&((ardillo_App_t *)ardillo_default_app)->stream_subscriptions, fd, &read, &write);

    rearm = (read ? EPOLLIN : 0) | (write ? EPOLLOUT : 0);

    if (!rearm) {
        ardillo_debug("ardillo_windows_on_stream_event() Cannot find subscriptions for %d\n, not rearming", fd);
        epoll_ctl(ardillo_ephnd, EPOLL_CTL_DEL, fd, NULL);
    } else {
        event->events = rearm | ARDILLO_EPOLL_FLAGS | EPOLLONESHOT;

        ardillo_debug("ardillo_windows_on_stream_event() Rearming %d read: %d, write: %d\n",
            fd, (rearm & EPOLLIN) ? 1 : 0, (rearm & EPOLLOUT) ? 1 : 0);

        if (epoll_ctl(ardillo_ephnd, EPOLL_CTL_MOD, fd, event) == -1) {
            ardillo_debug("ardillo_windows_on_stream_event() Cannot rearm %d read: %d, write: %d (errno: %d)",
                fd, (rearm & EPOLLIN) ? 1 : 0, (rearm & EPOLLOUT) ? 1 : 0, errno);
        }
    }

    ardillo_debug("ardillo_windows_on_stream_event() Done processing event for %d read: %d, write: %d\n",
        fd, (event->events & EPOLLIN) ? 1 : 0, (event->events & EPOLLOUT) ? 1 : 0);
}

void ardillo_stream_wait(void *unused)
{
    struct epoll_event events[ARDILLO_MAX_IO_EVENTS];
    int i, n;

    while (ardillo_io_running) {
        n = epoll_wait(ardillo_ephnd, events, ARDILLO_MAX_IO_EVENTS, -1);
        ardillo_debug("ardillo_stream_wait() Got %d event(s)\n", n);

        if (n == -1) {
            zend_error(E_CORE_ERROR, "I/O polling error occurred");
            return;
        }

        for (i = 0; i < n; i++) {
            ardillo_debug("ardillo_stream_wait() - event: %d fd: %d read: %d, write: %d, rdhup: %d, pri: %d, err: %d, hup: %d\n",
                i, events[i].data.fd, (events[i].events & EPOLLIN) ? 1 : 0, (events[i].events & EPOLLOUT) ? 1 : 0,
                (events[i].events & EPOLLRDHUP) ? 1 : 0, (events[i].events & EPOLLPRI) ? 1 : 0,
                (events[i].events & EPOLLERR) ? 1 : 0, (events[i].events & EPOLLHUP) ? 1 : 0);
            uiQueueMain(ardillo_windows_on_stream_event, &events[i]);
        }
    }
}

bool ardillo_stream_init()
{
    ardillo_debug("About to run ardillo_stream_init()\n");

    ardillo_parent_thread = GetCurrentThreadId();

    ardillo_debug("ardillo_stream_init() Parent thread ID: %d\n", ardillo_parent_thread);

    if (ardillo_io_running) {
        zend_error(E_CORE_ERROR, "Cannot reinitialize already running I/O wait thread");
        return 0;
    }

    if (ardillo_iothread || (ardillo_ephnd > -1)) {
        zend_error(E_CORE_ERROR, "Cannot reinitialize I/O wait thread");
        return 0;
    }

    ardillo_ephnd = epoll_create1(0);
    if (ardillo_ephnd == -1) {
        zend_error(E_CORE_ERROR, "Cannot initialize I/O polling handler");
        return 0;
    }

    ardillo_iothread = CreateThread(NULL, 0, ardillo_stream_wait, NULL, 0, NULL);
    if (!ardillo_iothread) {
        zend_error(E_CORE_ERROR, "Cannot initialize I/O wait thread");
        return 0;
    }

    ardillo_io_running = 1;

    ardillo_debug("Done running ardillo_stream_init()\n");

    return 1;
}

bool ardillo_stream_monitor(ardillo_stream_subscription_t *sub, ardillo_App_t *app)
{
    if (!ardillo_iothread) {
        if (!ardillo_stream_init()) {
            return 0;
        }
    }

    ardillo_debug("ardillo_stream_monitor() About to add fd: %d write: %d\n", sub->fd, sub->write);

    struct epoll_event event;
    int op = EPOLL_CTL_ADD;

    event.data.fd = sub->fd;

    if (!ardillo_stream_subscriptions_find_by_fd(&ardillo_default_app->stream_subscriptions, sub->fd, !sub->write)) {
        event.events = (sub->write ? EPOLLOUT : EPOLLIN) | ARDILLO_EPOLL_FLAGS | EPOLLONESHOT;
    } else {
        event.events = EPOLLOUT | EPOLLIN | ARDILLO_EPOLL_FLAGS | EPOLLONESHOT;
        op = EPOLL_CTL_MOD;
    }

    if (epoll_ctl(ardillo_ephnd, op, sub->fd, &event) == -1) {
        zend_error(E_CORE_ERROR, "ardillo_stream_monitor() cannot add stream fd: %d write: %d (errno: %d)", sub->fd, sub->write, errno);
        return 0;
    }

    ardillo_debug("ardillo_stream_monitor() Done adding fd: %d write: %d\n", sub->fd, sub->write);

    return 1;
}

void ardillo_stream_unmonitor(ardillo_stream_subscription_t *sub)
{
    if (!ardillo_stream_subscriptions_find_by_fd(&ardillo_default_app->stream_subscriptions, sub->fd, !sub->write)) {
        ardillo_debug("ardillo_stream_unmonitor() About to remove fd: %d write: %d\n", sub->fd, sub->write);
        epoll_ctl(ardillo_ephnd, EPOLL_CTL_DEL, sub->fd, NULL);
        ardillo_debug("ardillo_stream_unmonitor() Done removing fd: %d write: %d\n", sub->fd, sub->write);
    } else {
        struct epoll_event event;

        event.data.fd = sub->fd;
        event.events = (!sub->write ? EPOLLOUT : EPOLLIN) | ARDILLO_EPOLL_FLAGS | EPOLLONESHOT;

        if (epoll_ctl(ardillo_ephnd, EPOLL_CTL_MOD, sub->fd, &event) == -1) {
            zend_error(E_CORE_ERROR, "Cannot modify stream");
            return;
        }

        ardillo_debug("ardillo_stream_unmonitor() Extra subscription found for fd: %d write: %d, will MOD instead\n", sub->fd, sub->write);
    }
}
