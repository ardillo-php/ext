#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers Area_object_handlers;

zend_object* ardillo_create_Area_object(zend_class_entry *ce)
{
    ardillo_ui_Area_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Area_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Area_object_handlers, zend_get_std_object_handlers(), sizeof(Area_object_handlers));
    Area_object_handlers.offset = XtOffsetOf(ardillo_ui_Area_t, std);
    Area_object_handlers.free_obj = ardillo_free_Area_object;
    ardillo_s->std.handlers = &Area_object_handlers;

    if (!ardillo_default_app) {
        zend_error(E_CORE_ERROR, "Cannot instantiate Ardillo\\Area outside of an Application context");
        return NULL;
    }

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Area @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Area_object(zend_object *object)
{
    ardillo_ui_Area_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Area_t, object);

    ardillo_debug_objects(0, "Freeing Area @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native Area @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }

    ardillo_debug_objects(0, "Refcount for Area @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Area @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Area, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Area_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Area_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Area, __construct)
{
    zval *ah = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(ah, ce_Ardillo_AreaHandler)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Area_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Area_t, getThis());
    this->uis = uiNewArea(ARDILLO_ZVAL_GET_UIS(ardillo_ui_AreaHandler_t, ah));
    ardillo_debug_objects(0, "Constructing Area @%p (uis @ %p)\n", this, this->uis);
    uiAreaSetUserData(this->uis, this);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_Area, queueRedrawAll)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Area_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Area_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Area::queueRedrawAll on invalid object");
    }

    uiAreaQueueRedrawAll(this->uis);
}
