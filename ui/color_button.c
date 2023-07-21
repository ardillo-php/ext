#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

void ardillo_call_ColorButton_onChanged(uiColorButton *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onChanged", strlen("onChanged"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_ColorButton_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);
    
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\ColorButton::onChanged");
        return;
    }

    return;
}


zend_object_handlers ColorButton_object_handlers;

zend_object* ardillo_create_ColorButton_object(zend_class_entry *ce)
{
    ardillo_ui_ColorButton_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_ColorButton_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&ColorButton_object_handlers, zend_get_std_object_handlers(), sizeof(ColorButton_object_handlers));
    ColorButton_object_handlers.offset = XtOffsetOf(ardillo_ui_ColorButton_t, std);
    ColorButton_object_handlers.free_obj = ardillo_free_ColorButton_object;
    ardillo_s->std.handlers = &ColorButton_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created ColorButton @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_ColorButton_object(zend_object *object)
{
    ardillo_ui_ColorButton_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_ColorButton_t, object);

    ardillo_debug_objects(0, "Freeing ColorButton @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native ColorButton @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }
    
    ardillo_debug_objects(0, "Refcount for ColorButton @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing ColorButton @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_ColorButton, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_ColorButton_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_ColorButton_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_ColorButton, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_ColorButton_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_ColorButton_t, getThis());
    this->uis = uiNewColorButton();
    ardillo_debug_objects(0, "Constructing ColorButton @%p (uis @ %p)\n", this, this->uis);
    uiColorButtonOnChanged(this->uis, ardillo_call_ColorButton_onChanged, this);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_ColorButton, getColor)
{
    double color_r = 0.0, color_g = 0.0, color_b = 0.0, color_a = 0.0;

    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_ColorButton_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_ColorButton_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\ColorButton::getColor on invalid object");
    }
    
    uiColorButtonColor(this->uis, &color_r, &color_g, &color_b, &color_a);

    zval color;
    object_init_ex(&color, ce_Ardillo_Color);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "red", sizeof("red") - 1, color_r);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "green", sizeof("green") - 1, color_g);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "blue", sizeof("blue") - 1, color_b);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "alpha", sizeof("alpha") - 1, color_a);
    RETVAL_ZVAL(&color, 0, 0);
}

ZEND_METHOD(Ardillo_ColorButton, setColor)
{
    zval *color = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(color, ce_Ardillo_Color)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_ColorButton_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_ColorButton_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\ColorButton::setColor on invalid object");
    }
    
    zval *color_r, *color_g, *color_b, *color_a, rv;
    color_r = zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "red", sizeof("red") - 1, 0, &rv);
    ZVAL_DEREF(color_r);
    color_g = zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "green", sizeof("green") - 1, 0, &rv);
    ZVAL_DEREF(color_g);
    color_b = zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "blue", sizeof("blue") - 1, 0, &rv);
    ZVAL_DEREF(color_b);
    color_a = zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "alpha", sizeof("alpha") - 1, 0, &rv);
    ZVAL_DEREF(color_a);

    uiColorButtonSetColor(this->uis, zval_get_double(color_r), zval_get_double(color_g), zval_get_double(color_b), zval_get_double(color_a));
}

ZEND_METHOD(Ardillo_ColorButton, onChanged)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}


