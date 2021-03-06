/* $Id: graham.h,v 1.2 2003/03/04 12:17:30 m-a Exp $ */
/*  constants and declarations for graham */

#ifndef	GRAHAM_H
#define	GRAHAM_H

#include <method.h>

#define UNKNOWN_WORD		0.4	/* odds that unknown word is spammish */

#define GRAHAM_GOOD_BIAS	2.0	/* don't give good words more weight */

extern	method_t graham_method;

#endif	/* GRAHAM_H */
