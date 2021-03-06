/* $Id: collect.c,v 1.21 2003/10/09 00:45:27 relson Exp $ */

/* collect.c -- tokenize input and cap word frequencies, return a wordhash */

#include "common.h"

#include <stdlib.h>

#include "charset.h"
#include "mime.h"
#include "wordhash.h"
#include "token.h"

#include "collect.h"

static void initialize(void)
{
    mime_reset();
    token_init();
    lexer_v3_init(NULL);
    init_charset_table(charset_default, true);
}

/* this is referenced by register.c, must not be static */
void wordprop_init(void *vwordprop)
{
    wordprop_t *wordprop = vwordprop;
    memset(wordprop, 0, sizeof(*wordprop));
}

/* this is used by robinson.c static */
void wordprop_incr(wordprop_t *w1, wordprop_t *w2)
{
    w1->good += w2->good;
    w1->bad += w2->bad;
}

/* Tokenize input text and save words in the wordhash_t hash table.
 *
 * Returns:  true if the EOF token has not been read.
 */
void collect_words(wordhash_t *wh)
{
    if (DEBUG_WORDLIST(2)) fprintf(dbgout, "### collect_words() begins\n");

    initialize();

    for (;;){
	wordprop_t *w;
	word_t *token;
	token_t cls = get_token();

	if (cls == NONE)
	    break;

	token = yylval;

	if (cls == BOGO_LEX_LINE)
	{
	    char *s = (char *)(yylval->text+1);
	    char *f = strchr(s, '"');
	    token->text = (unsigned char *) s;
	    token->leng = f - s;
	}

	w = wordhash_insert(wh, token, sizeof(wordprop_t), &wordprop_init);
	if (w->freq < max_repeats) w->freq++;
	wh->wordcount += 1;
	if (DEBUG_WORDLIST(3)) { 
	    fprintf(dbgout, "%3d ", (int) wh->wordcount);
	    word_puts(token, 0, dbgout);
	    fputc('\n', dbgout);
	}

	if (cls == BOGO_LEX_LINE)
	{
	    char *s = (char *)yylval->text;
	    s += yylval->leng + 2;
	    w->bad = atoi(s);
	    s = strchr(s+1, ' ') + 1;
	    w->good = atoi(s);
	}
    }

    if (DEBUG_WORDLIST(2)) fprintf(dbgout, "### collect_words() ends\n");

    return;
}
