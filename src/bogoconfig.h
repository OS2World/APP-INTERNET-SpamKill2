/* $Id: bogoconfig.h,v 1.10 2003/08/16 11:50:06 relson Exp $ */

/*****************************************************************************

NAME:
   bogoconfig.h -- prototypes and definitions for bogoconfig.c.

AUTHOR:
   David Relson <relson@osagesoftware.com>

******************************************************************************/

#ifndef BOGOCONFIG_H
#define BOGOCONFIG_H

/* Global variables */

extern const char *logtag;
extern const char *spam_header_name;
extern const char *user_config_file;

extern void query_config(void);
extern void process_args_and_config_file(int argc, char **argv, bool warn_on_error);

#endif
