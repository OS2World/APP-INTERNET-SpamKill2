/* $Id: xcalloc.c,v 1.2 2003/05/08 12:31:32 relson Exp $ */

/*
* NAME:
*    xcalloc.c -- front-end to standard heap manipulation routines, with error checking.
*
* AUTHOR:
*    Gyepi Sam <gyepi@praxis-sw.com>
*
*/

#include <stdlib.h>

#include "config.h"
#include "xmalloc.h"

#ifdef	ENABLE_MEMDEBUG
#include "memdebug.h"
#endif

void
*xcalloc(size_t nmemb, size_t size){
   void *x;
   x = calloc(nmemb, size);
   if (x == NULL && (nmemb == 0 || size == 0))
       x = calloc(1, 1);
   if (x == NULL) {
       xmem_error("xcalloc");
   }
   return x;
}
