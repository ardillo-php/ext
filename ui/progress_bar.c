#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers ProgressBar_object_handlers;

zend_object* ardillo_create_ProgressBar_object(zend_class_entry *ce)
{
    ardillo_ui_ProgressBar_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_ProgressBar_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&ProgressBar_object_handlers, zend_get_std_object_handlers(), sizeof(ProgressBar_object_handlers));
    ProgressBar_object_handlers.offset = XtOffsetOf(ardillo_ui_ProgressBar_t, std);
    ProgressBar_object_handlers.free_obj = ardillo_free_ProgressBar_object;
    ardillo_s->std.handlers = &ProgressBar_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created ProgressBar @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_ProgressBar_object(zend_object *object)
{
    ardillo_ui_ProgressBar_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_ProgressBar_t, object);

    ardillo_debug_objects(0, "Freeing ProgressBar @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native ProgressBar @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }

    ardillo_debug_objects(0, "Refcount for ProgressBar @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing ProgressBar @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_ProgressBar, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_ProgressBar_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_ProgressBar_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_ProgressBar, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_ProgressBar_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_ProgressBar_t, getThis());
    this->uis = uiNewProgressBar();
    ardillo_debug_objects(0, "Constructing ProgressBar @%p (uis @ %p)\n", this, this->uis);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_ProgressBar, getValue)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_ProgressBar_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_ProgressBar_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\ProgressBar::getValue on invalid object");
    }

    int ret = uiProgressBarValue(this->uis);

    RETURN_LONG(ret);
}

ZEND_METHOD(Ardillo_ProgressBar, setValue)
{
    zend_long n = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(n)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_ProgressBar_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_ProgressBar_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\ProgressBar::setValue on invalid object");
    }

    uiProgressBarSetValue(this->uis, (int)n);
}
