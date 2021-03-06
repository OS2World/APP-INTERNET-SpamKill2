/* $Id: maint.h,v 1.4 2003/10/02 11:29:46 relson Exp $ */

#ifndef MAINT_H
#define MAINT_H

#include <time.h>

#define	AGE_IS_YDAY
#undef	AGE_IS_YDAY
#undef	AGE_IS_YYYYMMDD
#define	AGE_IS_YYYYMMDD

extern	uint32_t thresh_count;
extern	YYYYMMDD thresh_date;
extern	size_t   size_min, size_max;
extern	bool     timestamp_tokens;
extern	bool     replace_nonascii_characters;

/* Function Prototypes */
void maintain_wordlists(void);
int  maintain_wordlist_file(const char *db_file);

bool keep_date(YYYYMMDD dat);
bool keep_count(uint32_t cnt);
bool keep_size(size_t siz);
bool do_replace_nonascii_characters(byte *, size_t);

void set_today(void);
void set_date(YYYYMMDD date);
time_t long_to_date(long l);
YYYYMMDD string_to_date(const char *s);

#endif	/* MAINT_H */
