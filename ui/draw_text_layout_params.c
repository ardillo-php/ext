#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

zend_object_handlers DrawTextLayoutParams_object_handlers;

zend_object* ardillo_create_DrawTextLayoutParams_object(zend_class_entry *ce)
{
    ardillo_ui_DrawTextLayoutParams_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_DrawTextLayoutParams_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&DrawTextLayoutParams_object_handlers, zend_get_std_object_handlers(), sizeof(DrawTextLayoutParams_object_handlers));
    DrawTextLayoutParams_object_handlers.offset = XtOffsetOf(ardillo_ui_DrawTextLayoutParams_t, std);
    DrawTextLayoutParams_object_handlers.free_obj = ardillo_free_DrawTextLayoutParams_object;
    ardillo_s->std.handlers = &DrawTextLayoutParams_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created DrawTextLayoutParams @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_DrawTextLayoutParams_object(zend_object *object)
{
    ardillo_ui_DrawTextLayoutParams_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_DrawTextLayoutParams_t, object);

    ardillo_debug_objects(0, "Freeing DrawTextLayoutParams @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Refcount for DrawTextLayoutParams @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing DrawTextLayoutParams @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_DrawTextLayoutParams, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_DrawTextLayoutParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawTextLayoutParams_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_DrawTextLayoutParams, getDefaultFont)
{

    ardillo_ui_DrawTextLayoutParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawTextLayoutParams_t, getThis());
    ardillo_ui_FontDescriptor_t *obj = (ardillo_ui_FontDescriptor_t *)this->uis->DefaultFont;
    zval ret;
    ZVAL_OBJ(&ret, &obj->std);
    RETVAL_ZVAL(&ret, 0, 0);
    zval_ptr_dtor(&ret);
}

ZEND_METHOD(Ardillo_DrawTextLayoutParams, setDefaultFont)
{
    zval *defaultFont = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(defaultFont, ce_Ardillo_FontDescriptor)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawTextLayoutParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawTextLayoutParams_t, getThis());
    this->uis->DefaultFont = ARDILLO_ZVAL_GET_UIS(ardillo_ui_FontDescriptor_t, defaultFont);
}

ZEND_METHOD(Ardillo_DrawTextLayoutParams, getWidth)
{

    ardillo_ui_DrawTextLayoutParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawTextLayoutParams_t, getThis());
    RETURN_DOUBLE(this->uis->Width);
}

ZEND_METHOD(Ardillo_DrawTextLayoutParams, setWidth)
{
    double width = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(width)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawTextLayoutParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawTextLayoutParams_t, getThis());
    this->uis->Width = width;
}

ZEND_METHOD(Ardillo_DrawTextLayoutParams, getAlign)
{

    ardillo_ui_DrawTextLayoutParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawTextLayoutParams_t, getThis());
    RETURN_LONG((zend_long)this->uis->Align);
}

ZEND_METHOD(Ardillo_DrawTextLayoutParams, setAlign)
{
    zend_long align = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(align)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawTextLayoutParams_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawTextLayoutParams_t, getThis());
    this->uis->Align = align;
}
