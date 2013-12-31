/* $Id: base64.h,v 1.4 2003/10/31 15:34:52 relson Exp $ */

/*****************************************************************************

NAME:
   base64.h -- prototypes and definitions for base64.c

******************************************************************************/

#ifndef	HAVE_BASE64_H
#define	HAVE_BASE64_H

#include "word.h"

uint	base64_decode(word_t *word);
bool	base64_validate(word_t *word);

#endif	/* HAVE_BASE64_H */
