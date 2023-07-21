#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers Grid_object_handlers;

zend_object* ardillo_create_Grid_object(zend_class_entry *ce)
{
    ardillo_ui_Grid_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Grid_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Grid_object_handlers, zend_get_std_object_handlers(), sizeof(Grid_object_handlers));
    Grid_object_handlers.offset = XtOffsetOf(ardillo_ui_Grid_t, std);
    Grid_object_handlers.free_obj = ardillo_free_Grid_object;
    ardillo_s->std.handlers = &Grid_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Grid @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Grid_object(zend_object *object)
{
    ardillo_ui_Grid_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Grid_t, object);

    ardillo_debug_objects(0, "Freeing Grid @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native Grid @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }

    ardillo_debug_objects(0, "Refcount for Grid @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Grid @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Grid, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Grid_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Grid_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Grid, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Grid_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Grid_t, getThis());
    this->uis = uiNewGrid();
    ardillo_debug_objects(0, "Constructing Grid @%p (uis @ %p)\n", this, this->uis);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_Grid, getPadded)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Grid_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Grid_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Grid::getPadded on invalid object");
    }

    int ret = uiGridPadded(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Grid, setPadded)
{
    bool padded = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(padded)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Grid_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Grid_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Grid::setPadded on invalid object");
    }

    uiGridSetPadded(this->uis, (int)padded);
}

ZEND_METHOD(Ardillo_Grid, append)
{
    zval *c = NULL;
    zend_long left = 0;
    zend_long top = 0;
    zend_long xspan = 0;
    zend_long yspan = 0;
    bool hexpand = 0;
    zend_long halign = 0;
    bool vexpand = 0;
    zend_long valign = 0;

    ZEND_PARSE_PARAMETERS_START(9, 9)
        Z_PARAM_OBJECT_OF_CLASS(c, ce_Ardillo_Control)
        Z_PARAM_LONG(left)
        Z_PARAM_LONG(top)
        Z_PARAM_LONG(xspan)
        Z_PARAM_LONG(yspan)
        Z_PARAM_BOOL(hexpand)
        Z_PARAM_LONG(halign)
        Z_PARAM_BOOL(vexpand)
        Z_PARAM_LONG(valign)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Grid_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Grid_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Grid::append on invalid object");
    }

    uiGridAppend(this->uis, ARDILLO_ZVAL_GET_UIS(ardillo_ui_Control_t, c), (int)left, (int)top, (int)xspan, (int)yspan, (int)hexpand, (int)halign, (int)vexpand, (int)valign);
}

ZEND_METHOD(Ardillo_Grid, insertAt)
{
    zval *c = NULL;
    zval *existing = NULL;
    zend_long at = 0;
    zend_long xspan = 0;
    zend_long yspan = 0;
    bool hexpand = 0;
    zend_long halign = 0;
    bool vexpand = 0;
    zend_long valign = 0;

    ZEND_PARSE_PARAMETERS_START(9, 9)
        Z_PARAM_OBJECT_OF_CLASS(c, ce_Ardillo_Control)
        Z_PARAM_OBJECT_OF_CLASS(existing, ce_Ardillo_Control)
        Z_PARAM_LONG(at)
        Z_PARAM_LONG(xspan)
        Z_PARAM_LONG(yspan)
        Z_PARAM_BOOL(hexpand)
        Z_PARAM_LONG(halign)
        Z_PARAM_BOOL(vexpand)
        Z_PARAM_LONG(valign)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Grid_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Grid_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Grid::insertAt on invalid object");
    }

    uiGridInsertAt(this->uis, ARDILLO_ZVAL_GET_UIS(ardillo_ui_Control_t, c), ARDILLO_ZVAL_GET_UIS(ardillo_ui_Control_t, existing), at, (int)xspan, (int)yspan, (int)hexpand, (int)halign, (int)vexpand, (int)valign);
}
