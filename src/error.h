/* $Id: error.h,v 1.1 2003/02/03 16:55:14 relson Exp $ */

/*****************************************************************************

NAME:
   error.h -- definitions and prototypes for error.c

AUTHOR:
   David Relson <relson@osagesoftware.com>

******************************************************************************/

#ifndef ERROR_H
#define ERROR_H

extern void print_error( const char *file, unsigned long line, const char *format, ... )
#ifdef __GNUC__
    __attribute__ ((format(printf,3,4)))
#endif
    ;

#endif
