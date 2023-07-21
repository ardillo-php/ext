#ifndef __ARDILLO_APP_STREAM_H
#define __ARDILLO_APP_STREAM_H

#include "php_network.h"
#include "app/app.h"

extern zend_class_entry *ce_Ardillo_StreamEventHandler;

typedef struct _ardillo_stream_subscription_t {
    php_socket_t fd;
    zend_object *handler;
    bool write;
    void *src;
} ardillo_stream_subscription_t;

PHP_MINIT_FUNCTION(Ardillo_StreamEventHandler);

php_socket_t ardillo_get_stream_fd(zval *zstream);

bool ardillo_stream_monitor(ardillo_stream_subscription_t *sub, ardillo_App_t *app);
void ardillo_stream_unmonitor(ardillo_stream_subscription_t *sub);
void ardillo_stream_subscriptions_cleanup_list(void *data);
int ardillo_stream_subscriptions_compare(void *s1, void *s2);
void ardillo_stream_subscriptions_add(zend_llist *tracker, ardillo_stream_subscription_t *sub);
ardillo_stream_subscription_t* ardillo_stream_subscriptions_find_by_fd(zend_llist *tracker, php_socket_t fd, bool write);
void ardillo_stream_subscriptions_del(zend_llist *tracker, ardillo_stream_subscription_t *sub);

#endif /* __ARDILLO_APP_STREAM_H */
