#ifndef __ARDILLO_APP_APP_H
#define __ARDILLO_APP_APP_H

#include "php.h"
#include "ui.h"

extern zend_class_entry *ce_Ardillo_App;

typedef struct _ardillo_App_t {
    HashTable *tasks;
    zend_llist stream_subscriptions;
    zend_object std;
} ardillo_App_t;

extern ardillo_App_t *ardillo_default_app;
extern ardillo_App_t *ardillo_last_app;

PHP_MINIT_FUNCTION(Ardillo_App);
void ardillo_App_stop(ardillo_App_t *app);
int ardillo_App_onShouldQuit(void *data);
void ardillo_App_onClicked(uiMenuItem *sender, uiWindow *window, void *senderData);

#endif /* __ARDILLO_APP_APP_H */
