#include <CoreFoundation/CFSocket.h>
#include "app/app.h"
#include "app/stream.h"
#include "platform/darwin.h"

/*
 * Per Apple:
 *
 * > The new CFSocket object, or NULL if an error occurred. If a CFSocket object already
 * > exists for sock, the function returns the pre-existing object instead of creating a new
 * > object; the context, callout, and callBackTypes parameters are ignored in this case.
 *
 * As a result, we'll always monitor for both reads and writes, regardless of the actual
 * subscription and we'll only remove the source when neither subscription is present.
 */

bool ardillo_stream_monitor(ardillo_stream_subscription_t *sub, ardillo_App_t *app)
{
    CFSocketCallBackType type = kCFSocketWriteCallBack | kCFSocketReadCallBack;
    CFSocketContext ctx = {0, app, NULL, NULL, NULL};
    CFSocketRef sock = CFSocketCreateWithNative(kCFAllocatorDefault, sub->fd, type, ardillo_darwin_on_stream_event, &ctx);

    if (!sock) {
        zend_error(E_CORE_WARNING, "Ardillo\\App::addReadStream cannot add stream");
        return 0;
    }

    CFOptionFlags opt = CFSocketGetSocketFlags(sock);
    opt &= ~kCFSocketCloseOnInvalidate;

    CFSocketSetSocketFlags(sock, opt);

    sub->src = (CFRunLoopSourceRef)CFSocketCreateRunLoopSource(kCFAllocatorDefault, sock, 0);
    CFRelease(sock);

    if (!sub->src) {
        zend_error(E_CORE_WARNING, "Ardillo\\App::addReadStream cannot add stream");
        return 0;
    }

    CFRunLoopAddSource(CFRunLoopGetCurrent(), sub->src, kCFRunLoopCommonModes);

    return 1;
}

void ardillo_stream_unmonitor(ardillo_stream_subscription_t *sub)
{
    if (!ardillo_stream_subscriptions_find_by_fd(&ardillo_default_app->stream_subscriptions, sub->fd, !sub->write)) {
        CFRunLoopRemoveSource(CFRunLoopGetCurrent(), (CFRunLoopSourceRef)sub->src, kCFRunLoopCommonModes);
        CFRelease((CFRunLoopSourceRef)sub->src);
    }
}

void ardillo_darwin_on_stream_event(CFSocketRef sock, CFSocketCallBackType type, CFDataRef addr, void const *data, void *ctx)
{
    bool write = type & kCFSocketWriteCallBack;
    php_socket_t fd = (php_socket_t)CFSocketGetNative(sock);
    ardillo_stream_subscription_t *sub = ardillo_stream_subscriptions_find_by_fd(&((ardillo_App_t *)ctx)->stream_subscriptions, fd, write);

    if (!sub) {
        return;
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
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\StreamEventHandler");
        return;
    }
}
