#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

void ardillo_call_EditableCombobox_onChanged(uiEditableCombobox *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onChanged", strlen("onChanged"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_EditableCombobox_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);
    
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\EditableCombobox::onChanged");
        return;
    }

    return;
}


zend_object_handlers EditableCombobox_object_handlers;

zend_object* ardillo_create_EditableCombobox_object(zend_class_entry *ce)
{
    ardillo_ui_EditableCombobox_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_EditableCombobox_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&EditableCombobox_object_handlers, zend_get_std_object_handlers(), sizeof(EditableCombobox_object_handlers));
    EditableCombobox_object_handlers.offset = XtOffsetOf(ardillo_ui_EditableCombobox_t, std);
    EditableCombobox_object_handlers.free_obj = ardillo_free_EditableCombobox_object;
    ardillo_s->std.handlers = &EditableCombobox_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created EditableCombobox @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_EditableCombobox_object(zend_object *object)
{
    ardillo_ui_EditableCombobox_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_EditableCombobox_t, object);

    ardillo_debug_objects(0, "Freeing EditableCombobox @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native EditableCombobox @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }
    
    ardillo_debug_objects(0, "Refcount for EditableCombobox @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing EditableCombobox @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_EditableCombobox, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_EditableCombobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_EditableCombobox_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_EditableCombobox, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_EditableCombobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_EditableCombobox_t, getThis());
    this->uis = uiNewEditableCombobox();
    ardillo_debug_objects(0, "Constructing EditableCombobox @%p (uis @ %p)\n", this, this->uis);
    uiEditableComboboxOnChanged(this->uis, ardillo_call_EditableCombobox_onChanged, this);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_EditableCombobox, getText)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_EditableCombobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_EditableCombobox_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\EditableCombobox::getText on invalid object");
    }
    
    char *ret = (char *)uiEditableComboboxText(this->uis);

    RETVAL_STRING(ret);
    uiFreeText(ret);
}

ZEND_METHOD(Ardillo_EditableCombobox, setText)
{
    zend_string *text = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_EditableCombobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_EditableCombobox_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\EditableCombobox::setText on invalid object");
    }
    
    uiEditableComboboxSetText(this->uis, ZSTR_VAL(text));
}

ZEND_METHOD(Ardillo_EditableCombobox, onChanged)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}

ZEND_METHOD(Ardillo_EditableCombobox, append)
{
    zend_string *text = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_EditableCombobox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_EditableCombobox_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\EditableCombobox::append on invalid object");
    }
    
    uiEditableComboboxAppend(this->uis, ZSTR_VAL(text));
}


