/* $Id: word.h,v 1.8 2003/10/31 22:26:51 relson Exp $ */

/*****************************************************************************

NAME:
   word.h -- constants and declarations for word.c

AUTHOR:
   David Relson <relson@osagesoftware.com>

******************************************************************************/

#ifndef	WORD_H
#define	WORD_H

typedef struct {
    uint    leng;
    byte   *text;
} word_t;

extern word_t  *word_new(const byte *text, uint leng);
extern void 	word_free(word_t *self);
extern word_t  *word_dup(const word_t *self);
extern word_t  *word_cpy(word_t *dst, const word_t *src);
extern int 	word_cmp(const word_t *w1, const word_t *w2);
extern word_t  *word_concat(const word_t *w1, const word_t *w2);
extern void 	word_puts(const word_t *self, uint width, FILE *fp);

#endif	/* WORD_H */

