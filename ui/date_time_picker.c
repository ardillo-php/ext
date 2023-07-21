#include "php.h"
#include "Zend/zend_API.h"
#include "ui.h"
#include "ui/types.h"
#include "app/app.h"
#include "util/common.h"
#include "util/debug.h"

void ardillo_call_DateTimePicker_onChanged(uiDateTimePicker *uis, void *this)
{
    zval retval;
    zend_string *method = zend_string_init("onChanged", strlen("onChanged"), 0);

    int successful = zend_call_method_if_exists(&((ardillo_ui_DateTimePicker_t *)this)->std, method, &retval, 0, NULL);
    zend_string_release(method);
    
    zval_ptr_dtor(&retval);

    if (successful != SUCCESS) {
        return;
    }

    if (EG(exception)) {
        zend_error(E_CORE_ERROR, "Uncaught exception in Ardillo\\DateTimePicker::onChanged");
        return;
    }

    return;
}


zend_object_handlers DateTimePicker_object_handlers;

zend_object* ardillo_create_DateTimePicker_object(zend_class_entry *ce)
{
    ardillo_ui_DateTimePicker_t *ardillo_s = ecalloc(1, sizeof(ardillo_ui_DateTimePicker_t) + zend_object_properties_size(ce));
    ardillo_s->uis = NULL;

    zend_object_std_init(&ardillo_s->std, ce);
    object_properties_init(&ardillo_s->std, ce);

    memcpy(&DateTimePicker_object_handlers, zend_get_std_object_handlers(), sizeof(DateTimePicker_object_handlers));
    DateTimePicker_object_handlers.offset = XtOffsetOf(ardillo_ui_DateTimePicker_t, std);
    DateTimePicker_object_handlers.free_obj = ardillo_free_DateTimePicker_object;
    ardillo_s->std.handlers = &DateTimePicker_object_handlers;

    zval app;
    ZVAL_OBJ(&app, &ardillo_default_app->std);
    zend_update_property(ce, &ardillo_s->std, "app", sizeof("app") - 1, &app);

    ardillo_debug_objects(0, "Created DateTimePicker @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);

    return &ardillo_s->std;
}

void ardillo_free_DateTimePicker_object(zend_object *object)
{
    ardillo_ui_DateTimePicker_t *ardillo_s = ARDILLO_GET_OBJECT(ardillo_ui_DateTimePicker_t, object);

    ardillo_debug_objects(0, "Freeing DateTimePicker @%p (uis @%p, refcount: %d)\n", ardillo_s, ardillo_s->uis, GC_REFCOUNT(&ardillo_s->std));

    if (ardillo_s->uis) {
        ardillo_debug_objects(0, "Hiding native DateTimePicker @%p (uis @%p, object @%p)\n", ardillo_s, ardillo_s->uis, &ardillo_s->std);
        uiControlHide(uiControl(ardillo_s->uis));
    }
    
    ardillo_debug_objects(0, "Refcount for DateTimePicker @%p before dtor: %d\n", ardillo_s, GC_REFCOUNT(&ardillo_s->std));

    zend_object_std_dtor(&ardillo_s->std);

    ardillo_debug_objects(0, "Done freeing DateTimePicker @%p\n", ardillo_s);
}

ZEND_METHOD(Ardillo_DateTimePicker, isValid)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_DateTimePicker_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DateTimePicker_t, getThis());

    RETURN_BOOL(this->uis != NULL);
}

ZEND_METHOD(Ardillo_DateTimePicker, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_DateTimePicker_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DateTimePicker_t, getThis());
    this->uis = uiNewDateTimePicker();
    ardillo_debug_objects(0, "Constructing DateTimePicker @%p (uis @ %p)\n", this, this->uis);
    uiDateTimePickerOnChanged(this->uis, ardillo_call_DateTimePicker_onChanged, this);
    uiControlOnFree(uiControl(this->uis), ardillo_call_Control_onFree, this);
}

ZEND_METHOD(Ardillo_DateTimePicker, getTime)
{
    struct tm time;

    ZEND_PARSE_PARAMETERS_NONE();

    ardillo_ui_DateTimePicker_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DateTimePicker_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\DateTimePicker::getTime on invalid object");
    }
    
    uiDateTimePickerTime(this->uis, &time);

    zval ret;
    char *str;
    size_t str_len;
    
    str_len = spprintf(
        &str, 0, "%04d-%02d-%02d %02d:%02d:%02d",
        time.tm_year + 1900, time.tm_mon + 1, time.tm_mday,
        time.tm_hour, time.tm_min, time.tm_sec
    );
    
    php_date_instantiate(php_date_get_immutable_ce(), &ret);
    php_date_initialize(Z_PHPDATE_P(&ret), str, str_len, "Y-m-d H:i:s", NULL, PHP_DATE_INIT_FORMAT);
    efree(str);
    
    RETVAL_ZVAL(&ret, 0, 0);
}

ZEND_METHOD(Ardillo_DateTimePicker, setTime)
{
    zval *time = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(time, php_date_get_interface_ce())
    ZEND_PARSE_PARAMETERS_END_EX(RETURN_THROWS());

    ardillo_ui_DateTimePicker_t *this = ARDILLO_ZVAL_GET_OBJECT(ardillo_ui_DateTimePicker_t, getThis());
    
    if (!this->uis) {
        zend_error(E_CORE_ERROR, "Cannot invoke Ardillo\\DateTimePicker::setTime on invalid object");
    }
    
    struct tm tm_time = {0};
    php_date_obj *time_dt = php_date_obj_from_obj(Z_OBJ_P(time));
    tm_time.tm_year = time_dt->time->y - 1900;
    tm_time.tm_mon = time_dt->time->m - 1;
    tm_time.tm_mday = time_dt->time->d;
    tm_time.tm_hour = time_dt->time->h;
    tm_time.tm_min = time_dt->time->i;
    tm_time.tm_sec = time_dt->time->s;
    tm_time.tm_isdst = time_dt->time->dst;

    uiDateTimePickerSetTime(this->uis, &tm_time);
}

ZEND_METHOD(Ardillo_DateTimePicker, onChanged)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_NULL();
}


