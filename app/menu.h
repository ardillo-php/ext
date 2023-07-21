#ifndef __ARDILLO_APP_MENU_H
#define __ARDILLO_APP_MENU_H

#include "php.h"

extern zend_class_entry *ce_Ardillo_Menu;

typedef struct _ardillo_Menu_t {
    void *uis;
    zend_long type;
    zend_object std;
} ardillo_Menu_t;

zend_object* ardillo_create_Menu_object(zend_class_entry *ce);
PHP_MINIT_FUNCTION(Ardillo_Menu);

#endif /* __ARDILLO_APP_MENU_H */
