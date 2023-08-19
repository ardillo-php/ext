#include <signal.h>
#include "php.h"
#include "php_network.h"
#include "ui.h"
#include "ardillo_arginfo.h"
#include "ui/types.h"
#include "app/app.h"
#include "app/menu.h"
#include "app/task.h"
#include "app/stream.h"
#include "util/debug.h"
#include "util/common.h"

zend_class_entry *ce_Ardillo_App;
zend_object_handlers App_object_handlers;
ardillo_App_t *ardillo_default_app = NULL;
ardillo_App_t *ardillo_last_app = NULL;

zend_object* ardillo_create_App_object(zend_class_entry *ce)
{
    if (ardillo_default_app) {
        zend_error(E_CORE_ERROR, "Cannot have more than one Ardillo\\App class instance at a time");
        return NULL;
    }

    ardillo_App_t *ardillo_s = ecalloc(1, sizeof(ardillo_App_t) + zend_object_properties_size(ce));

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    ardillo_s->std.handlers = &App_object_handlers;
    ALLOC_HASHTABLE(ardillo_s->tasks);
    zend_hash_init(ardillo_s->tasks, 0, NULL, ZVAL_PTR_DTOR, 0);
    zend_llist_init(&ardillo_s->stream_subscriptions, sizeof(ardillo_stream_subscription_t), ardillo_stream_subscriptions_cleanup_list, 0);

    ardillo_debug_objects(0, "Created App @%p\n", ardillo_s);

    ardillo_default_app = ardillo_s;

    return &ardillo_s->std;
}

void ardillo_free_App_object(zend_object *object)
{
    ardillo_App_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_App_t, object);

    ardillo_debug_objects(0, "Freeing App @%p (refcount: %d)\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_hash_destroy(ardillo_s->tasks);

    zend_llist_clean(&ardillo_s->stream_subscriptions);

    ardillo_last_app = ardillo_default_app;
    ardillo_default_app = NULL;

    ardillo_debug_objects(0, "Refcount for App @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));
    zend_object_std_dtor(&ardillo_s->std);

    FREE_HASHTABLE(ardillo_s->tasks);

    ardillo_debug_objects(0, "Done freeing App @%p\n", ardillo_s);
}

void ardillo_App_stop(ardillo_App_t *app)
{
    ardillo_debug("App::stop: About to run uiQuit()\n");
    uiQuit();
    ardillo_debug("App::stop: Done running uiQuit()\n");

    zend_string *key;
    zval *zv;
    zend_ulong idx;

    ZEND_HASH_FOREACH_KEY_VAL_IND(app->tasks, idx, key, zv) {
        /* Wipe any pending scheduled tasks */
        ardillo_debug_references(0, "Destroying task @%p refcount: %d\n", Z_OBJ_P(zv), GC_REFCOUNT(Z_OBJ_P(zv)));
        zend_hash_index_del(app->tasks, idx);
    } ZEND_HASH_FOREACH_END();

    ardillo_debug("App::stop: Done running App::stop()\n");
}

PHP_MINIT_FUNCTION(Ardillo_App)
{
    ce_Ardillo_App = register_class_Ardillo_App();
    ce_Ardillo_App->create_object = ardillo_create_App_object;

    memcpy(&App_object_handlers, zend_get_std_object_handlers(), sizeof(App_object_handlers));
    App_object_handlers.offset = XtOffsetOf(ardillo_App_t, std);
    App_object_handlers.free_obj = ardillo_free_App_object;

    return SUCCESS;
}

ZEND_METHOD(Ardillo_App, get)
{
    ZEND_PARSE_PARAMETERS_NONE();

    if (!ardillo_default_app) {
        RETURN_NULL();
    }

    zval ret;
    ZVAL_OBJ(&ret, &ardillo_default_app->std);
    RETVAL_ZVAL(&ret, 1, 0);
}

ZEND_METHOD(Ardillo_App, run)
{
    ZEND_PARSE_PARAMETERS_NONE();

    uiMain();
}

ZEND_METHOD(Ardillo_App, stop)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_App_stop(ARDILLO_ZVAL_GET_OBJECT(ardillo_App_t, getThis()));
}

ZEND_METHOD(Ardillo_App, appendMenu)
{
    zval *parent = NULL;
    zend_long type = 0;
    zend_long id = 0;
    zend_string *label = NULL;

    ZEND_PARSE_PARAMETERS_START(3, 4)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(parent, ce_Ardillo_Menu)
        Z_PARAM_LONG(type)
        Z_PARAM_LONG(id)
        Z_PARAM_OPTIONAL
        Z_PARAM_STR_OR_NULL(label)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    zend_object *obj = ardillo_create_Menu_object(ce_Ardillo_Menu);
    ardillo_Menu_t *pmenu = NULL;

    if (type > 0) {
        if (!parent) {
            zend_error(E_CORE_ERROR, "Cannot create menu item without a parent");
            RETURN_NULL();
        }

        pmenu = ARDILLO_ZVAL_GET_OBJECT(ardillo_Menu_t, parent);

        if (!pmenu->uis) {
            zend_error(E_CORE_ERROR, "Cannot create menu item with invalid parent");
            RETURN_NULL();
        }

        if (pmenu->type != 0) {
            zend_error(E_CORE_ERROR, "Cannot create menu item on a non-Top parent");
            RETURN_NULL();
        }
    }

    if ((!type || type >= 5) && !label) {
        zend_error(E_CORE_ERROR, "Cannot create menu item without a label");
        RETURN_NULL();
    }

    ARDILLO_GET_OBJECT(ardillo_Menu_t, obj)->type = type;

    switch (type) {
        case 0:
            ARDILLO_GET_OBJECT(ardillo_Menu_t, obj)->uis = uiNewMenu(ZSTR_VAL(label));
            break;

        case 1:
            uiMenuAppendSeparator(pmenu->uis);
            break;

        case 2:
            ARDILLO_GET_OBJECT(ardillo_Menu_t, obj)->uis = uiMenuAppendQuitItem(pmenu->uis);
            uiOnShouldQuit(ardillo_App_onShouldQuit, NULL);
            break;

        case 3:
            ARDILLO_GET_OBJECT(ardillo_Menu_t, obj)->uis = uiMenuAppendPreferencesItem(pmenu->uis);
            break;

        case 4:
            ARDILLO_GET_OBJECT(ardillo_Menu_t, obj)->uis = uiMenuAppendAboutItem(pmenu->uis);
            break;

        case 5:
            ARDILLO_GET_OBJECT(ardillo_Menu_t, obj)->uis = uiMenuAppendCheckItem(pmenu->uis, ZSTR_VAL(label));
            break;

        case 6:
            ARDILLO_GET_OBJECT(ardillo_Menu_t, obj)->uis = uiMenuAppendItem(pmenu->uis, ZSTR_VAL(label));
            break;
    }

    if (type >= 3) {
        uiMenuItemOnClicked(ARDILLO_GET_OBJECT(ardillo_Menu_t, obj)->uis, ardillo_App_onClicked, (void *)id);
    }

    zval ret;
    ZVAL_OBJ(&ret, obj);
    RETVAL_ZVAL(&ret, 0, 0);
}

ZEND_METHOD(Ardillo_App, scheduleTask)
{
    zval *task = NULL;
    zend_long interval = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_OBJECT_OF_CLASS(task, ce_Ardillo_Task)
        Z_PARAM_LONG(interval)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_App_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_App_t, getThis());

    if (zend_hash_next_index_insert(this->tasks, task)) {
        Z_ADDREF_P(task);
    }

    if (interval <= 0) {
        uiQueueMain(runFutureTickTask, Z_OBJ_P(task));
    } else {
        uiTimer(interval, runIntervalTask, Z_OBJ_P(task));
    }
}

ZEND_METHOD(Ardillo_App, addReadStream)
{
    zval *zstream = NULL;
    zval *handler = NULL;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_RESOURCE(zstream)
        Z_PARAM_OBJECT_OF_CLASS(handler, ce_Ardillo_StreamEventHandler)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    php_socket_t fd = ardillo_get_stream_fd(zstream);
    ardillo_debug("Ardillo\\App::addReadStream() fd: %d\n", fd);

    if (fd < 0) {
        zend_error(E_CORE_WARNING, "Ardillo\\App::addReadStream requires a valid stream (%d < 0)", fd);
        RETURN_LONG(-1);
    }

    ardillo_App_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_App_t, getThis());

    ardillo_stream_subscription_t sub;
    sub.fd = fd;
    sub.handler = Z_OBJ_P(handler);
    sub.write = 0;

    if (!ardillo_stream_monitor(&sub, this)) {
        ardillo_debug("Ardillo\\App::addReadStream() failed for fd: %d\n", fd);
        RETURN_LONG(-1);
    }

    ardillo_stream_subscriptions_add(&this->stream_subscriptions, &sub);
    RETURN_LONG(fd);
}

ZEND_METHOD(Ardillo_App, addWriteStream)
{
    zval *zstream = NULL;
    zval *handler = NULL;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_RESOURCE(zstream)
        Z_PARAM_OBJECT_OF_CLASS(handler, ce_Ardillo_StreamEventHandler)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    php_socket_t fd = ardillo_get_stream_fd(zstream);
    ardillo_debug("Ardillo\\App::addWriteStream() fd: %d\n", fd);

    if (fd < 0) {
        zend_error(E_CORE_WARNING, "Ardillo\\App::addWriteStream requires a valid stream (%d < 0)", fd);
        RETURN_LONG(-1);
    }

    ardillo_App_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_App_t, getThis());

    ardillo_stream_subscription_t sub;
    sub.fd = fd;
    sub.handler = Z_OBJ_P(handler);
    sub.write = 1;

    if (!ardillo_stream_monitor(&sub, this)) {
        RETURN_LONG(-1);
    }

    ardillo_stream_subscriptions_add(&this->stream_subscriptions, &sub);
    RETURN_LONG(fd);
}

ZEND_METHOD(Ardillo_App, removeReadStream)
{
    zend_long fd;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(fd)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_debug("Ardillo\\App::removeReadStream() fd: %lld\n", fd);

    if (fd < 0) {
        zend_error(E_CORE_ERROR, "Ardillo\\App::removeReadStream requires a valid stream (%lld < 0)", fd);
        return;
    }

    ardillo_App_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_App_t, getThis());
    ardillo_stream_subscription_t *sub = ardillo_stream_subscriptions_find_by_fd(&this->stream_subscriptions, fd, 0);

    ardillo_stream_subscriptions_del(&this->stream_subscriptions, sub);
}

ZEND_METHOD(Ardillo_App, removeWriteStream)
{
    zend_long fd;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(fd)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_debug("Ardillo\\App::removeWriteStream() fd: %lld\n", fd);

    if (fd < 0) {
        zend_error(E_CORE_ERROR, "Ardillo\\App::removeWriteStream requires a valid stream (%lld < 0)", fd);
        return;
    }

    ardillo_App_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_App_t, getThis());
    ardillo_stream_subscription_t *sub = ardillo_stream_subscriptions_find_by_fd(&this->stream_subscriptions, fd, 1);

    ardillo_stream_subscriptions_del(&this->stream_subscriptions, sub);
}

int ardillo_App_onShouldQuit(void *data)
{
    ardillo_debug("App::onShouldQuit\n");

    int ret = 1;

    if (!ardillo_default_app) {
        ardillo_debug("App::onShouldQuit: no app found, exiting\n");
        return ret;
    }

    zval retval;
    ZVAL_LONG(&retval, 0);

    zend_string *method = zend_string_init("onShouldQuit", strlen("onShouldQuit"), 0);
    zend_object *this = &ardillo_default_app->std;

    int successful = zend_call_method_if_exists(this, method, &retval, 0, NULL);
    zend_string_release(method);

    if (successful == SUCCESS) {
        ret = Z_TYPE(retval) == IS_TRUE;
    } else {
        ret = 1;
    }

    zval_ptr_dtor(&retval);

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\App::onShouldQuit");
    }

    if (ret) {
        ardillo_App_stop(ardillo_default_app);

        return 0;
    }

    return ret;
}

void ardillo_App_onClicked(uiMenuItem *sender, uiWindow *window, void *senderData)
{
    if (!ardillo_default_app) {
        return;
    }

    zval retval;
    zval params[1];
    zend_string *method = zend_string_init("onMenuItemClicked", strlen("onMenuItemClicked"), 0);
    zend_object *this = &ardillo_default_app->std;

    ZVAL_LONG(&params[0], (zend_long)senderData);
    int successful = zend_call_method_if_exists(this, method, &retval, 1, params);
    zend_string_release(method);
    zval_ptr_dtor(&retval);

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\App::onMenuItemClicked");
    }
}

void ardillo_App_onSignal(int signo)
{
    if (!ardillo_default_app) {
        return;
    }

    zval retval;
    zval params[1];
    zend_string *method = zend_string_init("onSignal", strlen("onSignal"), 0);
    zend_object *this = &ardillo_default_app->std;

    ZVAL_LONG(&params[0], (zend_long)signo);
    int successful = zend_call_method_if_exists(this, method, &retval, 1, params);
    zend_string_release(method);
    zval_ptr_dtor(&retval);

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\App::onSignal");
    }
}

ZEND_METHOD(Ardillo_App, addSignal)
{
    zend_long signo;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(signo)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_debug("Ardillo\\App::addSignal() signal number: %lld\n", signo);

    if (signo < 0) {
        zend_error(E_CORE_ERROR, "Ardillo\\App::addSignal requires a valid signal number (%lld < 0)", signo);
        return;
    }

    zend_signal(signo, ardillo_App_onSignal);
}

ZEND_METHOD(Ardillo_App, removeSignal)
{
    zend_long signo;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(signo)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_debug("Ardillo\\App::removeSignal() signal number: %lld\n", signo);

    if (signo < 0) {
        zend_error(E_CORE_ERROR, "Ardillo\\App::removeSignal requires a valid signal number (%lld < 0)", signo);
        return;
    }

    zend_signal(signo, SIG_DFL);
}
