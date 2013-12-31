/* (C) 2002 by Matthias Andree, redistributable according to the terms
 * of the GNU General Public License, v2.
 *
 * $Id: xstrdup.c,v 1.3 2003/02/17 11:32:47 m-a Exp $
 *
 * $History$
 *
 */

#include <string.h>
#include "xmalloc.h"
#include "xstrdup.h"

char *xstrdup(const char *s) {
    size_t l = strlen(s) + 1;
    char *t = xmalloc(l);
    memcpy(t, s, l);
    return t;
}
