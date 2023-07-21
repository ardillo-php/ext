#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers Control_object_handlers;

zend_object* ardillo_create_Control_object(zend_class_entry *ce)
{
    ardillo_ui_Control_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Control_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Control_object_handlers, zend_get_std_object_handlers(), sizeof(Control_object_handlers));
    Control_object_handlers.offset = XtOffsetOf(ardillo_ui_Control_t, std);
    Control_object_handlers.free_obj = ardillo_free_Control_object;
    ardillo_s->std.handlers = &Control_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Control @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Control_object(zend_object *object)
{
    ardillo_ui_Control_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Control_t, object);

    ardillo_debug_objects(0, "Freeing Control @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native Control @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }
    
    ardillo_debug_objects(0, "Refcount for Control @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Control @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Control, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Control_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Control_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Control, disable)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Control_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Control_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Control::disable on invalid object");
    }
    
    uiControlDisable(this->uis);
}

ZEND_METHOD(Ardillo_Control, enable)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Control_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Control_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Control::enable on invalid object");
    }
    
    uiControlEnable(this->uis);
}

ZEND_METHOD(Ardillo_Control, isEnabled)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Control_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Control_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Control::enabled on invalid object");
    }
    
    int ret = uiControlEnabled(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Control, isEnabledToUser)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Control_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Control_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Control::enabledToUser on invalid object");
    }
    
    int ret = uiControlEnabledToUser(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Control, hide)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Control_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Control_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Control::hide on invalid object");
    }
    
    uiControlHide(this->uis);
}

ZEND_METHOD(Ardillo_Control, show)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Control_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Control_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Control::show on invalid object");
    }
    
    uiControlShow(this->uis);
}

ZEND_METHOD(Ardillo_Control, isTopLevel)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Control_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Control_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Control::toplevel on invalid object");
    }
    
    int ret = uiControlToplevel(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Control, isVisible)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Control_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Control_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Control::visible on invalid object");
    }
    
    int ret = uiControlVisible(this->uis);

    RETURN_BOOL(ret);
}


void ardillo_call_Control_onFree(uiControl *uis, void *this)
{
    ((ardillo_ui_Control_t *)this)->uis = NULL;
}
