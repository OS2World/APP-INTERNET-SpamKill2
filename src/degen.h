/* $Id: degen.h,v 1.1 2003/07/29 14:37:31 relson Exp $ */

/*****************************************************************************

NAME:
   degen.h -- prototypes and definitions for degen.c

******************************************************************************/

#ifndef	HAVE_DEGEN_H
#define	HAVE_DEGEN_H

#include "word.h"

double degen(const word_t *token, wordprop_t *wordstats);

#endif	/* HAVE_DEGEN_H */
