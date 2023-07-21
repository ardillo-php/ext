#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers Image_object_handlers;

zend_object* ardillo_create_Image_object(zend_class_entry *ce)
{
    ardillo_ui_Image_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Image_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Image_object_handlers, zend_get_std_object_handlers(), sizeof(Image_object_handlers));
    Image_object_handlers.offset = XtOffsetOf(ardillo_ui_Image_t, std);
    Image_object_handlers.free_obj = ardillo_free_Image_object;
    ardillo_s->std.handlers = &Image_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Image @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Image_object(zend_object *object)
{
    ardillo_ui_Image_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Image_t, object);

    ardillo_debug_objects(0, "Freeing Image @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Freeing native Image @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
    uiFreeImage(ardillo_s->uis);
    
    ardillo_debug_objects(0, "Refcount for Image @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Image @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Image, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Image_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Image_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Image, __construct)
{
    double width = 0.0;
    double height = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(width)
        Z_PARAM_DOUBLE(height)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Image_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Image_t, getThis());
    this->uis = uiNewImage(width, height);
    ardillo_debug_objects(0, "Constructing Image @%p (uis @ %p)\n", this, this->uis);
}


uint8_t doubleToUint8(double value)
{
    if (value < 0.0) {
        value = 0.0;
    } else if (value > 1.0) {
        value = 1.0;
    }

    return (uint8_t)(value * 255.0);
}

ZEND_METHOD(Ardillo_Image, append)
{
    zval *pixels = NULL;
    zval *size = NULL;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_ARRAY(pixels)
        Z_PARAM_OBJECT_OF_CLASS(size, ce_Ardillo_Size)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Image_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Image_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Image::append on invalid object");
    }

    zval *size_width, *size_height, size_rv;
    size_width = zend_read_property(ce_Ardillo_Size, Z_OBJ_P(size), "width", sizeof("width") - 1, 0, &size_rv);
    ZVAL_DEREF(size_width);
    size_height = zend_read_property(ce_Ardillo_Size, Z_OBJ_P(size), "height", sizeof("height") - 1, 0, &size_rv);
    ZVAL_DEREF(size_height);

    int stride = (int)zval_get_double(size_width) * 4;
    int count = stride * (int)zval_get_double(size_height);
    uint8_t *bytes = ecalloc(count, sizeof(uint8_t));
    zval *color;
    int i = 0;

    ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(pixels), color) {
        if ((Z_TYPE_P(color) == IS_OBJECT) && (Z_OBJCE_P(color) == ce_Ardillo_Color) && (i < count)) {
            bytes[i++] = doubleToUint8(Z_DVAL_P(zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "red", sizeof("red") - 1, 0, NULL)));
            bytes[i++] = doubleToUint8(Z_DVAL_P(zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "green", sizeof("green") - 1, 0, NULL)));
            bytes[i++] = doubleToUint8(Z_DVAL_P(zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "blue", sizeof("blue") - 1, 0, NULL)));
            bytes[i++] = doubleToUint8(Z_DVAL_P(zend_read_property(ce_Ardillo_Color, Z_OBJ_P(color), "alpha", sizeof("alpha") - 1, 0, NULL)));
        }
    } ZEND_HASH_FOREACH_END();

    uiImageAppend(this->uis, bytes, (int)zval_get_double(size_width), (int)zval_get_double(size_height), stride);

    efree(bytes);
}
