#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers InitOptions_object_handlers;

zend_object* ardillo_create_InitOptions_object(zend_class_entry *ce)
{
    ardillo_ui_InitOptions_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_InitOptions_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&InitOptions_object_handlers, zend_get_std_object_handlers(), sizeof(InitOptions_object_handlers));
    InitOptions_object_handlers.offset = XtOffsetOf(ardillo_ui_InitOptions_t, std);
    InitOptions_object_handlers.free_obj = ardillo_free_InitOptions_object;
    ardillo_s->std.handlers = &InitOptions_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created InitOptions @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_InitOptions_object(zend_object *object)
{
    ardillo_ui_InitOptions_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_InitOptions_t, object);

    ardillo_debug_objects(0, "Freeing InitOptions @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Refcount for InitOptions @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing InitOptions @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_InitOptions, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_InitOptions_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_InitOptions_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_InitOptions, getSize)
{

    ardillo_ui_InitOptions_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_InitOptions_t, getThis());
    RETURN_LONG((zend_long)this->uis->Size);
}

ZEND_METHOD(Ardillo_InitOptions, setSize)
{
    zend_long size = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(size)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_InitOptions_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_InitOptions_t, getThis());
    this->uis->Size = size;
}
