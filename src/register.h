/* register.h -- constants and declarations for register.c */
/* $Id: register.h,v 1.6 2003/10/29 18:47:45 relson Exp $ */

#ifndef	REGISTER_H
#define	REGISTER_H

#include "wordhash.h"

extern void register_words(run_t _run_type, wordhash_t *h, u_int32_t msgcount);

#endif	/* REGISTER_H */
