#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"


zend_object_handlers TableValueImage_object_handlers;

zend_object* ardillo_create_TableValueImage_object(zend_class_entry *ce)
{
    ardillo_ui_TableValueImage_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_TableValueImage_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&TableValueImage_object_handlers, zend_get_std_object_handlers(), sizeof(TableValueImage_object_handlers));
    TableValueImage_object_handlers.offset = XtOffsetOf(ardillo_ui_TableValueImage_t, std);
    TableValueImage_object_handlers.free_obj = ardillo_free_TableValueImage_object;
    ardillo_s->std.handlers = &TableValueImage_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created TableValueImage @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_TableValueImage_object(zend_object *object)
{
    ardillo_ui_TableValueImage_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_TableValueImage_t, object);

    ardillo_debug_objects(0, "Freeing TableValueImage @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));
    
    ardillo_debug_objects(0, "Refcount for TableValueImage @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing TableValueImage @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_TableValueImage, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_TableValueImage_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableValueImage_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_TableValueImage, __construct)
{
    zval *img = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(img, ce_Ardillo_Image)
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_TableValueImage_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableValueImage_t, getThis());
    this->uis = uiNewTableValueImage(ARDILLO_ZVAL_GET_UIS(ardillo_ui_Image_t, img));
    ardillo_debug_objects(0, "Constructing TableValueImage @%p (uis @ %p)\n", this, this->uis);
}


ZEND_METHOD(Ardillo_TableValueImage, get)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_TableValueImage_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_TableValueImage_t, getThis());

    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\TableValueImage::get on invalid object");
    }

    zend_object *obj = ardillo_create_Image_object(ce_Ardillo_Image);
    ARDILLO_GET_OBJECT(ardillo_ui_Image_t, obj)->uis = uiTableValueImage(this->uis);

    zval ret;
    ZVAL_OBJ(&ret, obj);
    RETVAL_ZVAL(&ret, 0, 0);
}
