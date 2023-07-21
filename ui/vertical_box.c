#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers VerticalBox_object_handlers;

zend_object* ardillo_create_VerticalBox_object(zend_class_entry *ce)
{
    ardillo_ui_VerticalBox_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_VerticalBox_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&VerticalBox_object_handlers, zend_get_std_object_handlers(), sizeof(VerticalBox_object_handlers));
    VerticalBox_object_handlers.offset = XtOffsetOf(ardillo_ui_VerticalBox_t, std);
    VerticalBox_object_handlers.free_obj = ardillo_free_VerticalBox_object;
    ardillo_s->std.handlers = &VerticalBox_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created VerticalBox @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_VerticalBox_object(zend_object *object)
{
    ardillo_ui_VerticalBox_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_VerticalBox_t, object);

    ardillo_debug_objects(0, "Freeing VerticalBox @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native VerticalBox @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }

    ardillo_debug_objects(0, "Refcount for VerticalBox @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing VerticalBox @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_VerticalBox, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_VerticalBox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_VerticalBox_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_VerticalBox, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_VerticalBox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_VerticalBox_t, getThis());
    this->uis = uiNewVerticalBox();
    ardillo_debug_objects(0, "Constructing VerticalBox @%p (uis @ %p)\n", this, this->uis);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}
