/*
  +----------------------------------------------------------------------+
  | PHP Version 5, 7                                                     |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt.                                 |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Marcin Gibula <mg@iceni.pl>                                  |
  |         Remi Collet <remi@php.net>                                   |
  +----------------------------------------------------------------------+
*/

#ifndef PHP_XATTR_H
#define PHP_XATTR_H

extern zend_module_entry xattr_module_entry;
#define phpext_xattr_ptr &xattr_module_entry

#define PHP_XATTR_VERSION "1.3.0"

#ifdef PHP_WIN32
#define PHP_XATTR_API __declspec(dllexport)
#else
#define PHP_XATTR_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(xattr);
PHP_MINFO_FUNCTION(xattr);

PHP_FUNCTION(xattr_set);
PHP_FUNCTION(xattr_get);
PHP_FUNCTION(xattr_remove);
PHP_FUNCTION(xattr_list);
PHP_FUNCTION(xattr_supported);

#if PHP_MAJOR_VERSION < 7
typedef long zend_long;
typedef int strsize_t;
#define _RETVAL_STRINGL(s,l,d) RETVAL_STRINGL(s,l,d)
#define _RETURN_STRINGL(s,l,d) RETURN_STRINGL(s,l,d)
#else
typedef size_t strsize_t;
#define _RETVAL_STRINGL(s,l,d) { RETVAL_STRINGL(s,l); if (!d) efree(s); }
#define _RETURN_STRINGL(s,l,d) { _RETVAL_STRINGL(s,l,d); return; }
#endif

#endif	/* PHP_XATTR_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
