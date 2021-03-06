/* $Id: fisher.h,v 1.1 2003/02/03 16:55:14 relson Exp $ */
/*  constants and declarations for robinson-fisher method */

#ifndef	FISHER_H
#define	FISHER_H

#include <robinson.h>

extern 	double prbf(double x, double df);		/* needed by rstats.c */

extern	rf_method_t rf_fisher_method;

#endif	/* FISHER_H */
