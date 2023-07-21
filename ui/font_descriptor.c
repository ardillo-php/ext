#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers FontDescriptor_object_handlers;

zend_object* ardillo_create_FontDescriptor_object(zend_class_entry *ce)
{
    ardillo_ui_FontDescriptor_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_FontDescriptor_t) + zend_object_properties_size(ce));
    ardillo_s->uis = (uiFontDescriptor *)ecalloc(1, sizeof(uiFontDescriptor));

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&FontDescriptor_object_handlers, zend_get_std_object_handlers(), sizeof(FontDescriptor_object_handlers));
    FontDescriptor_object_handlers.offset = XtOffsetOf(ardillo_ui_FontDescriptor_t, std);
    FontDescriptor_object_handlers.free_obj = ardillo_free_FontDescriptor_object;
    ardillo_s->std.handlers = &FontDescriptor_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created FontDescriptor @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_FontDescriptor_object(zend_object *object)
{
    ardillo_ui_FontDescriptor_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_FontDescriptor_t, object);

    ardillo_debug_objects(0, "Freeing FontDescriptor @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));
    
    ardillo_debug_objects(0, "Refcount for FontDescriptor @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    if (ardillo_s->uis) {
        efree(ardillo_s->uis);
        ardillo_s->uis = NULL;
    }

    ardillo_debug_objects(0, "Done freeing FontDescriptor @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_FontDescriptor, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_FontDescriptor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontDescriptor_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_FontDescriptor, getFamily)
{
    
    ardillo_ui_FontDescriptor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontDescriptor_t, getThis());
    RETURN_STRING(this->uis->Family);
}

ZEND_METHOD(Ardillo_FontDescriptor, setFamily)
{
    zend_string *family = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(family)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_FontDescriptor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontDescriptor_t, getThis());
    this->uis->Family = ZSTR_VAL(family);
}

ZEND_METHOD(Ardillo_FontDescriptor, getSize)
{
    
    ardillo_ui_FontDescriptor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontDescriptor_t, getThis());
    RETURN_DOUBLE(this->uis->Size);
}

ZEND_METHOD(Ardillo_FontDescriptor, setSize)
{
    double size = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(size)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_FontDescriptor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontDescriptor_t, getThis());
    this->uis->Size = size;
}

ZEND_METHOD(Ardillo_FontDescriptor, getWeight)
{
    
    ardillo_ui_FontDescriptor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontDescriptor_t, getThis());
    RETURN_LONG((zend_long)this->uis->Weight);
}

ZEND_METHOD(Ardillo_FontDescriptor, setWeight)
{
    zend_long weight = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(weight)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_FontDescriptor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontDescriptor_t, getThis());
    this->uis->Weight = weight;
}

ZEND_METHOD(Ardillo_FontDescriptor, getItalic)
{
    
    ardillo_ui_FontDescriptor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontDescriptor_t, getThis());
    RETURN_LONG((zend_long)this->uis->Italic);
}

ZEND_METHOD(Ardillo_FontDescriptor, setItalic)
{
    zend_long italic = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(italic)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_FontDescriptor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontDescriptor_t, getThis());
    this->uis->Italic = italic;
}

ZEND_METHOD(Ardillo_FontDescriptor, getStretch)
{
    
    ardillo_ui_FontDescriptor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontDescriptor_t, getThis());
    RETURN_LONG((zend_long)this->uis->Stretch);
}

ZEND_METHOD(Ardillo_FontDescriptor, setStretch)
{
    zend_long stretch = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(stretch)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_FontDescriptor_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_FontDescriptor_t, getThis());
    this->uis->Stretch = stretch;
}


