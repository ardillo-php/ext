#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

void ardillo_call_Spinbox_onChanged(uiSpinbox *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onChanged", strlen("onChanged"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_Spinbox_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);

    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Spinbox::onChanged");
        return;
    }

    return;
}

zend_object_handlers Spinbox_object_handlers;

zend_object* ardillo_create_Spinbox_object(zend_class_entry *ce)
{
    ardillo_ui_Spinbox_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Spinbox_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Spinbox_object_handlers, zend_get_std_object_handlers(), sizeof(Spinbox_object_handlers));
    Spinbox_object_handlers.offset = XtOffsetOf(ardillo_ui_Spinbox_t, std);
    Spinbox_object_handlers.free_obj = ardillo_free_Spinbox_object;
    ardillo_s->std.handlers = &Spinbox_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Spinbox @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Spinbox_object(zend_object *object)
{
    ardillo_ui_Spinbox_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Spinbox_t, object);

    ardillo_debug_objects(0, "Freeing Spinbox @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native Spinbox @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }

    ardillo_debug_objects(0, "Refcount for Spinbox @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Spinbox @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Spinbox, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Spinbox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Spinbox_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Spinbox, __construct)
{
    zend_long min = 0;
    zend_long max = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(min)
        Z_PARAM_LONG(max)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Spinbox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Spinbox_t, getThis());
    this->uis = uiNewSpinbox((int)min, (int)max);
    ardillo_debug_objects(0, "Constructing Spinbox @%p (uis @ %p)\n", this, this->uis);
    uiSpinboxOnChanged(this->uis, ardillo_call_Spinbox_onChanged, this);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_Spinbox, getValue)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Spinbox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Spinbox_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Spinbox::getValue on invalid object");
    }

    int ret = uiSpinboxValue(this->uis);

    RETURN_LONG(ret);
}

ZEND_METHOD(Ardillo_Spinbox, setValue)
{
    zend_long value = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(value)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Spinbox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Spinbox_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Spinbox::setValue on invalid object");
    }

    uiSpinboxSetValue(this->uis, (int)value);
}

ZEND_METHOD(Ardillo_Spinbox, onChanged)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}
