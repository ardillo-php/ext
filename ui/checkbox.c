#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

void ardillo_call_Checkbox_onToggled(uiCheckbox *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onToggled", strlen("onToggled"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_Checkbox_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);
    
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Checkbox::onToggled");
        return;
    }

    return;
}


zend_object_handlers Checkbox_object_handlers;

zend_object* ardillo_create_Checkbox_object(zend_class_entry *ce)
{
    ardillo_ui_Checkbox_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Checkbox_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Checkbox_object_handlers, zend_get_std_object_handlers(), sizeof(Checkbox_object_handlers));
    Checkbox_object_handlers.offset = XtOffsetOf(ardillo_ui_Checkbox_t, std);
    Checkbox_object_handlers.free_obj = ardillo_free_Checkbox_object;
    ardillo_s->std.handlers = &Checkbox_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Checkbox @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Checkbox_object(zend_object *object)
{
    ardillo_ui_Checkbox_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Checkbox_t, object);

    ardillo_debug_objects(0, "Freeing Checkbox @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native Checkbox @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }
    
    ardillo_debug_objects(0, "Refcount for Checkbox @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Checkbox @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Checkbox, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Checkbox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Checkbox_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Checkbox, __construct)
{
    zend_string *text = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Checkbox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Checkbox_t, getThis());
    this->uis = uiNewCheckbox(ZSTR_VAL(text));
    ardillo_debug_objects(0, "Constructing Checkbox @%p (uis @ %p)\n", this, this->uis);
    uiCheckboxOnToggled(this->uis, ardillo_call_Checkbox_onToggled, this);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_Checkbox, getChecked)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Checkbox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Checkbox_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Checkbox::getChecked on invalid object");
    }
    
    int ret = uiCheckboxChecked(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Checkbox, setChecked)
{
    bool checked = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(checked)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Checkbox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Checkbox_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Checkbox::setChecked on invalid object");
    }
    
    uiCheckboxSetChecked(this->uis, (int)checked);
}

ZEND_METHOD(Ardillo_Checkbox, getText)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Checkbox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Checkbox_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Checkbox::getText on invalid object");
    }
    
    char *ret = (char *)uiCheckboxText(this->uis);

    RETVAL_STRING(ret);
    uiFreeText(ret);
}

ZEND_METHOD(Ardillo_Checkbox, setText)
{
    zend_string *text = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Checkbox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Checkbox_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Checkbox::setText on invalid object");
    }
    
    uiCheckboxSetText(this->uis, ZSTR_VAL(text));
}

ZEND_METHOD(Ardillo_Checkbox, onToggled)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}


