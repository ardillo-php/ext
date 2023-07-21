#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers DrawPath_object_handlers;

zend_object* ardillo_create_DrawPath_object(zend_class_entry *ce)
{
    ardillo_ui_DrawPath_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_DrawPath_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&DrawPath_object_handlers, zend_get_std_object_handlers(), sizeof(DrawPath_object_handlers));
    DrawPath_object_handlers.offset = XtOffsetOf(ardillo_ui_DrawPath_t, std);
    DrawPath_object_handlers.free_obj = ardillo_free_DrawPath_object;
    ardillo_s->std.handlers = &DrawPath_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created DrawPath @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_DrawPath_object(zend_object *object)
{
    ardillo_ui_DrawPath_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_DrawPath_t, object);

    ardillo_debug_objects(0, "Freeing DrawPath @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Freeing native DrawPath @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
    uiDrawFreePath(ardillo_s->uis);
    
    ardillo_debug_objects(0, "Refcount for DrawPath @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing DrawPath @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_DrawPath, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_DrawPath_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawPath_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_DrawPath, __construct)
{
    zend_long fillMode = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(fillMode)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawPath_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawPath_t, getThis());
    this->uis = uiDrawNewPath((int)fillMode);
    ardillo_debug_objects(0, "Constructing DrawPath @%p (uis @ %p)\n", this, this->uis);
}

ZEND_METHOD(Ardillo_DrawPath, addRectangle)
{
    zval *pt = NULL;
    zval *size = NULL;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_OBJECT_OF_CLASS(pt, ce_Ardillo_Point)
        Z_PARAM_OBJECT_OF_CLASS(size, ce_Ardillo_Size)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawPath_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawPath_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\DrawPath::addRectangle on invalid object");
    }
    
    zval *pt_x, *pt_y, pt_rv;
    pt_x = zend_read_property(ce_Ardillo_Point, Z_OBJ_P(pt), "x", sizeof("x") - 1, 0, &pt_rv);
    ZVAL_DEREF(pt_x);
    pt_y = zend_read_property(ce_Ardillo_Point, Z_OBJ_P(pt), "y", sizeof("y") - 1, 0, &pt_rv);
    ZVAL_DEREF(pt_y);
    zval *size_width, *size_height, size_rv;
    size_width = zend_read_property(ce_Ardillo_Size, Z_OBJ_P(size), "width", sizeof("width") - 1, 0, &size_rv);
    ZVAL_DEREF(size_width);
    size_height = zend_read_property(ce_Ardillo_Size, Z_OBJ_P(size), "height", sizeof("height") - 1, 0, &size_rv);
    ZVAL_DEREF(size_height);

    uiDrawPathAddRectangle(this->uis, zval_get_double(pt_x), zval_get_double(pt_y), zval_get_double(size_width), zval_get_double(size_height));
}

ZEND_METHOD(Ardillo_DrawPath, newFigure)
{
    double x = 0.0;
    double y = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawPath_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawPath_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\DrawPath::newFigure on invalid object");
    }
    
    uiDrawPathNewFigure(this->uis, x, y);
}

ZEND_METHOD(Ardillo_DrawPath, closeFigure)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_DrawPath_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawPath_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\DrawPath::closeFigure on invalid object");
    }
    
    uiDrawPathCloseFigure(this->uis);
}

ZEND_METHOD(Ardillo_DrawPath, lineTo)
{
    double x = 0.0;
    double y = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawPath_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawPath_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\DrawPath::lineTo on invalid object");
    }
    
    uiDrawPathLineTo(this->uis, x, y);
}

ZEND_METHOD(Ardillo_DrawPath, end)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_DrawPath_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawPath_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\DrawPath::end on invalid object");
    }
    
    uiDrawPathEnd(this->uis);
}


