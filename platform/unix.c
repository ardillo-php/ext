#include <gtk/gtk.h>
#include "app/app.h"
#include "app/stream.h"
#include "platform/unix.h"

bool ardillo_stream_monitor(ardillo_stream_subscription_t *sub, ardillo_App_t *app)
{
    int conditions = sub->write ? G_IO_OUT : G_IO_IN | G_IO_PRI | G_IO_HUP;

    GIOChannel* channel = g_io_channel_unix_new(sub->fd);
    sub->src = (void *)(long)g_io_add_watch(channel, (GIOCondition)conditions, &ardillo_unix_on_stream_event, app);
    g_io_channel_unref(channel);

    if (!sub->src) {
        zend_error(E_CORE_WARNING, "Ardillo\\App::addReadStream cannot add stream");
        return 0;
    }

    return 1;
}

void ardillo_stream_unmonitor(ardillo_stream_subscription_t *sub)
{
    g_source_remove((unsigned)(long)sub->src);
}

gboolean ardillo_unix_on_stream_event(GIOChannel *channel, GIOCondition condition, gpointer data)
{
    bool write = condition & G_IO_OUT;
    php_socket_t fd = (php_socket_t)g_io_channel_unix_get_fd(channel);
    ardillo_stream_subscription_t *sub = ardillo_stream_subscriptions_find_by_fd(&((ardillo_App_t *)data)->stream_subscriptions, fd, write);

    if (!sub) {
        return 0;
    }

    zval params[1];
    ZVAL_LONG(&params[0], fd);
    zval retval;
    zend_string *method;

    if (!write) {
        method = zend_string_init("onReadEvent", strlen("onReadEvent"), 0);
    } else {
        method = zend_string_init("onWriteEvent", strlen("onWriteEvent"), 0);
    }

    int successful = zend_call_method_if_exists(sub->handler, method, &retval, 1, params);
    zend_string_release(method);
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return 0;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\StreamEventHandler");
        return 0;
    }

    return 1;
}
