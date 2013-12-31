/* $Id: xmalloc.c,v 1.4 2003/08/09 21:11:38 relson Exp $ */

/*
* NAME:
*    xmalloc.c -- front-end to standard heap manipulation routines, with error checking.
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

void *
xmalloc(size_t size){
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL && size == 0)
	ptr = malloc(1);
    if (ptr == NULL) {
	xmem_error("xmalloc"); 
    }
    return ptr;
}

void
xfree(void *ptr){
    if (ptr)
	free(ptr);
}

