/* $Id: xrealloc.c,v 1.3 2003/05/08 12:31:32 relson Exp $ */

/*
* NAME:
*    xrealloc.c -- front-end to standard heap manipulation routines, with error checking.
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
*xrealloc(void *ptr, size_t size){
   void *x;
   x = realloc(ptr, size);
   if (x == NULL) xmem_error("xrealloc");
   return x;
}

