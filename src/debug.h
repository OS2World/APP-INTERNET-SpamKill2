/* $Id: debug.h,v 1.8 2003/10/29 18:47:45 relson Exp $ */

/*****************************************************************************

NAME:
   debug.h -- prototypes and definitions for debug.c

******************************************************************************/

#ifndef _DEBUG_H
#define _DEBUG_H

#define	DEBUG_NONE	0

#define	MASK_BIT(uc)	( 1 << (uc - 'A'))

#ifndef	NODEBUG
#define BIT_NAMES	"bcdfghlmrstw"
#define BIT_READER	MASK_BIT('B')
#define BIT_CONFIG	MASK_BIT('C')
#define BIT_DATABASE	MASK_BIT('D')
#define BIT_FORMAT	MASK_BIT('F')
#define BIT_GENERAL	MASK_BIT('G')
#define BIT_HTML	MASK_BIT('H')
#define BIT_LEXER	MASK_BIT('L')
#define BIT_MIME	MASK_BIT('M')
#define BIT_REGISTER	MASK_BIT('R')
#define BIT_ROBINSON	MASK_BIT('R')
#define BIT_SPAMICITY	MASK_BIT('S')
#define BIT_TEXT	MASK_BIT('T')
#define BIT_WORDLIST	MASK_BIT('W')
#endif

extern FILE	 *dbgout;
extern u_int32_t  debug_mask;

#ifdef	NODEBUG
#define	DEBUG_GENERAL(level)	0
#define DEBUG_CONFIG(level)	0
#define DEBUG_DATABASE(level)	0
#define DEBUG_FORMAT(level)	0
#define DEBUG_HTML(level)	0
#define DEBUG_LEXER(level)	0
#define DEBUG_MIME(level)	0
#define DEBUG_REGISTER(level)	0
#define DEBUG_ROBINSON(level)	0
#define DEBUG_SPAMICITY(level)	0
#define DEBUG_TEXT(level)	0
#define DEBUG_WORDLIST(level)	0
#else
#define	DEBUG_GENERAL(level)	((debug_mask & BIT_GENERAL)   && (verbose > level))
#define DEBUG_CONFIG(level)	((debug_mask & BIT_CONFIG)    && (verbose > level))
#define DEBUG_DATABASE(level)	((debug_mask & BIT_DATABASE)  && (verbose > level))
#define DEBUG_FORMAT(level)	((debug_mask & BIT_FORMAT)    && (verbose > level))
#define DEBUG_HTML(level)	((debug_mask & BIT_HTML)      && (verbose > level))
#define DEBUG_LEXER(level)	((debug_mask & BIT_LEXER)     && (verbose > level))
#define DEBUG_MIME(level)	((debug_mask & BIT_MIME)      && (verbose > level))
#define DEBUG_READER(level)	((debug_mask & BIT_READER)    && (verbose > level))
#define DEBUG_REGISTER(level)	((debug_mask & BIT_REGISTER)  && (verbose > level))
#define DEBUG_ROBINSON(level)	((debug_mask & BIT_ROBINSON)  && (verbose > level))
#define DEBUG_SPAMICITY(level)	((debug_mask & BIT_SPAMICITY) && (verbose > level))
#define DEBUG_TEXT(level)	((debug_mask & BIT_TEXT)      && (verbose > level))
#define DEBUG_WORDLIST(level)	((debug_mask & BIT_WORDLIST)  && (verbose > level))
#endif

#define	BOGOTEST(uc)		((bogotest & MASK_BIT(uc)) != 0)

void set_debug_mask(const char *mask);
void set_bogotest(const char *mask);

#endif
