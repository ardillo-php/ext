#include "php.h"
#include "ardillo_arginfo.h"
#include "app/app.h"
#include "app/task.h"
#include "util/common.h"
#include "util/debug.h"

zend_class_entry *ce_Ardillo_Task;

PHP_MINIT_FUNCTION(Ardillo_Task)
{
    ce_Ardillo_Task = register_class_Ardillo_Task();

    return SUCCESS;
}

ZEND_METHOD(Ardillo_Task, onExecute)
{
}

void removeTask(zend_object *task)
{
    zend_string *key;
    zval *zv;
    zend_ulong idx;

    ZEND_HASH_FOREACH_KEY_VAL_IND(ardillo_default_app->tasks, idx, key, zv) {
        if (task == Z_OBJ_P(zv)) {
            ardillo_debug_references(0, "Removing task @%p refcount: %d\n", Z_OBJ_P(zv), GC_REFCOUNT(Z_OBJ_P(zv)));
            zend_hash_index_del(ardillo_default_app->tasks, idx);
            return;
        }
    } ZEND_HASH_FOREACH_END();
}

int runTask(zend_object *task)
{
    int ret = 0;
    zval *prop, rv;

    prop = zend_read_property(ce_Ardillo_Task, task, "suspended", sizeof("suspended") - 1, 0, &rv);
    ZVAL_DEREF(prop);

    if (!zend_is_true(prop)) {
        zval retval;
        zend_string *method = zend_string_init("onExecute", strlen("onExecute"), 0);

        int successful = zend_call_method_if_exists(task, method, &retval, 0, NULL);
        zend_string_release(method);
        zval_ptr_dtor(&retval);

        prop = zend_read_property(ce_Ardillo_Task, task, "suspended", sizeof("suspended") - 1, 0, &rv);
        ZVAL_DEREF(prop);

        ret = !zend_is_true(prop);

        if (successful != SUCCESS) {
            ret = 0;
        }

        if (EG(exception)) {
            zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\Task::onExecute");
            ret = 0;
        }
    }

    if (!ret && ardillo_default_app) {
       removeTask(task);
    }

    return ret;
}

void runFutureTickTask(void *data)
{
    zend_object *task = (zend_object *)data;

    if (runTask(task) && ardillo_default_app) {
        removeTask(task);
    }
}

int runIntervalTask(void *data)
{
    zend_object *task = (zend_object *)data;

    return runTask(task);
}
