#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers TableValueColor_object_handlers;

zend_object* ardillo_create_TableValueColor_object(zend_class_entry *ce)
{
    ardillo_ui_TableValueColor_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_TableValueColor_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&TableValueColor_object_handlers, zend_get_std_object_handlers(), sizeof(TableValueColor_object_handlers));
    TableValueColor_object_handlers.offset = XtOffsetOf(ardillo_ui_TableValueColor_t, std);
    TableValueColor_object_handlers.free_obj = ardillo_free_TableValueColor_object;
    ardillo_s->std.handlers = &TableValueColor_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created TableValueColor @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_TableValueColor_object(zend_object *object)
{
    ardillo_ui_TableValueColor_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_TableValueColor_t, object);

    ardillo_debug_objects(0, "Freeing TableValueColor @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Refcount for TableValueColor @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing TableValueColor @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_TableValueColor, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_TableValueColor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableValueColor_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_TableValueColor, __construct)
{
    zval *color = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(color, ce_Ardillo_Color)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_TableValueColor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableValueColor_t, getThis());

    zval *color_r, *color_g, *color_b, *color_a, rv;
    color_r = zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "red", sizeof("red") - 1, 0, &rv);
    ZVAL_DEREF(color_r);
    color_g = zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "green", sizeof("green") - 1, 0, &rv);
    ZVAL_DEREF(color_g);
    color_b = zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "blue", sizeof("blue") - 1, 0, &rv);
    ZVAL_DEREF(color_b);
    color_a = zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "alpha", sizeof("alpha") - 1, 0, &rv);
    ZVAL_DEREF(color_a);

    this->uis = uiNewTableValueColor(zval_get_double(color_r), zval_get_double(color_g), zval_get_double(color_b), zval_get_double(color_a));
    ardillo_debug_objects(0, "Constructing TableValueColor @%p (uis @ %p)\n", this, this->uis);
}

ZEND_METHOD(Ardillo_TableValueColor, get)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_TableValueColor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableValueColor_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\TableValueColor::get on invalid object");
    }

    double r = 0.0, g = 0.0,  b = 0.0, a = 0.0;

    uiTableValueColor(this->uis, &r, &g, &b, &a);

    zval color;
    object_init_ex(&color, ce_Ardillo_Color);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "red", sizeof("red") - 1, r);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "green", sizeof("green") - 1, g);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "blue", sizeof("blue") - 1, b);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "alpha", sizeof("alpha") - 1, a);
    RETVAL_ZVAL(&color, 0, 0);
}
