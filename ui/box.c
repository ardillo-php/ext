#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers Box_object_handlers;

zend_object* ardillo_create_Box_object(zend_class_entry *ce)
{
    ardillo_ui_Box_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Box_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Box_object_handlers, zend_get_std_object_handlers(), sizeof(Box_object_handlers));
    Box_object_handlers.offset = XtOffsetOf(ardillo_ui_Box_t, std);
    Box_object_handlers.free_obj = ardillo_free_Box_object;
    ardillo_s->std.handlers = &Box_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Box @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Box_object(zend_object *object)
{
    ardillo_ui_Box_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Box_t, object);

    ardillo_debug_objects(0, "Freeing Box @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native Box @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }

    ardillo_debug_objects(0, "Refcount for Box @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Box @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Box, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Box_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Box_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Box, getPadded)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Box_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Box_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Box::getPadded on invalid object");
    }

    int ret = uiBoxPadded(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Box, setPadded)
{
    bool padded = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(padded)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Box_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Box_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Box::setPadded on invalid object");
    }

    uiBoxSetPadded(this->uis, (int)padded);
}

ZEND_METHOD(Ardillo_Box, append)
{
    zval *child = NULL;
    bool stretchy = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_OBJECT_OF_CLASS(child, ce_Ardillo_Control)
        Z_PARAM_BOOL(stretchy)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Box_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Box_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Box::append on invalid object");
    }

    uiBoxAppend(this->uis, ARDILLO_ZVAL_GET_UIS(ardillo_ui_Control_t, child), (int)stretchy);
}

ZEND_METHOD(Ardillo_Box, delete)
{
    zend_long index = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Box_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Box_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Box::delete on invalid object");
    }

    uiBoxDelete(this->uis, (int)index);
}

ZEND_METHOD(Ardillo_Box, childrenCount)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Box_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Box_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Box::numChildren on invalid object");
    }

    int ret = uiBoxNumChildren(this->uis);

    RETURN_LONG(ret);
}
