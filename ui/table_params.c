#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers TableParams_object_handlers;

zend_object* ardillo_create_TableParams_object(zend_class_entry *ce)
{
    ardillo_ui_TableParams_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_TableParams_t) + zend_object_properties_size(ce));
    ardillo_s->uis = (uiTableParams *)ecalloc(1, sizeof(uiTableParams));

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&TableParams_object_handlers, zend_get_std_object_handlers(), sizeof(TableParams_object_handlers));
    TableParams_object_handlers.offset = XtOffsetOf(ardillo_ui_TableParams_t, std);
    TableParams_object_handlers.free_obj = ardillo_free_TableParams_object;
    ardillo_s->std.handlers = &TableParams_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created TableParams @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_TableParams_object(zend_object *object)
{
    ardillo_ui_TableParams_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_TableParams_t, object);

    ardillo_debug_objects(0, "Freeing TableParams @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));
    
    ardillo_debug_objects(0, "Refcount for TableParams @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    if (ardillo_s->uis) {
        efree(ardillo_s->uis);
        ardillo_s->uis = NULL;
    }

    ardillo_debug_objects(0, "Done freeing TableParams @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_TableParams, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_TableParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableParams_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_TableParams, getModel)
{
    
    ardillo_ui_TableParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableParams_t, getThis());
    ardillo_ui_TableModel_t *obj = (ardillo_ui_TableModel_t *)this->uis->Model;
    zval ret;
    ZVAL_OBJ(&ret, &obj->std);
    RETVAL_ZVAL(&ret, 0, 0);
    zval_ptr_dtor(&ret);
}

ZEND_METHOD(Ardillo_TableParams, setModel)
{
    zval *model = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(model, ce_Ardillo_TableModel)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_TableParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableParams_t, getThis());
    this->uis->Model = ARDILLO_ZVAL_GET_UIS(ardillo_ui_TableModel_t, model);
}

ZEND_METHOD(Ardillo_TableParams, getRowBackgroundColorModelColumn)
{
    
    ardillo_ui_TableParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableParams_t, getThis());
    RETURN_LONG((zend_long)this->uis->RowBackgroundColorModelColumn);
}

ZEND_METHOD(Ardillo_TableParams, setRowBackgroundColorModelColumn)
{
    zend_long rowBackgroundColorModelColumn = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(rowBackgroundColorModelColumn)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_TableParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableParams_t, getThis());
    this->uis->RowBackgroundColorModelColumn = rowBackgroundColorModelColumn;
}


