#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers AreaMouseEvent_object_handlers;

zend_object* ardillo_create_AreaMouseEvent_object(zend_class_entry *ce)
{
    ardillo_ui_AreaMouseEvent_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_AreaMouseEvent_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&AreaMouseEvent_object_handlers, zend_get_std_object_handlers(), sizeof(AreaMouseEvent_object_handlers));
    AreaMouseEvent_object_handlers.offset = XtOffsetOf(ardillo_ui_AreaMouseEvent_t, std);
    AreaMouseEvent_object_handlers.free_obj = ardillo_free_AreaMouseEvent_object;
    ardillo_s->std.handlers = &AreaMouseEvent_object_handlers;

    if (!ardillo_default_app) {
        zend_error(E_CORE_ERROR, "Cannot instantiate Ardillo\\AreaMouseEvent outside of an Application context");
        return NULL;
    }

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created AreaMouseEvent @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_AreaMouseEvent_object(zend_object *object)
{
    ardillo_ui_AreaMouseEvent_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_AreaMouseEvent_t, object);

    ardillo_debug_objects(0, "Freeing AreaMouseEvent @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Refcount for AreaMouseEvent @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing AreaMouseEvent @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_AreaMouseEvent, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_AreaMouseEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaMouseEvent_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_AreaMouseEvent, getPoint)
{

    ardillo_ui_AreaMouseEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaMouseEvent_t, getThis());
    zval point;
    object_init_ex(&point, ce_Ardillo_Point);
    zend_update_property_double(ce_Ardillo_Point, Z_OBJ(point), "x", sizeof("x") - 1, this->uis->X);
    zend_update_property_double(ce_Ardillo_Point, Z_OBJ(point), "y", sizeof("y") - 1, this->uis->Y);
    RETVAL_ZVAL(&point, 0, 0);
}

ZEND_METHOD(Ardillo_AreaMouseEvent, getAreaSize)
{

    ardillo_ui_AreaMouseEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaMouseEvent_t, getThis());
    zval area;
    object_init_ex(&area, ce_Ardillo_Size);
    zend_update_property_double(ce_Ardillo_Size, Z_OBJ(area), "width", sizeof("width") - 1, this->uis->AreaWidth);
    zend_update_property_double(ce_Ardillo_Size, Z_OBJ(area), "height", sizeof("height") - 1, this->uis->AreaHeight);
    RETVAL_ZVAL(&area, 0, 0);
}

ZEND_METHOD(Ardillo_AreaMouseEvent, getDown)
{

    ardillo_ui_AreaMouseEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaMouseEvent_t, getThis());
    RETURN_LONG((zend_long)this->uis->Down);
}

ZEND_METHOD(Ardillo_AreaMouseEvent, getUp)
{

    ardillo_ui_AreaMouseEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaMouseEvent_t, getThis());
    RETURN_LONG((zend_long)this->uis->Up);
}

ZEND_METHOD(Ardillo_AreaMouseEvent, getCount)
{

    ardillo_ui_AreaMouseEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaMouseEvent_t, getThis());
    RETURN_LONG((zend_long)this->uis->Count);
}

ZEND_METHOD(Ardillo_AreaMouseEvent, getModifiers)
{

    ardillo_ui_AreaMouseEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaMouseEvent_t, getThis());
    RETURN_LONG((zend_long)this->uis->Modifiers);
}

ZEND_METHOD(Ardillo_AreaMouseEvent, getHeld1To64)
{

    ardillo_ui_AreaMouseEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaMouseEvent_t, getThis());
    RETURN_LONG((zend_long)this->uis->Held1To64);
}
