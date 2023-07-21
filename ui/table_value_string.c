#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers TableValueString_object_handlers;

zend_object* ardillo_create_TableValueString_object(zend_class_entry *ce)
{
    ardillo_ui_TableValueString_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_TableValueString_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&TableValueString_object_handlers, zend_get_std_object_handlers(), sizeof(TableValueString_object_handlers));
    TableValueString_object_handlers.offset = XtOffsetOf(ardillo_ui_TableValueString_t, std);
    TableValueString_object_handlers.free_obj = ardillo_free_TableValueString_object;
    ardillo_s->std.handlers = &TableValueString_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created TableValueString @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_TableValueString_object(zend_object *object)
{
    ardillo_ui_TableValueString_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_TableValueString_t, object);

    ardillo_debug_objects(0, "Freeing TableValueString @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Refcount for TableValueString @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing TableValueString @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_TableValueString, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_TableValueString_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableValueString_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_TableValueString, __construct)
{
    zend_string *str = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(str)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_TableValueString_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableValueString_t, getThis());
    this->uis = uiNewTableValueString(ZSTR_VAL(str));
    ardillo_debug_objects(0, "Constructing TableValueString @%p (uis @ %p)\n", this, this->uis);
}

ZEND_METHOD(Ardillo_TableValueString, get)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_TableValueString_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableValueString_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\TableValueString::get on invalid object");
    }

    char *ret = (char *)uiTableValueString(this->uis);

    RETURN_STRING(ret);
}
