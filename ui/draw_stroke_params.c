#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers DrawStrokeParams_object_handlers;

zend_object* ardillo_create_DrawStrokeParams_object(zend_class_entry *ce)
{
    ardillo_ui_DrawStrokeParams_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_DrawStrokeParams_t) + zend_object_properties_size(ce));
    ardillo_s->uis = (uiDrawStrokeParams *)ecalloc(1, sizeof(uiDrawStrokeParams));

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&DrawStrokeParams_object_handlers, zend_get_std_object_handlers(), sizeof(DrawStrokeParams_object_handlers));
    DrawStrokeParams_object_handlers.offset = XtOffsetOf(ardillo_ui_DrawStrokeParams_t, std);
    DrawStrokeParams_object_handlers.free_obj = ardillo_free_DrawStrokeParams_object;
    ardillo_s->std.handlers = &DrawStrokeParams_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created DrawStrokeParams @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_DrawStrokeParams_object(zend_object *object)
{
    ardillo_ui_DrawStrokeParams_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, object);

    ardillo_debug_objects(0, "Freeing DrawStrokeParams @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Refcount for DrawStrokeParams @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    if (ardillo_s->uis) {
        efree(ardillo_s->uis);
        ardillo_s->uis = NULL;
    }

    ardillo_debug_objects(0, "Done freeing DrawStrokeParams @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_DrawStrokeParams, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_DrawStrokeParams, getCap)
{

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    RETURN_LONG((zend_long)this->uis->Cap);
}

ZEND_METHOD(Ardillo_DrawStrokeParams, setCap)
{
    zend_long cap = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(cap)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    this->uis->Cap = cap;
}

ZEND_METHOD(Ardillo_DrawStrokeParams, getJoin)
{

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    RETURN_LONG((zend_long)this->uis->Join);
}

ZEND_METHOD(Ardillo_DrawStrokeParams, setJoin)
{
    zend_long join = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(join)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    this->uis->Join = join;
}

ZEND_METHOD(Ardillo_DrawStrokeParams, getThickness)
{

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    RETURN_DOUBLE(this->uis->Thickness);
}

ZEND_METHOD(Ardillo_DrawStrokeParams, setThickness)
{
    double thickness = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(thickness)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    this->uis->Thickness = thickness;
}

ZEND_METHOD(Ardillo_DrawStrokeParams, getMiterLimit)
{

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    RETURN_DOUBLE(this->uis->MiterLimit);
}

ZEND_METHOD(Ardillo_DrawStrokeParams, setMiterLimit)
{
    double miterLimit = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(miterLimit)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    this->uis->MiterLimit = miterLimit;
}

ZEND_METHOD(Ardillo_DrawStrokeParams, getDashes)
{

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    RETURN_DOUBLE(*(this->uis->Dashes));
}

ZEND_METHOD(Ardillo_DrawStrokeParams, setDashes)
{
    double dashes = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(dashes)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    *this->uis->Dashes = dashes;
}

ZEND_METHOD(Ardillo_DrawStrokeParams, getNumDashes)
{

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    RETURN_LONG((zend_long)this->uis->NumDashes);
}

ZEND_METHOD(Ardillo_DrawStrokeParams, setNumDashes)
{
    zend_long numDashes = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(numDashes)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    this->uis->NumDashes = numDashes;
}

ZEND_METHOD(Ardillo_DrawStrokeParams, getDashPhase)
{

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    RETURN_DOUBLE(this->uis->DashPhase);
}

ZEND_METHOD(Ardillo_DrawStrokeParams, setDashPhase)
{
    double dashPhase = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(dashPhase)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawStrokeParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawStrokeParams_t, getThis());
    this->uis->DashPhase = dashPhase;
}
