#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

void ardillo_call_Table_onHeaderClicked(uiTable *uis, int column, void *this)
{
    zval args[1];
    zval retval;
    ZVAL_LONG(&args[0], (zend_long)column);
    zend_string *method = zend_string_init("onHeaderClicked", strlen("onHeaderClicked"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_Table_t *)this)->std, method, &retval, 1, args);
    zend_string_release(method);

    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        zval_ptr_dtor(&args[0]);
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Table::onHeaderClicked");
        zval_ptr_dtor(&args[0]);
        return;
    }

    return;
}

void ardillo_call_Table_onRowClicked(uiTable *uis, int row, void *this)
{
    zval args[1];
    zval retval;
    ZVAL_LONG(&args[0], (zend_long)row);
    zend_string *method = zend_string_init("onRowClicked", strlen("onRowClicked"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_Table_t *)this)->std, method, &retval, 1, args);
    zend_string_release(method);

    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        zval_ptr_dtor(&args[0]);
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Table::onRowClicked");
        zval_ptr_dtor(&args[0]);
        return;
    }

    return;
}

void ardillo_call_Table_onRowDoubleClicked(uiTable *uis, int row, void *this)
{
    zval args[1];
    zval retval;
    ZVAL_LONG(&args[0], (zend_long)row);
    zend_string *method = zend_string_init("onRowDoubleClicked", strlen("onRowDoubleClicked"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_Table_t *)this)->std, method, &retval, 1, args);
    zend_string_release(method);

    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        zval_ptr_dtor(&args[0]);
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Table::onRowDoubleClicked");
        zval_ptr_dtor(&args[0]);
        return;
    }

    return;
}

zend_object_handlers Table_object_handlers;

zend_object* ardillo_create_Table_object(zend_class_entry *ce)
{
    ardillo_ui_Table_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Table_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Table_object_handlers, zend_get_std_object_handlers(), sizeof(Table_object_handlers));
    Table_object_handlers.offset = XtOffsetOf(ardillo_ui_Table_t, std);
    Table_object_handlers.free_obj = ardillo_free_Table_object;
    ardillo_s->std.handlers = &Table_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Table @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Table_object(zend_object *object)
{
    ardillo_ui_Table_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Table_t, object);

    ardillo_debug_objects(0, "Freeing Table @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native Table @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }

    ardillo_debug_objects(0, "Refcount for Table @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Table @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Table, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

void ardillo_call_Table_onSelectionChanged(uiTable *uis, void *this)
{
    zval retval, params[1];
    uiTableSelection *selection = uiTableGetSelection(((ardillo_ui_Table_t *)this)->uis);

    array_init_size(&params[0], selection->NumRows);

    for (size_t i = 0; i < selection->NumRows; i++) {
        add_next_index_long(&params[0], selection->Rows[i]);
    }

    zend_string *method = zend_string_init("onSelectionChanged", strlen("onSelectionChanged"), 0);
    int successful = zend_call_method_if_exists(&((ardillo_ui_Table_t *)this)->std, method, &retval, 1, params);

    zend_string_release(method);
    zval_ptr_dtor(&retval);
    zval_ptr_dtor(&params[0]);
    uiFreeTableSelection(selection);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Table::onSelectionChanged");
        return;
    }

    return;
}

ZEND_METHOD(Ardillo_Table, onSelectionChanged)
{
    zval *rows;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(rows)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    RETURN_NULL();
}

ZEND_METHOD(Ardillo_Table, setSelection)
{
    zval *rows, *val;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(rows)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());
    uiTableSelection *selection = (uiTableSelection *)ecalloc(1, sizeof(uiTableSelection));
    selection->Rows = (int *)ecalloc(Z_ARRVAL_P(rows)->nNumOfElements, sizeof(int));
    int i = 0;

    ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(rows), val) {
        if (Z_TYPE_P(val) == IS_LONG) {
            selection->Rows[i++] = Z_LVAL_P(val);
        }
    } ZEND_HASH_FOREACH_END();

    selection->NumRows = i;
    uiTableSetSelection(this->uis, selection);

    efree(selection->Rows);
    efree(selection);
}

ZEND_METHOD(Ardillo_Table, __construct)
{
    zval *params = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(params, ce_Ardillo_TableParams)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());
    this->uis = uiNewTable(ARDILLO_ZVAL_GET_UIS(ardillo_ui_TableParams_t, params));
    ardillo_debug_objects(0, "Constructing Table @%p (uis @ %p)\n", this, this->uis);
    uiTableHeaderOnClicked(this->uis, ardillo_call_Table_onHeaderClicked, this);
    uiTableOnRowClicked(this->uis, ardillo_call_Table_onRowClicked, this);
    uiTableOnRowDoubleClicked(this->uis, ardillo_call_Table_onRowDoubleClicked, this);
    uiTableOnSelectionChanged(this->uis, ardillo_call_Table_onSelectionChanged, this);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_Table, getColumnWidth)
{
    zend_long column = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(column)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::getColumnWidth on invalid object");
    }

    int ret = uiTableColumnWidth(this->uis, (int)column);

    RETURN_LONG(ret);
}

ZEND_METHOD(Ardillo_Table, setColumnWidth)
{
    zend_long column = 0;
    zend_long width = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(column)
        Z_PARAM_LONG(width)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::setColumnWidth on invalid object");
    }

    uiTableColumnSetWidth(this->uis, (int)column, (int)width);
}

ZEND_METHOD(Ardillo_Table, getHeaderSortIndicator)
{
    zend_long column = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(column)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::getHeaderSortIndicator on invalid object");
    }

    int ret = uiTableHeaderSortIndicator(this->uis, (int)column);

    RETURN_LONG(ret);
}

ZEND_METHOD(Ardillo_Table, setHeaderSortIndicator)
{
    zend_long column = 0;
    zend_long indicator = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(column)
        Z_PARAM_LONG(indicator)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::setHeaderSortIndicator on invalid object");
    }

    uiTableHeaderSetSortIndicator(this->uis, (int)column, (int)indicator);
}

ZEND_METHOD(Ardillo_Table, getHeaderVisible)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::getHeaderVisible on invalid object");
    }

    int ret = uiTableHeaderVisible(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Table, setHeaderVisible)
{
    zend_long visible = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(visible)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::setHeaderVisible on invalid object");
    }

    uiTableHeaderSetVisible(this->uis, (int)visible);
}

ZEND_METHOD(Ardillo_Table, getSelectionMode)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::getSelectionMode on invalid object");
    }

    int ret = uiTableGetSelectionMode(this->uis);

    RETURN_LONG(ret);
}

ZEND_METHOD(Ardillo_Table, setSelectionMode)
{
    zend_long mode = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(mode)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::setSelectionMode on invalid object");
    }

    uiTableSetSelectionMode(this->uis, (int)mode);
}

ZEND_METHOD(Ardillo_Table, onHeaderClicked)
{
    zend_long column = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(column)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    RETURN_NULL();
}

ZEND_METHOD(Ardillo_Table, onRowClicked)
{
    zend_long row = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(row)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    RETURN_NULL();
}

ZEND_METHOD(Ardillo_Table, onRowDoubleClicked)
{
    zend_long row = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(row)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    RETURN_NULL();
}

ZEND_METHOD(Ardillo_Table, appendButtonColumn)
{
    zend_string *name = NULL;
    zend_long buttonModelColumn = 0;
    zend_long buttonClickableModelColumn = 0;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_STR(name)
        Z_PARAM_LONG(buttonModelColumn)
        Z_PARAM_LONG(buttonClickableModelColumn)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::appendButtonColumn on invalid object");
    }

    uiTableAppendButtonColumn(this->uis, ZSTR_VAL(name), (int)buttonModelColumn, (int)buttonClickableModelColumn);
}

ZEND_METHOD(Ardillo_Table, appendCheckboxColumn)
{
    zend_string *name = NULL;
    zend_long checkboxModelColumn = 0;
    zend_long checkboxEditableModelColumn = 0;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_STR(name)
        Z_PARAM_LONG(checkboxModelColumn)
        Z_PARAM_LONG(checkboxEditableModelColumn)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::appendCheckboxColumn on invalid object");
    }

    uiTableAppendCheckboxColumn(this->uis, ZSTR_VAL(name), (int)checkboxModelColumn, (int)checkboxEditableModelColumn);
}

ZEND_METHOD(Ardillo_Table, appendCheckboxTextColumn)
{
    zend_string *name = NULL;
    zend_long checkboxModelColumn = 0;
    zend_long checkboxEditableModelColumn = 0;
    zend_long textModelColumn = 0;
    zend_long textEditableModelColumn = 0;
    zval *textParams = NULL;

    ZEND_PARSE_PARAMETERS_START(6, 6)
        Z_PARAM_STR(name)
        Z_PARAM_LONG(checkboxModelColumn)
        Z_PARAM_LONG(checkboxEditableModelColumn)
        Z_PARAM_LONG(textModelColumn)
        Z_PARAM_LONG(textEditableModelColumn)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(textParams, ce_Ardillo_TableTextColumnOptionalParams)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::appendCheckboxTextColumn on invalid object");
    }

    uiTableAppendCheckboxTextColumn(this->uis, ZSTR_VAL(name), (int)checkboxModelColumn, (int)checkboxEditableModelColumn, (int)textModelColumn, (int)textEditableModelColumn, ARDILLO_ZVAL_GET_UIS_OR_NULL(ardillo_ui_TableTextColumnOptionalParams_t, textParams));
}

ZEND_METHOD(Ardillo_Table, appendImageColumn)
{
    zend_string *name = NULL;
    zend_long imageModelColumn = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STR(name)
        Z_PARAM_LONG(imageModelColumn)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::appendImageColumn on invalid object");
    }

    uiTableAppendImageColumn(this->uis, ZSTR_VAL(name), (int)imageModelColumn);
}

ZEND_METHOD(Ardillo_Table, appendImageTextColumn)
{
    zend_string *name = NULL;
    zend_long imageModelColumn = 0;
    zend_long textModelColumn = 0;
    zend_long textEditableModelColumn = 0;
    zval *textParams = NULL;

    ZEND_PARSE_PARAMETERS_START(5, 5)
        Z_PARAM_STR(name)
        Z_PARAM_LONG(imageModelColumn)
        Z_PARAM_LONG(textModelColumn)
        Z_PARAM_LONG(textEditableModelColumn)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(textParams, ce_Ardillo_TableTextColumnOptionalParams)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::appendImageTextColumn on invalid object");
    }

    uiTableAppendImageTextColumn(this->uis, ZSTR_VAL(name), (int)imageModelColumn, (int)textModelColumn, (int)textEditableModelColumn, ARDILLO_ZVAL_GET_UIS_OR_NULL(ardillo_ui_TableTextColumnOptionalParams_t, textParams));
}

ZEND_METHOD(Ardillo_Table, appendProgressBarColumn)
{
    zend_string *name = NULL;
    zend_long progressModelColumn = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STR(name)
        Z_PARAM_LONG(progressModelColumn)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::appendProgressBarColumn on invalid object");
    }

    uiTableAppendProgressBarColumn(this->uis, ZSTR_VAL(name), (int)progressModelColumn);
}

ZEND_METHOD(Ardillo_Table, appendTextColumn)
{
    zend_string *name = NULL;
    zend_long textModelColumn = 0;
    zend_long textEditableModelColumn = 0;
    zval *textParams = NULL;

    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_STR(name)
        Z_PARAM_LONG(textModelColumn)
        Z_PARAM_LONG(textEditableModelColumn)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(textParams, ce_Ardillo_TableTextColumnOptionalParams)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Table_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Table_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Table::appendTextColumn on invalid object");
    }

    uiTableAppendTextColumn(this->uis, ZSTR_VAL(name), (int)textModelColumn, (int)textEditableModelColumn, ARDILLO_ZVAL_GET_UIS_OR_NULL(ardillo_ui_TableTextColumnOptionalParams_t, textParams));
}
