/* ardillo extension for PHP */

#ifndef PHP_ARDILLO_H
# define PHP_ARDILLO_H

extern zend_module_entry ardillo_module_entry;
# define phpext_ardillo_ptr &ardillo_module_entry

# define PHP_ARDILLO_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_ARDILLO)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_ARDILLO_H */
