/* $Id: textblock.h,v 1.3 2003/08/17 16:40:56 relson Exp $ */

/*****************************************************************************

NAME:
   textblock.h -- prototypes and definitions for textblock.c

******************************************************************************/

#ifndef	HAVE_TEXTBLOCK_H
#define	HAVE_TEXTBLOCK_H

typedef struct textdata_s {
    struct textdata_s *next;
    size_t             size;
    byte              *data;
} textdata_t;

typedef struct textblock_s {
    textdata_t *head;
    textdata_t *tail;
}  textblock_t;

textdata_t *textblock_head(void);
void textblock_init(void);
void textblock_free(void);

void textblock_add(const byte *text, size_t size);

#endif	/* HAVE_TEXTBLOCK_H */
