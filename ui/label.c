#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers Label_object_handlers;

zend_object* ardillo_create_Label_object(zend_class_entry *ce)
{
    ardillo_ui_Label_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_Label_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&Label_object_handlers, zend_get_std_object_handlers(), sizeof(Label_object_handlers));
    Label_object_handlers.offset = XtOffsetOf(ardillo_ui_Label_t, std);
    Label_object_handlers.free_obj = ardillo_free_Label_object;
    ardillo_s->std.handlers = &Label_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created Label @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_Label_object(zend_object *object)
{
    ardillo_ui_Label_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_Label_t, object);

    ardillo_debug_objects(0, "Freeing Label @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native Label @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }
    
    ardillo_debug_objects(0, "Refcount for Label @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Label @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_Label, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Label_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Label_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_Label, __construct)
{
    zend_string *text = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Label_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Label_t, getThis());
    this->uis = uiNewLabel(ZSTR_VAL(text));
    ardillo_debug_objects(0, "Constructing Label @%p (uis @ %p)\n", this, this->uis);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_Label, getText)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_Label_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Label_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Label::getText on invalid object");
    }
    
    char *ret = (char *)uiLabelText(this->uis);

    RETVAL_STRING(ret);
    uiFreeText(ret);
}

ZEND_METHOD(Ardillo_Label, setText)
{
    zend_string *text = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_Label_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_Label_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\Label::setText on invalid object");
    }
    
    uiLabelSetText(this->uis, ZSTR_VAL(text));
}


