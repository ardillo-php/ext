#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers Form_object_handlers;

zend_object* ardillo_create_Form_object(zend_class_entry *ce)
{
    ardillo_ui_Form_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Form_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Form_object_handlers, zend_get_std_object_handlers(), sizeof(Form_object_handlers));
    Form_object_handlers.offset = XtOffsetOf(ardillo_ui_Form_t, std);
    Form_object_handlers.free_obj = ardillo_free_Form_object;
    ardillo_s->std.handlers = &Form_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Form @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Form_object(zend_object *object)
{
    ardillo_ui_Form_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Form_t, object);

    ardillo_debug_objects(0, "Freeing Form @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native Form @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }
    
    ardillo_debug_objects(0, "Refcount for Form @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Form @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Form, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Form_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Form_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Form, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Form_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Form_t, getThis());
    this->uis = uiNewForm();
    ardillo_debug_objects(0, "Constructing Form @%p (uis @ %p)\n", this, this->uis);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_Form, getPadded)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Form_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Form_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Form::getPadded on invalid object");
    }
    
    int ret = uiFormPadded(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Form, setPadded)
{
    bool padded = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(padded)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Form_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Form_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Form::setPadded on invalid object");
    }
    
    uiFormSetPadded(this->uis, (int)padded);
}

ZEND_METHOD(Ardillo_Form, append)
{
    zend_string *label = NULL;
    zval *c = NULL;
    bool stretchy = 0;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_STR(label)
        Z_PARAM_OBJECT_OF_CLASS(c, ce_Ardillo_Control)
        Z_PARAM_BOOL(stretchy)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Form_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Form_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Form::append on invalid object");
    }
    
    uiFormAppend(this->uis, ZSTR_VAL(label), ARDILLO_ZVAL_GET_UIS(ardillo_ui_Control_t, c), (int)stretchy);
}

ZEND_METHOD(Ardillo_Form, delete)
{
    zend_long index = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Form_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Form_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Form::delete on invalid object");
    }
    
    uiFormDelete(this->uis, (int)index);
}

ZEND_METHOD(Ardillo_Form, childrenCount)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Form_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Form_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Form::numChildren on invalid object");
    }
    
    int ret = uiFormNumChildren(this->uis);

    RETURN_LONG(ret);
}


