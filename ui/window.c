#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

int ardillo_call_Window_onClosing(uiWindow *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onClosing", strlen("onClosing"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_Window_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);
    int ret = Z_LVAL(retval);
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return 0;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Window::onClosing");
        return 0;
    }

    if (ret) {
        ((ardillo_ui_Window_t *)this)->uis = NULL;
    }

    return ret;
}

void ardillo_call_Window_onContentSizeChanged(uiWindow *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onContentSizeChanged", strlen("onContentSizeChanged"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_Window_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);

    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Window::onContentSizeChanged");
        return;
    }

    return;
}

void ardillo_call_Window_onFocusChanged(uiWindow *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onFocusChanged", strlen("onFocusChanged"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_Window_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);

    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Window::onFocusChanged");
        return;
    }

    return;
}

void ardillo_call_Window_onPositionChanged(uiWindow *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onPositionChanged", strlen("onPositionChanged"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_Window_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);

    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Window::onPositionChanged");
        return;
    }

    return;
}

zend_object_handlers Window_object_handlers;

zend_object* ardillo_create_Window_object(zend_class_entry *ce)
{
    ardillo_ui_Window_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Window_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Window_object_handlers, zend_get_std_object_handlers(), sizeof(Window_object_handlers));
    Window_object_handlers.offset = XtOffsetOf(ardillo_ui_Window_t, std);
    Window_object_handlers.free_obj = ardillo_free_Window_object;
    ardillo_s->std.handlers = &Window_object_handlers;

    if (!ardillo_default_app) {
        zend_error(E_CORE_ERROR, "Cannot instantiate Ardillo\\Window outside of an Application context");
        return NULL;
    }

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Window @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Window_object(zend_object *object)
{
    ardillo_ui_Window_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Window_t, object);

    ardillo_debug_objects(0, "Freeing Window @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Destroying native Window @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlDestroy(uiControl(ardillo_s->uis));
    }

    ardillo_debug_objects(0, "Refcount for Window @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Window @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Window, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Window, __construct)
{
    zend_string *title = NULL;
    zval *size = NULL;
    bool hasMenubar = 0;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_STR(title)
        Z_PARAM_OBJECT_OF_CLASS(size, ce_Ardillo_Size)
        Z_PARAM_BOOL(hasMenubar)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    zval *size_width, *size_height, size_rv;
    size_width = zend_read_property(ce_Ardillo_Size, Z_OBJ_P(size), "width", sizeof("width") - 1, 0, &size_rv);
    ZVAL_DEREF(size_width);
    size_height = zend_read_property(ce_Ardillo_Size, Z_OBJ_P(size), "height", sizeof("height") - 1, 0, &size_rv);
    ZVAL_DEREF(size_height);

    this->uis = uiNewWindow(ZSTR_VAL(title), (int)zval_get_double(size_width), (int)zval_get_double(size_height), (int)hasMenubar);
    ardillo_debug_objects(0, "Constructing Window @%p (uis @ %p)\n", this, this->uis);
    uiWindowOnClosing(this->uis, ardillo_call_Window_onClosing, this);
    uiWindowOnContentSizeChanged(this->uis, ardillo_call_Window_onContentSizeChanged, this);
    uiWindowOnFocusChanged(this->uis, ardillo_call_Window_onFocusChanged, this);
    uiWindowOnPositionChanged(this->uis, ardillo_call_Window_onPositionChanged, this);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_Window, getBorderless)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::getBorderless on invalid object");
    }

    int ret = uiWindowBorderless(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Window, setBorderless)
{
    zend_long borderless = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(borderless)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::setBorderless on invalid object");
    }

    uiWindowSetBorderless(this->uis, (int)borderless);
}

ZEND_METHOD(Ardillo_Window, getContentSize)
{
    int size_width = 0, size_height = 0;

    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::getContentSize on invalid object");
    }

    uiWindowContentSize(this->uis, &size_width, &size_height);

    zval size;
    object_init_ex(&size, ce_Ardillo_Size);
    zend_update_property_double(ce_Ardillo_Size, Z_OBJ(size), "width", sizeof("width") - 1, size_width);
    zend_update_property_double(ce_Ardillo_Size, Z_OBJ(size), "height", sizeof("height") - 1, size_height);
    RETVAL_ZVAL(&size, 0, 0);
}

ZEND_METHOD(Ardillo_Window, setContentSize)
{
    zval *size = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(size, ce_Ardillo_Size)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::setContentSize on invalid object");
    }

    zval *size_width, *size_height, size_rv;
    size_width = zend_read_property(ce_Ardillo_Size, Z_OBJ_P(size), "width", sizeof("width") - 1, 0, &size_rv);
    ZVAL_DEREF(size_width);
    size_height = zend_read_property(ce_Ardillo_Size, Z_OBJ_P(size), "height", sizeof("height") - 1, 0, &size_rv);
    ZVAL_DEREF(size_height);

    uiWindowSetContentSize(this->uis, (int)zval_get_double(size_width), (int)zval_get_double(size_height));
}

ZEND_METHOD(Ardillo_Window, getFullscreen)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::getFullscreen on invalid object");
    }

    int ret = uiWindowFullscreen(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Window, setFullscreen)
{
    zend_long fullscreen = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(fullscreen)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::setFullscreen on invalid object");
    }

    uiWindowSetFullscreen(this->uis, (int)fullscreen);
}

ZEND_METHOD(Ardillo_Window, getMargined)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::getMargined on invalid object");
    }

    int ret = uiWindowMargined(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Window, setMargined)
{
    bool margined = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(margined)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::setMargined on invalid object");
    }

    uiWindowSetMargined(this->uis, (int)margined);
}

ZEND_METHOD(Ardillo_Window, getPosition)
{
    int coord_x = 0, coord_y = 0;

    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::getPosition on invalid object");
    }

    uiWindowPosition(this->uis, &coord_x, &coord_y);

    zval coord;
    object_init_ex(&coord, ce_Ardillo_Point);
    zend_update_property_double(ce_Ardillo_Point, Z_OBJ(coord), "x", sizeof("x") - 1, coord_x);
    zend_update_property_double(ce_Ardillo_Point, Z_OBJ(coord), "y", sizeof("y") - 1, coord_y);
    RETVAL_ZVAL(&coord, 0, 0);
}

ZEND_METHOD(Ardillo_Window, setPosition)
{
    zval *pos = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(pos, ce_Ardillo_Point)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::setPosition on invalid object");
    }

    zval *pos_x, *pos_y, pos_rv;
    pos_x = zend_read_property(ce_Ardillo_Point, Z_OBJ_P(pos), "x", sizeof("x") - 1, 0, &pos_rv);
    ZVAL_DEREF(pos_x);
    pos_y = zend_read_property(ce_Ardillo_Point, Z_OBJ_P(pos), "y", sizeof("y") - 1, 0, &pos_rv);
    ZVAL_DEREF(pos_y);

    uiWindowSetPosition(this->uis, (int)zval_get_double(pos_x), (int)zval_get_double(pos_y));
}

ZEND_METHOD(Ardillo_Window, getResizeable)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::getResizeable on invalid object");
    }

    int ret = uiWindowResizeable(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Window, setResizeable)
{
    bool resizeable = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(resizeable)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::setResizeable on invalid object");
    }

    uiWindowSetResizeable(this->uis, (int)resizeable);
}

ZEND_METHOD(Ardillo_Window, getTitle)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::getTitle on invalid object");
    }

    char *ret = (char *)uiWindowTitle(this->uis);

    RETVAL_STRING(ret);
    uiFreeText(ret);
}

ZEND_METHOD(Ardillo_Window, setTitle)
{
    zend_string *title = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(title)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::setTitle on invalid object");
    }

    uiWindowSetTitle(this->uis, ZSTR_VAL(title));
}

ZEND_METHOD(Ardillo_Window, onClosing)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(0);
}

ZEND_METHOD(Ardillo_Window, onContentSizeChanged)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}

ZEND_METHOD(Ardillo_Window, onFocusChanged)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}

ZEND_METHOD(Ardillo_Window, onPositionChanged)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}

ZEND_METHOD(Ardillo_Window, isFocused)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::focused on invalid object");
    }

    int ret = uiWindowFocused(this->uis);

    RETURN_BOOL(ret);
}

ZEND_METHOD(Ardillo_Window, setChild)
{
    zval *child = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(child, ce_Ardillo_Control)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::setChild on invalid object");
    }

    uiWindowSetChild(this->uis, ARDILLO_ZVAL_GET_UIS(ardillo_ui_Control_t, child));
}

ZEND_METHOD(Ardillo_Window, messageBox)
{
    zend_long type = 0;
    zend_string *title = NULL;
    zend_string *content = NULL;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_LONG(type)
        Z_PARAM_STR(title)
        Z_PARAM_STR(content)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::messageBox on invalid object");
    }

    switch (type) {
        case 1:
            uiMsgBoxError(this->uis, ZSTR_VAL(title), ZSTR_VAL(content));
            break;

        default:
            uiMsgBox(this->uis, ZSTR_VAL(title), ZSTR_VAL(content));
            break;
    }
}

ZEND_METHOD(Ardillo_Window, openFolder)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::openFolder on invalid object");
    }

    char *ret = (char *)uiOpenFolder(this->uis);

    if (!ret) {
        RETURN_NULL();
    }

    RETVAL_STRING(ret);
    uiFreeText(ret);
}

ZEND_METHOD(Ardillo_Window, openFile)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::openFile on invalid object");
    }

    char *ret = (char *)uiOpenFile(this->uis);

    if (!ret) {
        RETURN_NULL();
    }

    RETVAL_STRING(ret);
    uiFreeText(ret);
}

ZEND_METHOD(Ardillo_Window, saveFile)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Window_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Window_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Window::saveFile on invalid object");
    }

    char *ret = (char *)uiSaveFile(this->uis);

    if (!ret) {
        RETURN_NULL();
    }

    RETVAL_STRING(ret);
    uiFreeText(ret);
}
