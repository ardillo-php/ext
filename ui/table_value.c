#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers TableValue_object_handlers;

zend_object* ardillo_create_TableValue_object(zend_class_entry *ce)
{
    ardillo_ui_TableValue_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_TableValue_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&TableValue_object_handlers, zend_get_std_object_handlers(), sizeof(TableValue_object_handlers));
    TableValue_object_handlers.offset = XtOffsetOf(ardillo_ui_TableValue_t, std);
    TableValue_object_handlers.free_obj = ardillo_free_TableValue_object;
    ardillo_s->std.handlers = &TableValue_object_handlers;

    if (!ardillo_default_app) {
        zend_error(E_CORE_ERROR, "Cannot instantiate Ardillo\\TableValue outside of an Application context");
        return NULL;
    }


    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created TableValue @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_TableValue_object(zend_object *object)
{
    ardillo_ui_TableValue_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_TableValue_t, object);

    ardillo_debug_objects(0, "Freeing TableValue @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));
    
    ardillo_debug_objects(0, "Refcount for TableValue @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing TableValue @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_TableValue, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_TableValue_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableValue_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_TableValue, getType)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_TableValue_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableValue_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\TableValue::getType on invalid object");
    }
    
    int ret = uiTableValueGetType(this->uis);

    RETURN_LONG(ret);
}


