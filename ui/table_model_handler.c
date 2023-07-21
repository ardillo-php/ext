#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

uiTableValue * ardillo_call_TableModelHandler_cellValueHandler(uiTableModelHandler *uis, uiTableModel *m, int row, int column)
{
    ardillo_ui_TableModelHandler_t *this = (ardillo_ui_TableModelHandler_t *)(uis->userData);
    zval args[3];
    zval retval;
    ZVAL_OBJ(&args[0], &((ardillo_ui_TableModel_t *)uiTableModelGetUserData(m))->std);
    ZVAL_LONG(&args[1], (zend_long)row);
    ZVAL_LONG(&args[2], (zend_long)column);
    zend_string *method = zend_string_init("cellValueHandler", strlen("cellValueHandler"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_TableModelHandler_t *)this)->std, method, &retval, 3, args);
    zend_string_release(method);

    if (Z_TYPE(retval) != IS_OBJECT) {
        zend_error(E_CORE_ERROR, "Ardillo\\TableModelHandler::cellValueHandler must return an object");
        return NULL;
    }

    uiTableValue *retuis = ARDILLO_ZVAL_GET_UIS(ardillo_ui_TableValue_t, &retval);
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        zval_ptr_dtor(&args[0]);
        zval_ptr_dtor(&args[1]);
        zval_ptr_dtor(&args[2]);
        return NULL;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\TableModelHandler::cellValueHandler");
        zval_ptr_dtor(&args[0]);
        zval_ptr_dtor(&args[1]);
        zval_ptr_dtor(&args[2]);
        return NULL;
    }

    return retuis;
}

uiTableValueType ardillo_call_TableModelHandler_columnTypeHandler(uiTableModelHandler *uis, uiTableModel *model, int column)
{
    ardillo_ui_TableModelHandler_t *this = (ardillo_ui_TableModelHandler_t *)(uis->userData);
    zval args[2];
    zval retval;
    ZVAL_OBJ(&args[0], &((ardillo_ui_TableModel_t *)uiTableModelGetUserData(model))->std);
    ZVAL_LONG(&args[1], (zend_long)column);
    zend_string *method = zend_string_init("columnTypeHandler", strlen("columnTypeHandler"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_TableModelHandler_t *)this)->std, method, &retval, 2, args);
    zend_string_release(method);
    int ret = Z_LVAL(retval);
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        zval_ptr_dtor(&args[0]);
        zval_ptr_dtor(&args[1]);
        return 0;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\TableModelHandler::columnTypeHandler");
        zval_ptr_dtor(&args[0]);
        zval_ptr_dtor(&args[1]);
        return 0;
    }

    return ret;
}

int ardillo_call_TableModelHandler_numColumnsHandler(uiTableModelHandler *uis, uiTableModel *model)
{
    ardillo_ui_TableModelHandler_t *this = (ardillo_ui_TableModelHandler_t *)(uis->userData);
    zval args[1];
    zval retval;
    ZVAL_OBJ(&args[0], &((ardillo_ui_TableModel_t *)uiTableModelGetUserData(model))->std);
    zend_string *method = zend_string_init("numColumnsHandler", strlen("numColumnsHandler"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_TableModelHandler_t *)this)->std, method, &retval, 1, args);
    zend_string_release(method);
    int ret = Z_LVAL(retval);
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        zval_ptr_dtor(&args[0]);
        return 0;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\TableModelHandler::numColumnsHandler");
        zval_ptr_dtor(&args[0]);
        return 0;
    }

    return ret;
}

int ardillo_call_TableModelHandler_numRowsHandler(uiTableModelHandler *uis, uiTableModel *model)
{
    ardillo_ui_TableModelHandler_t *this = (ardillo_ui_TableModelHandler_t *)(uis->userData);
    zval args[1];
    zval retval;
    ZVAL_OBJ(&args[0], &((ardillo_ui_TableModel_t *)uiTableModelGetUserData(model))->std);
    zend_string *method = zend_string_init("numRowsHandler", strlen("numRowsHandler"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_TableModelHandler_t *)this)->std, method, &retval, 1, args);
    zend_string_release(method);
    int ret = Z_LVAL(retval);
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        zval_ptr_dtor(&args[0]);
        return 0;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\TableModelHandler::numRowsHandler");
        zval_ptr_dtor(&args[0]);
        return 0;
    }

    return ret;
}

void ardillo_call_TableModelHandler_setCellValueHandler(uiTableModelHandler *uis, uiTableModel *model, int row, int column, const uiTableValue *value)
{
    ardillo_ui_TableModelHandler_t *this = (ardillo_ui_TableModelHandler_t *)(uis->userData);
    zval args[4];
    zval retval;
    ZVAL_OBJ(&args[0], &((ardillo_ui_TableModel_t *)uiTableModelGetUserData(model))->std);
    ZVAL_LONG(&args[1], (zend_long)row);
    ZVAL_LONG(&args[2], (zend_long)column);

    if (value) {
        switch (uiTableValueGetType(value)) {
            case uiTableValueTypeString: {
                zend_object *value_obj = ardillo_create_TableValueString_object(ce_Ardillo_TableValueString);
                ardillo_ui_TableValueString_t *value_wrapped = ARDILLO_GET_OBJECT(ardillo_ui_TableValueString_t, value_obj);
                value_wrapped->uis = (uiTableValue *)value;
                ZVAL_OBJ(&args[3], value_obj);
                break;
            }

            case uiTableValueTypeImage: {
                zend_object *value_obj = ardillo_create_TableValueImage_object(ce_Ardillo_TableValueImage);
                ardillo_ui_TableValueImage_t *value_wrapped = ARDILLO_GET_OBJECT(ardillo_ui_TableValueImage_t, value_obj);
                value_wrapped->uis = (uiTableValue *)value;
                ZVAL_OBJ(&args[3], value_obj);
                break;
            }

            case uiTableValueTypeInt: {
                zend_object *value_obj = ardillo_create_TableValueInt_object(ce_Ardillo_TableValueInt);
                ardillo_ui_TableValueInt_t *value_wrapped = ARDILLO_GET_OBJECT(ardillo_ui_TableValueInt_t, value_obj);
                value_wrapped->uis = (uiTableValue *)value;
                ZVAL_OBJ(&args[3], value_obj);
                break;
            }

            case uiTableValueTypeColor: {
                zend_object *value_obj = ardillo_create_TableValueColor_object(ce_Ardillo_TableValueColor);
                ardillo_ui_TableValueColor_t *value_wrapped = ARDILLO_GET_OBJECT(ardillo_ui_TableValueColor_t, value_obj);
                value_wrapped->uis = (uiTableValue *)value;
                ZVAL_OBJ(&args[3], value_obj);
                break;
            }
        }
    } else {
        ZVAL_NULL(&args[3]);
    }

    zend_string *method = zend_string_init("setCellValueHandler", strlen("setCellValueHandler"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_TableModelHandler_t *)this)->std, method, &retval, 4, args);
    zend_string_release(method);

    zval_ptr_dtor(&retval);
    zval_ptr_dtor(&args[3]);

    if (successful != SUCCESS) {
        zval_ptr_dtor(&args[0]);
        zval_ptr_dtor(&args[1]);
        zval_ptr_dtor(&args[2]);
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\TableModelHandler::setCellValueHandler");
        zval_ptr_dtor(&args[0]);
        zval_ptr_dtor(&args[1]);
        zval_ptr_dtor(&args[2]);
        return;
    }

    return;
}

zend_object_handlers TableModelHandler_object_handlers;

zend_object* ardillo_create_TableModelHandler_object(zend_class_entry *ce)
{
    ardillo_ui_TableModelHandler_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_TableModelHandler_t) + zend_object_properties_size(ce));
    ardillo_s->uis = (uiTableModelHandler *)ecalloc(1, sizeof(uiTableModelHandler));
    ardillo_s->uis->CellValue = ardillo_call_TableModelHandler_cellValueHandler;
    ardillo_s->uis->ColumnType = ardillo_call_TableModelHandler_columnTypeHandler;
    ardillo_s->uis->NumColumns = ardillo_call_TableModelHandler_numColumnsHandler;
    ardillo_s->uis->NumRows = ardillo_call_TableModelHandler_numRowsHandler;
    ardillo_s->uis->SetCellValue = ardillo_call_TableModelHandler_setCellValueHandler;
    ardillo_s->uis->userData = ardillo_s;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&TableModelHandler_object_handlers, zend_get_std_object_handlers(), sizeof(TableModelHandler_object_handlers));
    TableModelHandler_object_handlers.offset = XtOffsetOf(ardillo_ui_TableModelHandler_t, std);
    TableModelHandler_object_handlers.free_obj = ardillo_free_TableModelHandler_object;
    ardillo_s->std.handlers = &TableModelHandler_object_handlers;

    if (!ardillo_default_app) {
        zend_error(E_CORE_ERROR, "Cannot instantiate Ardillo\\TableModelHandler outside of an Application context");
        return NULL;
    }

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created TableModelHandler @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_TableModelHandler_object(zend_object *object)
{
    ardillo_ui_TableModelHandler_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_TableModelHandler_t, object);

    ardillo_debug_objects(0, "Freeing TableModelHandler @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Refcount for TableModelHandler @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    if (ardillo_s->uis) {
        efree(ardillo_s->uis);
        ardillo_s->uis = NULL;
    }

    ardillo_debug_objects(0, "Done freeing TableModelHandler @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_TableModelHandler, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_TableModelHandler_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableModelHandler_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}
