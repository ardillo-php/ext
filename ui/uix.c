#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"

ZEND_METHOD(Ardillo_Color, __construct)
{
    double red = 0, green = 0, blue = 0, alpha = 0;

    ZEND_PARSE_PARAMETERS_START(0, 4)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(red)
        Z_PARAM_DOUBLE(green)
        Z_PARAM_DOUBLE(blue)
        Z_PARAM_DOUBLE(alpha)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    zend_update_property_double(ce_Ardillo_Color, Z_OBJ_P(getThis()), "red", sizeof("red") - 1, red);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ_P(getThis()), "green", sizeof("green") - 1, green);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ_P(getThis()), "blue", sizeof("blue") - 1, blue);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ_P(getThis()), "alpha", sizeof("alpha") - 1, alpha);
}

ZEND_METHOD(Ardillo_Color, fromRGBA)
{
    zend_long rgba = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(rgba)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    zval color;
    object_init_ex(&color, ce_Ardillo_Color);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "red", sizeof("red") - 1, ((double)((rgba >> 24) & 0xff)) / 255);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "green", sizeof("green") - 1, ((double)((rgba >> 16) & 0xff)) / 255);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "blue", sizeof("blue") - 1, ((double)((rgba >> 8) & 0xff)) / 255);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "alpha", sizeof("alpha") - 1, ((double)(rgba & 0xff)) / 255);
    RETVAL_ZVAL(&color, 0, 0);
}

ZEND_METHOD(Ardillo_Color, fromRGB)
{
    zend_long rgba = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(rgba)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    zval color;
    object_init_ex(&color, ce_Ardillo_Color);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "red", sizeof("red") - 1, ((double)((rgba >> 16) & 0xff)) / 255);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "green", sizeof("green") - 1, ((double)((rgba >> 8) & 0xff)) / 255);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ(color), "blue", sizeof("blue") - 1, ((double)(rgba & 0xff)) / 255);
    RETVAL_ZVAL(&color, 0, 0);
}

ZEND_METHOD(Ardillo_Point, __construct)
{
    double x = 0, y = 0;

    ZEND_PARSE_PARAMETERS_START(0, 2)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    zend_update_property_double(ce_Ardillo_Color, Z_OBJ_P(getThis()), "x", sizeof("x") - 1, x);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ_P(getThis()), "y", sizeof("y") - 1, y);
}

ZEND_METHOD(Ardillo_Size, __construct)
{
    double width = 0, height = 0;

    ZEND_PARSE_PARAMETERS_START(0, 2)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(width)
        Z_PARAM_DOUBLE(height)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    zend_update_property_double(ce_Ardillo_Color, Z_OBJ_P(getThis()), "width", sizeof("width") - 1, width);
    zend_update_property_double(ce_Ardillo_Color, Z_OBJ_P(getThis()), "height", sizeof("height") - 1, height);
}
