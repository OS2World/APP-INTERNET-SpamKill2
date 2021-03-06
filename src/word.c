/* $Id: word.c,v 1.13 2003/10/31 22:26:51 relson Exp $ */

/*****************************************************************************

NAME:
   word.c -- support for bogofilter's word struct

AUTHOR:
   David Relson <relson@osagesoftware.com>

******************************************************************************/

#include "common.h"

#include "word.h"
#include "xmalloc.h"

/* Function Definitions */

word_t *word_new(const byte *text, uint leng)
{
    /* to lessen malloc/free calls, allocate struct and data in one block */
    uint len   = (leng || !text) ? leng : (uint) strlen((const char *) text);
    word_t *self = xmalloc(sizeof(word_t)+len+D);
    self->leng = len;
    self->text = (byte *)((char *)self+sizeof(word_t));
    if (text) {
	memcpy(self->text, text, len);
	Z(self->text[len]);			/* for easier debugging - removable */
    }
    return self;
}

void word_free(word_t *self)
{
    xfree(self);
}

word_t *word_dup(const word_t *word)
{
    word_t *self = xmalloc(sizeof(word_t)+word->leng+D);
    self->leng = word->leng;
    self->text = (byte *)((char *)self+sizeof(word_t));
    if (word->text) {
	memcpy(self->text, word->text, self->leng);
	Z(self->text[self->leng]);		/* for easier debugging - removable */
    }
    return self;
}

word_t *word_cpy(word_t *dst, const word_t *src)
{
    dst->leng = src->leng;
    memcpy(dst->text, src->text, src->leng);
    Z(dst->text[dst->leng]);			/* for easier debugging - removable */
    return dst;
}

int word_cmp(const word_t *w1, const word_t *w2)
{
#if	1
    return strcmp((const char *)w1->text, (const char *)w2->text);
#else
    uint s1 = w1->leng;
    uint s2 = w2->leng;
    uint l  = min(s1, s2);
    uint i;

    for (i = 0; i < l ; i += 1) {
	int d = w1->text[i] -  w2->text[i];
	if (d != 0)
	    return d;
    }

    return s1 - s2;
#endif
}

word_t *word_concat(const word_t *w1, const word_t *w2)
{
    uint len = w1->leng + w2->leng;
    word_t *ans = word_new(NULL, len);
    memcpy(ans->text, w1->text, w1->leng);
    memcpy(ans->text+w1->leng, w2->text, w2->leng);
    Z(ans->text[ans->leng]);		/* for easier debugging - removable */
    return ans;
}

void word_puts(const word_t *self, uint width, FILE *fp)
{
    /* width = 0 - output all of the word
    **       > 0 - use 'width' as count, 
    **		   blank fill if 'width' < length
    */
    uint l = (width == 0) ? self->leng : min(width, self->leng);
    (void)fwrite(self->text, 1, l, fp);
    if (l < width)
	(void) fprintf(fp, "%*s", (int)(width - l), " ");
}
