#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

void ardillo_call_Entry_onChanged(uiEntry *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onChanged", strlen("onChanged"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_Entry_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);

    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Entry::onChanged");
        return;
    }

    return;
}

zend_object_handlers Entry_object_handlers;

zend_object* ardillo_create_Entry_object(zend_class_entry *ce)
{
    ardillo_ui_Entry_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Entry_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Entry_object_handlers, zend_get_std_object_handlers(), sizeof(Entry_object_handlers));
    Entry_object_handlers.offset = XtOffsetOf(ardillo_ui_Entry_t, std);
    Entry_object_handlers.free_obj = ardillo_free_Entry_object;
    ardillo_s->std.handlers = &Entry_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Entry @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Entry_object(zend_object *object)
{
    ardillo_ui_Entry_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Entry_t, object);

    ardillo_debug_objects(0, "Freeing Entry @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native Entry @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }

    ardillo_debug_objects(0, "Refcount for Entry @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Entry @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Entry, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Entry_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Entry_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Entry, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Entry_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Entry_t, getThis());
    this->uis = uiNewEntry();
    ardillo_debug_objects(0, "Constructing Entry @%p (uis @ %p)\n", this, this->uis);
    uiEntryOnChanged(this->uis, ardillo_call_Entry_onChanged, this);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_Entry, getReadOnly)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Entry_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Entry_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Entry::getReadOnly on invalid object");
    }

    int ret = uiEntryReadOnly(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Entry, setReadOnly)
{
    zend_long readonly = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(readonly)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Entry_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Entry_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Entry::setReadOnly on invalid object");
    }

    uiEntrySetReadOnly(this->uis, (int)readonly);
}

ZEND_METHOD(Ardillo_Entry, getText)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Entry_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Entry_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Entry::getText on invalid object");
    }

    char *ret = (char *)uiEntryText(this->uis);

    RETVAL_STRING(ret);
    uiFreeText(ret);
}

ZEND_METHOD(Ardillo_Entry, setText)
{
    zend_string *text = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Entry_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Entry_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Entry::setText on invalid object");
    }

    uiEntrySetText(this->uis, ZSTR_VAL(text));
}

ZEND_METHOD(Ardillo_Entry, onChanged)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}
