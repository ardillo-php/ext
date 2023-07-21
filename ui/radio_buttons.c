#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

void ardillo_call_RadioButtons_onSelected(uiRadioButtons *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onSelected", strlen("onSelected"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_RadioButtons_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);
    
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\RadioButtons::onSelected");
        return;
    }

    return;
}


zend_object_handlers RadioButtons_object_handlers;

zend_object* ardillo_create_RadioButtons_object(zend_class_entry *ce)
{
    ardillo_ui_RadioButtons_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_RadioButtons_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&RadioButtons_object_handlers, zend_get_std_object_handlers(), sizeof(RadioButtons_object_handlers));
    RadioButtons_object_handlers.offset = XtOffsetOf(ardillo_ui_RadioButtons_t, std);
    RadioButtons_object_handlers.free_obj = ardillo_free_RadioButtons_object;
    ardillo_s->std.handlers = &RadioButtons_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created RadioButtons @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_RadioButtons_object(zend_object *object)
{
    ardillo_ui_RadioButtons_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_RadioButtons_t, object);

    ardillo_debug_objects(0, "Freeing RadioButtons @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native RadioButtons @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }
    
    ardillo_debug_objects(0, "Refcount for RadioButtons @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing RadioButtons @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_RadioButtons, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_RadioButtons_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_RadioButtons_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_RadioButtons, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_RadioButtons_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_RadioButtons_t, getThis());
    this->uis = uiNewRadioButtons();
    ardillo_debug_objects(0, "Constructing RadioButtons @%p (uis @ %p)\n", this, this->uis);
    uiRadioButtonsOnSelected(this->uis, ardillo_call_RadioButtons_onSelected, this);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_RadioButtons, getSelected)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_RadioButtons_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_RadioButtons_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\RadioButtons::getSelected on invalid object");
    }
    
    int ret = uiRadioButtonsSelected(this->uis);

    RETURN_LONG(ret);
}

ZEND_METHOD(Ardillo_RadioButtons, setSelected)
{
    zend_long index = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_RadioButtons_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_RadioButtons_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\RadioButtons::setSelected on invalid object");
    }
    
    uiRadioButtonsSetSelected(this->uis, (int)index);
}

ZEND_METHOD(Ardillo_RadioButtons, onSelected)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}

ZEND_METHOD(Ardillo_RadioButtons, append)
{
    zend_string *text = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_RadioButtons_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_RadioButtons_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\RadioButtons::append on invalid object");
    }
    
    uiRadioButtonsAppend(this->uis, ZSTR_VAL(text));
}


