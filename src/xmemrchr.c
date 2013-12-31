/* (C) 2003 by David Relson, redistributable according to the terms
 * of the GNU General Public License, v2.
 *
 * $Id: xmemrchr.c,v 1.1 2003/02/06 17:19:43 relson Exp $
 *
 * $History$
 *
 */

#include <string.h>
#include "xmemrchr.h"

void *xmemrchr(void *v, byte b, size_t len) {
    byte *s = v;
    byte *e = s + len;
    byte *a = NULL;
    while (s < e) {
	if (*s == b)
	    a = s;
	s += 1;
    }
    return a;
}
