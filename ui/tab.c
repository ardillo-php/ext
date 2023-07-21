#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers Tab_object_handlers;

zend_object* ardillo_create_Tab_object(zend_class_entry *ce)
{
    ardillo_ui_Tab_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Tab_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Tab_object_handlers, zend_get_std_object_handlers(), sizeof(Tab_object_handlers));
    Tab_object_handlers.offset = XtOffsetOf(ardillo_ui_Tab_t, std);
    Tab_object_handlers.free_obj = ardillo_free_Tab_object;
    ardillo_s->std.handlers = &Tab_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Tab @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Tab_object(zend_object *object)
{
    ardillo_ui_Tab_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Tab_t, object);

    ardillo_debug_objects(0, "Freeing Tab @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native Tab @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }

    ardillo_debug_objects(0, "Refcount for Tab @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Tab @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Tab, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Tab_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Tab_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Tab, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Tab_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Tab_t, getThis());
    this->uis = uiNewTab();
    ardillo_debug_objects(0, "Constructing Tab @%p (uis @ %p)\n", this, this->uis);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_Tab, getMargined)
{
    zend_long index = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Tab_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Tab_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Tab::getMargined on invalid object");
    }

    int ret = uiTabMargined(this->uis, (int)index);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Tab, setMargined)
{
    zend_long index = 0;
    bool margined = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(index)
        Z_PARAM_BOOL(margined)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Tab_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Tab_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Tab::setMargined on invalid object");
    }

    uiTabSetMargined(this->uis, (int)index, (int)margined);
}

ZEND_METHOD(Ardillo_Tab, append)
{
    zend_string *name = NULL;
    zval *c = NULL;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STR(name)
        Z_PARAM_OBJECT_OF_CLASS(c, ce_Ardillo_Control)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Tab_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Tab_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Tab::append on invalid object");
    }

    uiTabAppend(this->uis, ZSTR_VAL(name), ARDILLO_ZVAL_GET_UIS(ardillo_ui_Control_t, c));
}

ZEND_METHOD(Ardillo_Tab, delete)
{
    zend_long index = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Tab_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Tab_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Tab::delete on invalid object");
    }

    uiTabDelete(this->uis, (int)index);
}

ZEND_METHOD(Ardillo_Tab, insertAt)
{
    zend_string *name = NULL;
    zend_long index = 0;
    zval *c = NULL;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_STR(name)
        Z_PARAM_LONG(index)
        Z_PARAM_OBJECT_OF_CLASS(c, ce_Ardillo_Control)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Tab_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Tab_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Tab::insertAt on invalid object");
    }

    uiTabInsertAt(this->uis, ZSTR_VAL(name), (int)index, ARDILLO_ZVAL_GET_UIS(ardillo_ui_Control_t, c));
}

ZEND_METHOD(Ardillo_Tab, pageCount)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Tab_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Tab_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Tab::numPages on invalid object");
    }

    int ret = uiTabNumPages(this->uis);

    RETURN_LONG(ret);
}
