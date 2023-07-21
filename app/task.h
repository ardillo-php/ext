#ifndef __ARDILLO_APP_TASK_H
#define __ARDILLO_APP_TASK_H

extern zend_class_entry *ce_Ardillo_Task;

PHP_MINIT_FUNCTION(Ardillo_Task);

int runTask(zend_object *task);
void runFutureTickTask(void *data);
int runIntervalTask(void *data);

#endif /* __ARDILLO_APP_TASK_H */
