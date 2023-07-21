#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers DrawMatrix_object_handlers;

zend_object* ardillo_create_DrawMatrix_object(zend_class_entry *ce)
{
    ardillo_ui_DrawMatrix_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_DrawMatrix_t) + zend_object_properties_size(ce));
    ardillo_s->uis = (uiDrawMatrix *)ecalloc(1, sizeof(uiDrawMatrix));

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&DrawMatrix_object_handlers, zend_get_std_object_handlers(), sizeof(DrawMatrix_object_handlers));
    DrawMatrix_object_handlers.offset = XtOffsetOf(ardillo_ui_DrawMatrix_t, std);
    DrawMatrix_object_handlers.free_obj = ardillo_free_DrawMatrix_object;
    ardillo_s->std.handlers = &DrawMatrix_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created DrawMatrix @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_DrawMatrix_object(zend_object *object)
{
    ardillo_ui_DrawMatrix_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_DrawMatrix_t, object);

    ardillo_debug_objects(0, "Freeing DrawMatrix @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));
    
    ardillo_debug_objects(0, "Refcount for DrawMatrix @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    if (ardillo_s->uis) {
        efree(ardillo_s->uis);
        ardillo_s->uis = NULL;
    }

    ardillo_debug_objects(0, "Done freeing DrawMatrix @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_DrawMatrix, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_DrawMatrix_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawMatrix_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_DrawMatrix, setIdentity)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_DrawMatrix_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawMatrix_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\DrawMatrix::setIdentity on invalid object");
    }
    
    uiDrawMatrixSetIdentity(this->uis);
}

ZEND_METHOD(Ardillo_DrawMatrix, translate)
{
    double x = 0.0;
    double y = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DrawMatrix_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DrawMatrix_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\DrawMatrix::translate on invalid object");
    }
    
    uiDrawMatrixTranslate(this->uis, x, y);
}


