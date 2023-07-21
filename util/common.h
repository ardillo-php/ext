#ifndef __ARDILLO_UTIL_COMMON_H
#define __ARDILLO_UTIL_COMMON_H

#define ARDILLO_GET_OBJECT(ardillo_struct, obj) ((ardillo_struct *)((char *)obj - XtOffsetOf(ardillo_struct, std)))
#define ARDILLO_ZVAL_GET_OBJECT(ardillo_struct, zv) ARDILLO_GET_OBJECT(ardillo_struct, Z_OBJ_P(zv))
#define ARDILLO_ZVAL_GET_UIS(ardillo_struct, zv) (ARDILLO_ZVAL_GET_OBJECT(ardillo_struct, zv)->uis)
#define ARDILLO_ZVAL_GET_UIS_OR_NULL(ardillo_struct, zv) (zv ? (ARDILLO_ZVAL_GET_OBJECT(ardillo_struct, zv)->uis) : NULL)

#endif /* __ARDILLO_UTIL_COMMON_H */
