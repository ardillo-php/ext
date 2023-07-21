#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers HorizontalBox_object_handlers;

zend_object* ardillo_create_HorizontalBox_object(zend_class_entry *ce)
{
    ardillo_ui_HorizontalBox_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_HorizontalBox_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&HorizontalBox_object_handlers, zend_get_std_object_handlers(), sizeof(HorizontalBox_object_handlers));
    HorizontalBox_object_handlers.offset = XtOffsetOf(ardillo_ui_HorizontalBox_t, std);
    HorizontalBox_object_handlers.free_obj = ardillo_free_HorizontalBox_object;
    ardillo_s->std.handlers = &HorizontalBox_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created HorizontalBox @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_HorizontalBox_object(zend_object *object)
{
    ardillo_ui_HorizontalBox_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_HorizontalBox_t, object);

    ardillo_debug_objects(0, "Freeing HorizontalBox @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native HorizontalBox @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }
    
    ardillo_debug_objects(0, "Refcount for HorizontalBox @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing HorizontalBox @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_HorizontalBox, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_HorizontalBox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_HorizontalBox_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_HorizontalBox, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_HorizontalBox_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_HorizontalBox_t, getThis());
    this->uis = uiNewHorizontalBox();
    ardillo_debug_objects(0, "Constructing HorizontalBox @%p (uis @ %p)\n", this, this->uis);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}


