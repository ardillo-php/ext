#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

void ardillo_call_Slider_onChanged(uiSlider *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onChanged", strlen("onChanged"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_Slider_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);
    
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Slider::onChanged");
        return;
    }

    return;
}

void ardillo_call_Slider_onReleased(uiSlider *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onReleased", strlen("onReleased"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_Slider_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);
    
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Slider::onReleased");
        return;
    }

    return;
}


zend_object_handlers Slider_object_handlers;

zend_object* ardillo_create_Slider_object(zend_class_entry *ce)
{
    ardillo_ui_Slider_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Slider_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Slider_object_handlers, zend_get_std_object_handlers(), sizeof(Slider_object_handlers));
    Slider_object_handlers.offset = XtOffsetOf(ardillo_ui_Slider_t, std);
    Slider_object_handlers.free_obj = ardillo_free_Slider_object;
    ardillo_s->std.handlers = &Slider_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Slider @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Slider_object(zend_object *object)
{
    ardillo_ui_Slider_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Slider_t, object);

    ardillo_debug_objects(0, "Freeing Slider @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native Slider @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }
    
    ardillo_debug_objects(0, "Refcount for Slider @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Slider @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Slider, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Slider_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Slider_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Slider, __construct)
{
    zend_long min = 0;
    zend_long max = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(min)
        Z_PARAM_LONG(max)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Slider_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Slider_t, getThis());
    this->uis = uiNewSlider((int)min, (int)max);
    ardillo_debug_objects(0, "Constructing Slider @%p (uis @ %p)\n", this, this->uis);
    uiSliderOnChanged(this->uis, ardillo_call_Slider_onChanged, this);
    uiSliderOnReleased(this->uis, ardillo_call_Slider_onReleased, this);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_Slider, getHasToolTip)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Slider_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Slider_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Slider::getHasToolTip on invalid object");
    }
    
    int ret = uiSliderHasToolTip(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Slider, setHasToolTip)
{
    zend_long hasToolTip = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(hasToolTip)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Slider_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Slider_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Slider::setHasToolTip on invalid object");
    }
    
    uiSliderSetHasToolTip(this->uis, (int)hasToolTip);
}

ZEND_METHOD(Ardillo_Slider, getValue)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Slider_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Slider_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Slider::getValue on invalid object");
    }
    
    int ret = uiSliderValue(this->uis);

    RETURN_LONG(ret);
}

ZEND_METHOD(Ardillo_Slider, setValue)
{
    zend_long value = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(value)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Slider_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Slider_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Slider::setValue on invalid object");
    }
    
    uiSliderSetValue(this->uis, (int)value);
}

ZEND_METHOD(Ardillo_Slider, onChanged)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}

ZEND_METHOD(Ardillo_Slider, onReleased)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}

ZEND_METHOD(Ardillo_Slider, setRange)
{
    zend_long min = 0;
    zend_long max = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(min)
        Z_PARAM_LONG(max)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Slider_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Slider_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Slider::setRange on invalid object");
    }
    
    uiSliderSetRange(this->uis, (int)min, (int)max);
}


