#include "php.h"
#include "php_network.h"
#include "ardillo_arginfo.h"
#include "app/app.h"
#include "app/stream.h"
#include "util/debug.h"

zend_class_entry *ce_Ardillo_StreamEventHandler;

PHP_MINIT_FUNCTION(Ardillo_StreamEventHandler)
{
    ce_Ardillo_StreamEventHandler = register_class_Ardillo_StreamEventHandler();

    return SUCCESS;
}

php_socket_t ardillo_get_stream_fd(zval *zstream)
{
    if (Z_TYPE_P(zstream) != IS_RESOURCE) {
        return -1;
    }

    php_stream *stream;
    php_socket_t fd = -1;

    if ((stream = (php_stream *)zend_fetch_resource_ex(zstream, NULL, php_file_le_stream()))) {
        if (php_stream_cast(stream, PHP_STREAM_AS_FD_FOR_SELECT | PHP_STREAM_CAST_INTERNAL, (void*)&fd, 1) == SUCCESS && fd >= 0) {
            return fd;
        }
    }

    return -1;
}

void ardillo_stream_subscriptions_cleanup_list(void *data)
{
}

int ardillo_stream_subscriptions_compare(void *s1, void *s2)
{
    return (((ardillo_stream_subscription_t *)s1)->fd == ((ardillo_stream_subscription_t *)s2)->fd)
        && (((ardillo_stream_subscription_t *)s1)->write == ((ardillo_stream_subscription_t *)s2)->write);
}

void ardillo_stream_subscriptions_add(zend_llist *tracker, ardillo_stream_subscription_t *sub)
{
    zend_llist_add_element(tracker, sub);
}

ardillo_stream_subscription_t* ardillo_stream_subscriptions_find_by_fd(zend_llist *tracker, php_socket_t fd, bool write)
{
    ardillo_stream_subscription_t *p = NULL;
    zend_llist_position pos;

    for (p = (ardillo_stream_subscription_t *)zend_llist_get_first_ex(tracker, &pos); p;
        p = (ardillo_stream_subscription_t *)zend_llist_get_next_ex(tracker, &pos)) {

        if ((p->fd == fd) && (p->write == write)) {
            ardillo_debug("ardillo_stream_subscriptions_find_by_fd(%d, %d) Looking at fd: %d write: %d (MATCH) return %p\n", fd, write, p->fd, p->write, p);
            return p;
        } else {
            ardillo_debug("ardillo_stream_subscriptions_find_by_fd(%d, %d) Looking at fd: %d write: %d (mismatch)\n", fd, write, p->fd, p->write);
        }
    }

    ardillo_debug("ardillo_stream_subscriptions_find_by_fd(%d, %d) return NULL\n", fd, write);

    return NULL;
}

void ardillo_stream_subscriptions_find_any(zend_llist *tracker, php_socket_t fd,
    ardillo_stream_subscription_t **read, ardillo_stream_subscription_t **write)
{
    ardillo_stream_subscription_t *p = NULL;
    zend_llist_position pos;

    for (p = (ardillo_stream_subscription_t *)zend_llist_get_first_ex(tracker, &pos); p;
        p = (ardillo_stream_subscription_t *)zend_llist_get_next_ex(tracker, &pos)) {

        if (p->fd == fd) {
            if (!p->write && read) {
                *read = p;
            } else if (p->write && write) {
                *write = p;
            }

            ardillo_debug("ardillo_stream_subscriptions_find_any(%d) Looking at fd: %d write: %d (MATCH)\n", fd, p->fd, p->write);
        } else {
            ardillo_debug("ardillo_stream_subscriptions_find_any(%d) Looking at fd: %d write: %d (mismatch)\n", fd, p->fd, p->write);
        }
    }

    return;
}

void ardillo_stream_subscriptions_del(zend_llist *tracker, ardillo_stream_subscription_t *sub)
{
    ardillo_stream_unmonitor(sub);
    zend_llist_del_element(tracker, sub, ardillo_stream_subscriptions_compare);
}
