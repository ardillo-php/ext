#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers TableModel_object_handlers;

zend_object* ardillo_create_TableModel_object(zend_class_entry *ce)
{
    ardillo_ui_TableModel_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_TableModel_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&TableModel_object_handlers, zend_get_std_object_handlers(), sizeof(TableModel_object_handlers));
    TableModel_object_handlers.offset = XtOffsetOf(ardillo_ui_TableModel_t, std);
    TableModel_object_handlers.free_obj = ardillo_free_TableModel_object;
    ardillo_s->std.handlers = &TableModel_object_handlers;

    if (!ardillo_default_app) {
        zend_error(E_CORE_ERROR, "Cannot instantiate Ardillo\\TableModel outside of an Application context");
        return NULL;
    }

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created TableModel @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_TableModel_object(zend_object *object)
{
    ardillo_ui_TableModel_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_TableModel_t, object);

    ardillo_debug_objects(0, "Freeing TableModel @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Freeing native TableModel @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
    uiFreeTableModel(ardillo_s->uis);

    ardillo_debug_objects(0, "Refcount for TableModel @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing TableModel @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_TableModel, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_TableModel_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableModel_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_TableModel, __construct)
{
    zval *mh = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(mh, ce_Ardillo_TableModelHandler)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_TableModel_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableModel_t, getThis());
    this->uis = uiNewTableModel(ARDILLO_ZVAL_GET_UIS(ardillo_ui_TableModelHandler_t, mh));
    ardillo_debug_objects(0, "Constructing TableModel @%p (uis @ %p)\n", this, this->uis);
    uiTableModelSetUserData(this->uis, this);
}

ZEND_METHOD(Ardillo_TableModel, rowChanged)
{
    zend_long index = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_TableModel_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableModel_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\TableModel::rowChanged on invalid object");
    }

    uiTableModelRowChanged(this->uis, (int)index);
}

ZEND_METHOD(Ardillo_TableModel, rowDeleted)
{
    zend_long oldIndex = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(oldIndex)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_TableModel_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableModel_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\TableModel::rowDeleted on invalid object");
    }

    uiTableModelRowDeleted(this->uis, (int)oldIndex);
}

ZEND_METHOD(Ardillo_TableModel, rowInserted)
{
    zend_long newIndex = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(newIndex)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_TableModel_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableModel_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\TableModel::rowInserted on invalid object");
    }

    uiTableModelRowInserted(this->uis, (int)newIndex);
}
