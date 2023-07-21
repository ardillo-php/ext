#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers AreaKeyEvent_object_handlers;

zend_object* ardillo_create_AreaKeyEvent_object(zend_class_entry *ce)
{
    ardillo_ui_AreaKeyEvent_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_AreaKeyEvent_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&AreaKeyEvent_object_handlers, zend_get_std_object_handlers(), sizeof(AreaKeyEvent_object_handlers));
    AreaKeyEvent_object_handlers.offset = XtOffsetOf(ardillo_ui_AreaKeyEvent_t, std);
    AreaKeyEvent_object_handlers.free_obj = ardillo_free_AreaKeyEvent_object;
    ardillo_s->std.handlers = &AreaKeyEvent_object_handlers;

    if (!ardillo_default_app) {
        zend_error(E_CORE_ERROR, "Cannot instantiate Ardillo\\AreaKeyEvent outside of an Application context");
        return NULL;
    }


    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created AreaKeyEvent @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_AreaKeyEvent_object(zend_object *object)
{
    ardillo_ui_AreaKeyEvent_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_AreaKeyEvent_t, object);

    ardillo_debug_objects(0, "Freeing AreaKeyEvent @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));
    
    ardillo_debug_objects(0, "Refcount for AreaKeyEvent @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing AreaKeyEvent @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_AreaKeyEvent, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_AreaKeyEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaKeyEvent_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_AreaKeyEvent, getKey)
{
    
    ardillo_ui_AreaKeyEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaKeyEvent_t, getThis());
    RETURN_LONG((zend_long)this->uis->Key);
}

ZEND_METHOD(Ardillo_AreaKeyEvent, getExtKey)
{
    
    ardillo_ui_AreaKeyEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaKeyEvent_t, getThis());
    RETURN_LONG((zend_long)this->uis->ExtKey);
}

ZEND_METHOD(Ardillo_AreaKeyEvent, getModifier)
{
    
    ardillo_ui_AreaKeyEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaKeyEvent_t, getThis());
    RETURN_LONG((zend_long)this->uis->Modifier);
}

ZEND_METHOD(Ardillo_AreaKeyEvent, getModifiers)
{
    
    ardillo_ui_AreaKeyEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaKeyEvent_t, getThis());
    RETURN_LONG((zend_long)this->uis->Modifiers);
}

ZEND_METHOD(Ardillo_AreaKeyEvent, getUp)
{
    
    ardillo_ui_AreaKeyEvent_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_AreaKeyEvent_t, getThis());
    RETURN_LONG((zend_long)this->uis->Up);
}


