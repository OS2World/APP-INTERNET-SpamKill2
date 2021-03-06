/* $Id: xmem_error.c,v 1.1 2003/02/03 16:55:15 relson Exp $ */

#include <stdio.h>
#include <stdlib.h>

#include "xmalloc.h"

/*@noreturn@*/
void xmem_error(const char *a)
{
    (void)fprintf(stderr, "%s: Out of memory\n", a);
    abort();
}

/*@noreturn@*/
void xmem_toolong(const char *a)
{
    (void)fprintf(stderr, "%s: String too long\n", a);
    abort();
}
