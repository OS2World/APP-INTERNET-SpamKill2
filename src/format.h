/* $Id: format.h,v 1.9 2003/10/31 14:52:25 relson Exp $ */

#ifndef FORMAT_H
#define FORMAT_H

#include "configfile.h"

typedef const char *FIELD;

/* Global variables */

extern const char *spam_header_name;
extern const char *spam_subject_tag;

/* needed by bogoconfig.c */

extern const char *header_format;
extern const char *terse_format;
extern const char *log_update_format;
extern const char *log_header_format;
extern FIELD *spamicity_tags;
extern FIELD *spamicity_formats;

extern const parm_desc format_parms[];
extern void set_terse_mode_format(int mode);

/* Function Prototypes */

extern char *format_header(char *buff, size_t size);
extern char *format_terse(char *buff, size_t size);
extern char *format_log_header(char *buff, size_t size);
extern char *format_log_update(char *buff, size_t size, const char *reg, const char *unreg, uint wordcount, uint msgcount);
#endif
