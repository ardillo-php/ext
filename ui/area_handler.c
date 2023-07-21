#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

void ardillo_call_AreaHandler_dragBrokenHandler(uiAreaHandler *uis, uiArea *area)
{
    ardillo_ui_AreaHandler_t *this = (ardillo_ui_AreaHandler_t *)(uis->userData);
    zval args[1];
    zval retval;
    ZVAL_OBJ(&args[0], &((ardillo_ui_Area_t *)uiAreaGetUserData(area))->std);
    zend_string *method = zend_string_init("dragBrokenHandler", strlen("dragBrokenHandler"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_AreaHandler_t *)this)->std, method, &retval, 1, args);
    zend_string_release(method);

    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        zval_ptr_dtor(&args[0]);
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\AreaHandler::dragBrokenHandler");
        zval_ptr_dtor(&args[0]);
        return;
    }

    return;
}

void ardillo_call_AreaHandler_drawHandler(uiAreaHandler *uis, uiArea *area, uiAreaDrawParams *params)
{
    ardillo_ui_AreaHandler_t *this = (ardillo_ui_AreaHandler_t *)(uis->userData);
    zval args[2];
    zval retval;
    ZVAL_OBJ(&args[0], &((ardillo_ui_Area_t *)uiAreaGetUserData(area))->std);

    if (params) {
        zend_object *params_obj = ardillo_create_AreaDrawParams_object(ce_Ardillo_AreaDrawParams);
        ardillo_ui_AreaDrawParams_t *params_wrapped = ARDILLO_GET_OBJECT(ardillo_ui_AreaDrawParams_t, params_obj);
        params_wrapped->uis = (uiAreaDrawParams *)params;
        ZVAL_OBJ(&args[1], params_obj);
    } else {
        ZVAL_NULL(&args[1]);
    }

    zend_string *method = zend_string_init("drawHandler", strlen("drawHandler"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_AreaHandler_t *)this)->std, method, &retval, 2, args);
    zend_string_release(method);

    zval_ptr_dtor(&retval);
    zval_ptr_dtor(&args[1]);

    if (successful != SUCCESS) {
        zval_ptr_dtor(&args[0]);
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\AreaHandler::drawHandler");
        zval_ptr_dtor(&args[0]);
        return;
    }

    return;
}

int ardillo_call_AreaHandler_keyEventHandler(uiAreaHandler *uis, uiArea *area, uiAreaKeyEvent *event)
{
    ardillo_ui_AreaHandler_t *this = (ardillo_ui_AreaHandler_t *)(uis->userData);
    zval args[2];
    zval retval;
    ZVAL_OBJ(&args[0], &((ardillo_ui_Area_t *)uiAreaGetUserData(area))->std);

    if (event) {
        zend_object *event_obj = ardillo_create_AreaKeyEvent_object(ce_Ardillo_AreaKeyEvent);
        ardillo_ui_AreaKeyEvent_t *event_wrapped = ARDILLO_GET_OBJECT(ardillo_ui_AreaKeyEvent_t, event_obj);
        event_wrapped->uis = (uiAreaKeyEvent *)event;
        ZVAL_OBJ(&args[1], event_obj);
    } else {
        ZVAL_NULL(&args[1]);
    }

    zend_string *method = zend_string_init("keyEventHandler", strlen("keyEventHandler"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_AreaHandler_t *)this)->std, method, &retval, 2, args);
    zend_string_release(method);
    int ret = Z_LVAL(retval);
    zval_ptr_dtor(&retval);
    zval_ptr_dtor(&args[1]);

    if (successful != SUCCESS) {
        zval_ptr_dtor(&args[0]);
        return 0;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\AreaHandler::keyEventHandler");
        zval_ptr_dtor(&args[0]);
        return 0;
    }

    return ret;
}

void ardillo_call_AreaHandler_mouseCrossedHandler(uiAreaHandler *uis, uiArea *area, int left)
{
    ardillo_ui_AreaHandler_t *this = (ardillo_ui_AreaHandler_t *)(uis->userData);
    zval args[2];
    zval retval;
    ZVAL_OBJ(&args[0], &((ardillo_ui_Area_t *)uiAreaGetUserData(area))->std);
    ZVAL_LONG(&args[1], (zend_long)left);
    zend_string *method = zend_string_init("mouseCrossedHandler", strlen("mouseCrossedHandler"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_AreaHandler_t *)this)->std, method, &retval, 2, args);
    zend_string_release(method);

    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        zval_ptr_dtor(&args[0]);
        zval_ptr_dtor(&args[1]);
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\AreaHandler::mouseCrossedHandler");
        zval_ptr_dtor(&args[0]);
        zval_ptr_dtor(&args[1]);
        return;
    }

    return;
}

void ardillo_call_AreaHandler_mouseEventHandler(uiAreaHandler *uis, uiArea *area, uiAreaMouseEvent *event)
{
    ardillo_ui_AreaHandler_t *this = (ardillo_ui_AreaHandler_t *)(uis->userData);
    zval args[2];
    zval retval;
    ZVAL_OBJ(&args[0], &((ardillo_ui_Area_t *)uiAreaGetUserData(area))->std);

    if (event) {
        zend_object *event_obj = ardillo_create_AreaMouseEvent_object(ce_Ardillo_AreaMouseEvent);
        ardillo_ui_AreaMouseEvent_t *event_wrapped = ARDILLO_GET_OBJECT(ardillo_ui_AreaMouseEvent_t, event_obj);
        event_wrapped->uis = (uiAreaMouseEvent *)event;
        ZVAL_OBJ(&args[1], event_obj);
    } else {
        ZVAL_NULL(&args[1]);
    }

    zend_string *method = zend_string_init("mouseEventHandler", strlen("mouseEventHandler"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_AreaHandler_t *)this)->std, method, &retval, 2, args);
    zend_string_release(method);

    zval_ptr_dtor(&retval);
    zval_ptr_dtor(&args[1]);

    if (successful != SUCCESS) {
        zval_ptr_dtor(&args[0]);
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\AreaHandler::mouseEventHandler");
        zval_ptr_dtor(&args[0]);
        return;
    }

    return;
}

zend_object_handlers AreaHandler_object_handlers;

zend_object* ardillo_create_AreaHandler_object(zend_class_entry *ce)
{
    ardillo_ui_AreaHandler_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_AreaHandler_t) + zend_object_properties_size(ce));
    ardillo_s->uis = (uiAreaHandler *)ecalloc(1, sizeof(uiAreaHandler));
    ardillo_s->uis->DragBroken = ardillo_call_AreaHandler_dragBrokenHandler;
    ardillo_s->uis->Draw = ardillo_call_AreaHandler_drawHandler;
    ardillo_s->uis->KeyEvent = ardillo_call_AreaHandler_keyEventHandler;
    ardillo_s->uis->MouseCrossed = ardillo_call_AreaHandler_mouseCrossedHandler;
    ardillo_s->uis->MouseEvent = ardillo_call_AreaHandler_mouseEventHandler;
    ardillo_s->uis->userData = ardillo_s;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&AreaHandler_object_handlers, zend_get_std_object_handlers(), sizeof(AreaHandler_object_handlers));
    AreaHandler_object_handlers.offset = XtOffsetOf(ardillo_ui_AreaHandler_t, std);
    AreaHandler_object_handlers.free_obj = ardillo_free_AreaHandler_object;
    ardillo_s->std.handlers = &AreaHandler_object_handlers;

    if (!ardillo_default_app) {
        zend_error(E_CORE_ERROR, "Cannot instantiate Ardillo\\AreaHandler outside of an Application context");
        return NULL;
    }

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created AreaHandler @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_AreaHandler_object(zend_object *object)
{
    ardillo_ui_AreaHandler_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_AreaHandler_t, object);

    ardillo_debug_objects(0, "Freeing AreaHandler @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Refcount for AreaHandler @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    if (ardillo_s->uis) {
        efree(ardillo_s->uis);
        ardillo_s->uis = NULL;
    }

    ardillo_debug_objects(0, "Done freeing AreaHandler @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_AreaHandler, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_AreaHandler_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaHandler_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}
