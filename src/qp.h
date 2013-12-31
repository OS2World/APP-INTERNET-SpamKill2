/* $Id: qp.h,v 1.4 2003/10/31 15:34:53 relson Exp $ */

/*****************************************************************************

NAME:
   qp.h -- prototypes and definitions for qp.c

******************************************************************************/

#ifndef	HAVE_QP_H
#define	HAVE_QP_H

#include "word.h"

uint	qp_decode(word_t *word);
bool	qp_validate(word_t *word);

#endif	/* HAVE_QP_H */
