#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers DrawBrushGradientStop_object_handlers;

zend_object* ardillo_create_DrawBrushGradientStop_object(zend_class_entry *ce)
{
    ardillo_ui_DrawBrushGradientStop_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_DrawBrushGradientStop_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&DrawBrushGradientStop_object_handlers, zend_get_std_object_handlers(), sizeof(DrawBrushGradientStop_object_handlers));
    DrawBrushGradientStop_object_handlers.offset = XtOffsetOf(ardillo_ui_DrawBrushGradientStop_t, std);
    DrawBrushGradientStop_object_handlers.free_obj = ardillo_free_DrawBrushGradientStop_object;
    ardillo_s->std.handlers = &DrawBrushGradientStop_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created DrawBrushGradientStop @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_DrawBrushGradientStop_object(zend_object *object)
{
    ardillo_ui_DrawBrushGradientStop_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_DrawBrushGradientStop_t, object);

    ardillo_debug_objects(0, "Freeing DrawBrushGradientStop @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Refcount for DrawBrushGradientStop @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing DrawBrushGradientStop @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_DrawBrushGradientStop, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_DrawBrushGradientStop_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrushGradientStop_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_DrawBrushGradientStop, getPos)
{

    ardillo_ui_DrawBrushGradientStop_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrushGradientStop_t, getThis());
    RETURN_DOUBLE(this->uis->Pos);
}

ZEND_METHOD(Ardillo_DrawBrushGradientStop, setPos)
{
    double pos = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(pos)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawBrushGradientStop_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrushGradientStop_t, getThis());
    this->uis->Pos = pos;
}

ZEND_METHOD(Ardillo_DrawBrushGradientStop, getColor)
{

    ardillo_ui_DrawBrushGradientStop_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrushGradientStop_t, getThis());
    zval color;
    object_init_ex(&color, ce_Ardillo_Color);
    zend_update_property_double(ce_Ardillo_Size, Z_OBJ(color), "red", sizeof("red") - 1, this->uis->R);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "green", sizeof("green") - 1, this->uis->G);
    zend_update_property_double(ce_Ardillo_Size, Z_OBJ(color), "blue", sizeof("blue") - 1, this->uis->B);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "alpha", sizeof("alpha") - 1, this->uis->A);
    RETVAL_ZVAL(&color, 0, 0);
}

ZEND_METHOD(Ardillo_DrawBrushGradientStop, setColor)
{
    zval *color;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(color, ce_Ardillo_Color)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawBrushGradientStop_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrushGradientStop_t, getThis());
    zval color_rv;
    this->uis->R = Z_DVAL_P(zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "red", sizeof("red") - 1, 0, &color_rv));
    this->uis->G = Z_DVAL_P(zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "green", sizeof("green") - 1, 0, &color_rv));
    this->uis->B = Z_DVAL_P(zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "blue", sizeof("blue") - 1, 0, &color_rv));
    this->uis->A = Z_DVAL_P(zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "alpha", sizeof("alpha") - 1, 0, &color_rv));
}
