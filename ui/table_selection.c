#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers TableSelection_object_handlers;

zend_object* ardillo_create_TableSelection_object(zend_class_entry *ce)
{
    ardillo_ui_TableSelection_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_TableSelection_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&TableSelection_object_handlers, zend_get_std_object_handlers(), sizeof(TableSelection_object_handlers));
    TableSelection_object_handlers.offset = XtOffsetOf(ardillo_ui_TableSelection_t, std);
    TableSelection_object_handlers.free_obj = ardillo_free_TableSelection_object;
    ardillo_s->std.handlers = &TableSelection_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created TableSelection @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_TableSelection_object(zend_object *object)
{
    ardillo_ui_TableSelection_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_TableSelection_t, object);

    ardillo_debug_objects(0, "Freeing TableSelection @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Freeing native TableSelection @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
    uiFreeTableSelection(ardillo_s->uis);
    
    ardillo_debug_objects(0, "Refcount for TableSelection @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing TableSelection @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_TableSelection, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_TableSelection_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableSelection_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}


ZEND_METHOD(Ardillo_TableSelection, __construct)
{
    
    ardillo_ui_TableSelection_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableSelection_t, getThis());
    this->uis = (uiTableSelection *)ecalloc(1, sizeof(uiTableSelection));
}

ZEND_METHOD(Ardillo_TableSelection, getNumRows)
{
    
    ardillo_ui_TableSelection_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableSelection_t, getThis());
    RETURN_LONG((zend_long)this->uis->NumRows);
}

ZEND_METHOD(Ardillo_TableSelection, setNumRows)
{
    zend_long numRows = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(numRows)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_TableSelection_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableSelection_t, getThis());
    this->uis->NumRows = numRows;
}

ZEND_METHOD(Ardillo_TableSelection, getRows)
{
    
    ardillo_ui_TableSelection_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableSelection_t, getThis());
    
    zval rows;
    array_init_size(&rows, this->uis->NumRows);
    
    for (size_t i = 0; i < this->uis->NumRows; i++) {
        add_next_index_long(&rows, this->uis->Rows[i]);
    }
    
    RETVAL_ZVAL(&rows, 0, 0);
}

ZEND_METHOD(Ardillo_TableSelection, setRows)
{
    zval *rows;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(rows)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_TableSelection_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableSelection_t, getThis());
    zval *val;
    this->uis->Rows = (int *)ecalloc(Z_ARRVAL_P(rows)->nNumOfElements, sizeof(int));
    int i = 0;
    
    ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(rows), val) {
        if (Z_TYPE_P(val) == IS_LONG) {
            this->uis->Rows[i++] = Z_LVAL_P(val);
        }
    } ZEND_HASH_FOREACH_END();
}


