#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

void ardillo_call_FontButton_onChanged(uiFontButton *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onChanged", strlen("onChanged"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_FontButton_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);

    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\FontButton::onChanged");
        return;
    }

    return;
}

zend_object_handlers FontButton_object_handlers;

zend_object* ardillo_create_FontButton_object(zend_class_entry *ce)
{
    ardillo_ui_FontButton_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_FontButton_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&FontButton_object_handlers, zend_get_std_object_handlers(), sizeof(FontButton_object_handlers));
    FontButton_object_handlers.offset = XtOffsetOf(ardillo_ui_FontButton_t, std);
    FontButton_object_handlers.free_obj = ardillo_free_FontButton_object;
    ardillo_s->std.handlers = &FontButton_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created FontButton @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_FontButton_object(zend_object *object)
{
    ardillo_ui_FontButton_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_FontButton_t, object);

    ardillo_debug_objects(0, "Freeing FontButton @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native FontButton @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }

    ardillo_debug_objects(0, "Refcount for FontButton @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing FontButton @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_FontButton, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_FontButton_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontButton_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_FontButton, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_FontButton_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontButton_t, getThis());
    this->uis = uiNewFontButton();
    ardillo_debug_objects(0, "Constructing FontButton @%p (uis @ %p)\n", this, this->uis);
    uiFontButtonOnChanged(this->uis, ardillo_call_FontButton_onChanged, this);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_FontButton, onChanged)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}

ZEND_METHOD(Ardillo_FontButton, getFont)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_FontButton_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontButton_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\FontButton::font on invalid object");
    }

    uiFontDescriptor *desc;
    zend_object *obj = ardillo_create_FontDescriptor_object(ce_Ardillo_FontDescriptor);
    uiFontButtonFont(this->uis, desc);
    memcpy(ARDILLO_GET_OBJECT(ardillo_ui_FontDescriptor_t, obj)->uis, desc, sizeof(uiFontDescriptor));
    uiFreeFontButtonFont(desc);

    zval ret;
    ZVAL_OBJ(&ret, obj);
    RETVAL_ZVAL(&ret, 0, 0);
}
