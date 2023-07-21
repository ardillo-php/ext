#include "php.h"
#include "ardillo_arginfo.h"
#include "app/app.h"
#include "app/menu.h"
#include "util/debug.h"
#include "util/common.h"

zend_class_entry *ce_Ardillo_Menu;
zend_object_handlers Menu_object_handlers;

zend_object* ardillo_create_Menu_object(zend_class_entry *ce)
{
    ardillo_Menu_t *ardillo_s = ecalloc(1, sizeof(ardillo_Menu_t) + zend_object_properties_size(ce));

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    ardillo_s->std.handlers = &Menu_object_handlers;
    ardillo_s->uis = NULL;

    ardillo_debug_objects(0, "Created Menu @%p\n", ardillo_s);

    return &ardillo_s->std;
}

void ardillo_free_Menu_object(zend_object *object)
{
    ardillo_Menu_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_Menu_t, object);

    ardillo_debug_objects(0, "Freeing Menu @%p (refcount: %d)\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    ardillo_debug_objects(0, "Refcount for Menu @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing Menu @%p\n", ardillo_s);
}

PHP_MINIT_FUNCTION(Ardillo_Menu)
{
    ce_Ardillo_Menu = register_class_Ardillo_Menu();
    ce_Ardillo_Menu->create_object = ardillo_create_Menu_object;

    memcpy(&Menu_object_handlers, zend_get_std_object_handlers(), sizeof(Menu_object_handlers));
    Menu_object_handlers.offset = XtOffsetOf(ardillo_Menu_t, std);
    Menu_object_handlers.free_obj = ardillo_free_Menu_object;

    return SUCCESS;
}
