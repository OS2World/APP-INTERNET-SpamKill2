/* $Id: token.h,v 1.14 2003/10/14 20:19:38 relson Exp $ */

/*****************************************************************************

NAME:
   token.h -- prototypes and definitions for token.c

******************************************************************************/

#ifndef	HAVE_TOKEN_H
#define	HAVE_TOKEN_H

#include "lexer.h"

extern word_t *yylval;

extern token_t get_token(void);

extern void got_from(void);
extern void clr_tag(void);
extern void set_tag(const char *text);

extern void token_init(void);
extern void token_cleanup(void);

/* used by lexer_text_html.l */
extern void html_tag(int level);
extern void html_comment(int level);

#endif	/* HAVE_TOKEN_H */
