#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers AreaDrawParams_object_handlers;

zend_object* ardillo_create_AreaDrawParams_object(zend_class_entry *ce)
{
    ardillo_ui_AreaDrawParams_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_AreaDrawParams_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&AreaDrawParams_object_handlers, zend_get_std_object_handlers(), sizeof(AreaDrawParams_object_handlers));
    AreaDrawParams_object_handlers.offset = XtOffsetOf(ardillo_ui_AreaDrawParams_t, std);
    AreaDrawParams_object_handlers.free_obj = ardillo_free_AreaDrawParams_object;
    ardillo_s->std.handlers = &AreaDrawParams_object_handlers;

    if (!ardillo_default_app) {
        zend_error(E_CORE_ERROR, "Cannot instantiate Ardillo\\AreaDrawParams outside of an Application context");
        return NULL;
    }


    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created AreaDrawParams @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_AreaDrawParams_object(zend_object *object)
{
    ardillo_ui_AreaDrawParams_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_AreaDrawParams_t, object);

    ardillo_debug_objects(0, "Freeing AreaDrawParams @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));
    
    ardillo_debug_objects(0, "Refcount for AreaDrawParams @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing AreaDrawParams @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_AreaDrawParams, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_AreaDrawParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaDrawParams_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_AreaDrawParams, getAreaSize)
{
    
    ardillo_ui_AreaDrawParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaDrawParams_t, getThis());
    zval area;
    object_init_ex(&area, ce_Ardillo_Size);
    zend_update_property_double(ce_Ardillo_Size, Z_OBJ(area), "width", sizeof("width") - 1, this->uis->AreaWidth);
    zend_update_property_double(ce_Ardillo_Size, Z_OBJ(area), "height", sizeof("height") - 1, this->uis->AreaHeight);
    RETVAL_ZVAL(&area, 0, 0);
}

ZEND_METHOD(Ardillo_AreaDrawParams, getClipPoint)
{
    
    ardillo_ui_AreaDrawParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaDrawParams_t, getThis());
    zval clip;
    object_init_ex(&clip, ce_Ardillo_Point);
    zend_update_property_double(ce_Ardillo_Point, Z_OBJ(clip), "x", sizeof("x") - 1, this->uis->ClipX);
    zend_update_property_double(ce_Ardillo_Point, Z_OBJ(clip), "y", sizeof("y") - 1, this->uis->ClipY);
    RETVAL_ZVAL(&clip, 0, 0);
}

ZEND_METHOD(Ardillo_AreaDrawParams, getClipSize)
{
    
    ardillo_ui_AreaDrawParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaDrawParams_t, getThis());
    zval clip;
    object_init_ex(&clip, ce_Ardillo_Size);
    zend_update_property_double(ce_Ardillo_Size, Z_OBJ(clip), "width", sizeof("width") - 1, this->uis->ClipWidth);
    zend_update_property_double(ce_Ardillo_Size, Z_OBJ(clip), "height", sizeof("height") - 1, this->uis->ClipHeight);
    RETVAL_ZVAL(&clip, 0, 0);
}

ZEND_METHOD(Ardillo_AreaDrawParams, fill)
{
    zval *path = NULL;
    zval *brush = NULL;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_OBJECT_OF_CLASS(path, ce_Ardillo_DrawPath)
        Z_PARAM_OBJECT_OF_CLASS(brush, ce_Ardillo_DrawBrush)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_AreaDrawParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaDrawParams_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\AreaDrawParams::fill on invalid object");
    }
    
    uiDrawFill(this->uis->Context, ARDILLO_ZVAL_GET_UIS(ardillo_ui_DrawPath_t, path), ARDILLO_ZVAL_GET_UIS(ardillo_ui_DrawBrush_t, brush));
}

ZEND_METHOD(Ardillo_AreaDrawParams, stroke)
{
    zval *path = NULL;
    zval *brush = NULL;
    zval *sp = NULL;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_OBJECT_OF_CLASS(path, ce_Ardillo_DrawPath)
        Z_PARAM_OBJECT_OF_CLASS(brush, ce_Ardillo_DrawBrush)
        Z_PARAM_OBJECT_OF_CLASS(sp, ce_Ardillo_DrawStrokeParams)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_AreaDrawParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaDrawParams_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\AreaDrawParams::stroke on invalid object");
    }
    
    uiDrawStroke(this->uis->Context, ARDILLO_ZVAL_GET_UIS(ardillo_ui_DrawPath_t, path), ARDILLO_ZVAL_GET_UIS(ardillo_ui_DrawBrush_t, brush), ARDILLO_ZVAL_GET_UIS(ardillo_ui_DrawStrokeParams_t, sp));
}

ZEND_METHOD(Ardillo_AreaDrawParams, transform)
{
    zval *matrix = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(matrix, ce_Ardillo_DrawMatrix)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_AreaDrawParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaDrawParams_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\AreaDrawParams::transform on invalid object");
    }
    
    uiDrawTransform(this->uis->Context, ARDILLO_ZVAL_GET_UIS(ardillo_ui_DrawMatrix_t, matrix));
}


