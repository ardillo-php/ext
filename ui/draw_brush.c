#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers DrawBrush_object_handlers;

zend_object* ardillo_create_DrawBrush_object(zend_class_entry *ce)
{
    ardillo_ui_DrawBrush_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_DrawBrush_t) + zend_object_properties_size(ce));
    ardillo_s->uis = (uiDrawBrush *)ecalloc(1, sizeof(uiDrawBrush));

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&DrawBrush_object_handlers, zend_get_std_object_handlers(), sizeof(DrawBrush_object_handlers));
    DrawBrush_object_handlers.offset = XtOffsetOf(ardillo_ui_DrawBrush_t, std);
    DrawBrush_object_handlers.free_obj = ardillo_free_DrawBrush_object;
    ardillo_s->std.handlers = &DrawBrush_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created DrawBrush @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_DrawBrush_object(zend_object *object)
{
    ardillo_ui_DrawBrush_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_DrawBrush_t, object);

    ardillo_debug_objects(0, "Freeing DrawBrush @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));
    
    ardillo_debug_objects(0, "Refcount for DrawBrush @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    if (ardillo_s->uis) {
        efree(ardillo_s->uis);
        ardillo_s->uis = NULL;
    }

    ardillo_debug_objects(0, "Done freeing DrawBrush @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_DrawBrush, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_DrawBrush, getType)
{
    
    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    RETURN_LONG((zend_long)this->uis->Type);
}

ZEND_METHOD(Ardillo_DrawBrush, setType)
{
    zend_long type = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(type)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    this->uis->Type = type;
}

ZEND_METHOD(Ardillo_DrawBrush, getColor)
{
    
    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    zval color;
    object_init_ex(&color, ce_Ardillo_Color);
    zend_update_property_double(ce_Ardillo_Size, Z_OBJ(color), "red", sizeof("red") - 1, this->uis->R);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "green", sizeof("green") - 1, this->uis->G);
    zend_update_property_double(ce_Ardillo_Size, Z_OBJ(color), "blue", sizeof("blue") - 1, this->uis->B);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "alpha", sizeof("alpha") - 1, this->uis->A);
    RETVAL_ZVAL(&color, 0, 0);
}

ZEND_METHOD(Ardillo_DrawBrush, setColor)
{
    zval *color;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(color, ce_Ardillo_Color)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    zval color_rv;
    this->uis->R = Z_DVAL_P(zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "red", sizeof("red") - 1, 0, &color_rv));
    this->uis->G = Z_DVAL_P(zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "green", sizeof("green") - 1, 0, &color_rv));
    this->uis->B = Z_DVAL_P(zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "blue", sizeof("blue") - 1, 0, &color_rv));
    this->uis->A = Z_DVAL_P(zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "alpha", sizeof("alpha") - 1, 0, &color_rv));
}

ZEND_METHOD(Ardillo_DrawBrush, getPoint0)
{
    
    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    zval point;
    object_init_ex(&point, ce_Ardillo_Point);
    zend_update_property_double(ce_Ardillo_Point, Z_OBJ(point), "x", sizeof("x") - 1, this->uis->X0);
    zend_update_property_double(ce_Ardillo_Point, Z_OBJ(point), "y", sizeof("y") - 1, this->uis->Y0);
    RETVAL_ZVAL(&point, 0, 0);
}

ZEND_METHOD(Ardillo_DrawBrush, setPoint0)
{
    zval *point;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(point, ce_Ardillo_Point)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    zval *point_x, *point_y, point_rv;
    this->uis->X0 = Z_DVAL_P(zend_read_property(ce_Ardillo_Point, Z_OBJ_P(point), "x", sizeof("x") - 1, 0, &point_rv));
    ZVAL_DEREF(point_x);
    this->uis->Y0 = Z_DVAL_P(zend_read_property(ce_Ardillo_Point, Z_OBJ_P(point), "y", sizeof("y") - 1, 0, &point_rv));
    ZVAL_DEREF(point_y);
}

ZEND_METHOD(Ardillo_DrawBrush, getPoint1)
{
    
    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    zval point;
    object_init_ex(&point, ce_Ardillo_Point);
    zend_update_property_double(ce_Ardillo_Point, Z_OBJ(point), "x", sizeof("x") - 1, this->uis->X1);
    zend_update_property_double(ce_Ardillo_Point, Z_OBJ(point), "y", sizeof("y") - 1, this->uis->Y1);
    RETVAL_ZVAL(&point, 0, 0);
}

ZEND_METHOD(Ardillo_DrawBrush, setPoint1)
{
    zval *point;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(point, ce_Ardillo_Point)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    zval *point_x, *point_y, point_rv;
    this->uis->X1 = Z_DVAL_P(zend_read_property(ce_Ardillo_Point, Z_OBJ_P(point), "x", sizeof("x") - 1, 0, &point_rv));
    ZVAL_DEREF(point_x);
    this->uis->Y1 = Z_DVAL_P(zend_read_property(ce_Ardillo_Point, Z_OBJ_P(point), "y", sizeof("y") - 1, 0, &point_rv));
    ZVAL_DEREF(point_y);
}

ZEND_METHOD(Ardillo_DrawBrush, getOuterRadius)
{
    
    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    RETURN_DOUBLE(this->uis->OuterRadius);
}

ZEND_METHOD(Ardillo_DrawBrush, setOuterRadius)
{
    double outerRadius = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(outerRadius)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    this->uis->OuterRadius = outerRadius;
}

ZEND_METHOD(Ardillo_DrawBrush, getStops)
{
    
    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    ardillo_ui_DrawBrushGradientStop_t *obj = (ardillo_ui_DrawBrushGradientStop_t *)this->uis->Stops;
    zval ret;
    ZVAL_OBJ(&ret, &obj->std);
    RETVAL_ZVAL(&ret, 0, 0);
    zval_ptr_dtor(&ret);
}

ZEND_METHOD(Ardillo_DrawBrush, setStops)
{
    zval *stops = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(stops, ce_Ardillo_DrawBrushGradientStop)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    this->uis->Stops = ARDILLO_ZVAL_GET_UIS(ardillo_ui_DrawBrushGradientStop_t, stops);
}

ZEND_METHOD(Ardillo_DrawBrush, getNumStops)
{
    
    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    RETURN_LONG((zend_long)this->uis->NumStops);
}

ZEND_METHOD(Ardillo_DrawBrush, setNumStops)
{
    zend_long numStops = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(numStops)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawBrush_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawBrush_t, getThis());
    this->uis->NumStops = numStops;
}


