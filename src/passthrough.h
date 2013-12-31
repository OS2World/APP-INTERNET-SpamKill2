/* $Id: passthrough.h,v 1.2 2003/09/22 00:08:44 relson Exp $ */

/*****************************************************************************

NAME:
   passthrough.h -- prototypes and definitions for passthrough.c

******************************************************************************/

#ifndef	PASSTHROUGH_H
#define	PASSTHROUGH_H

/* in main.c */
extern FILE *fpo;
extern void passthrough_setup(void);
extern void passthrough_cleanup(void);
extern void write_message(rc_t status);
extern void write_log_message(rc_t status);
extern void output_setup(void);

#endif	/* PASSTHROUGH_H */
