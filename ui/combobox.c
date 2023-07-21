#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

void ardillo_call_Combobox_onSelected(uiCombobox *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onSelected", strlen("onSelected"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_Combobox_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);

    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Combobox::onSelected");
        return;
    }

    return;
}

zend_object_handlers Combobox_object_handlers;

zend_object* ardillo_create_Combobox_object(zend_class_entry *ce)
{
    ardillo_ui_Combobox_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Combobox_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Combobox_object_handlers, zend_get_std_object_handlers(), sizeof(Combobox_object_handlers));
    Combobox_object_handlers.offset = XtOffsetOf(ardillo_ui_Combobox_t, std);
    Combobox_object_handlers.free_obj = ardillo_free_Combobox_object;
    ardillo_s->std.handlers = &Combobox_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Combobox @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Combobox_object(zend_object *object)
{
    ardillo_ui_Combobox_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Combobox_t, object);

    ardillo_debug_objects(0, "Freeing Combobox @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native Combobox @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }

    ardillo_debug_objects(0, "Refcount for Combobox @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Combobox @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Combobox, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Combobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Combobox_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Combobox, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Combobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Combobox_t, getThis());
    this->uis = uiNewCombobox();
    ardillo_debug_objects(0, "Constructing Combobox @%p (uis @ %p)\n", this, this->uis);
    uiComboboxOnSelected(this->uis, ardillo_call_Combobox_onSelected, this);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_Combobox, getSelected)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Combobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Combobox_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Combobox::getSelected on invalid object");
    }

    int ret = uiComboboxSelected(this->uis);

    RETURN_LONG(ret);
}

ZEND_METHOD(Ardillo_Combobox, setSelected)
{
    zend_long index = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Combobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Combobox_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Combobox::setSelected on invalid object");
    }

    uiComboboxSetSelected(this->uis, (int)index);
}

ZEND_METHOD(Ardillo_Combobox, onSelected)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}

ZEND_METHOD(Ardillo_Combobox, append)
{
    zend_string *text = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Combobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Combobox_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Combobox::append on invalid object");
    }

    uiComboboxAppend(this->uis, ZSTR_VAL(text));
}

ZEND_METHOD(Ardillo_Combobox, clear)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Combobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Combobox_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Combobox::clear on invalid object");
    }

    uiComboboxClear(this->uis);
}

ZEND_METHOD(Ardillo_Combobox, delete)
{
    zend_long index = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Combobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Combobox_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Combobox::delete on invalid object");
    }

    uiComboboxDelete(this->uis, (int)index);
}

ZEND_METHOD(Ardillo_Combobox, insertAt)
{
    zend_long index = 0;
    zend_string *text = NULL;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(index)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Combobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Combobox_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Combobox::insertAt on invalid object");
    }

    uiComboboxInsertAt(this->uis, (int)index, ZSTR_VAL(text));
}

ZEND_METHOD(Ardillo_Combobox, numItems)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Combobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Combobox_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Combobox::numItems on invalid object");
    }

    int ret = uiComboboxNumItems(this->uis);

    RETURN_LONG(ret);
}
