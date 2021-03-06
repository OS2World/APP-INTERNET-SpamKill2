/* $Id: globals.c,v 1.43 2003/10/31 22:26:51 relson Exp $ */

/*****************************************************************************

NAME:
   globals.c -- define global variables

AUTHOR:
   Matthias Andree <matthias.andree@gmx.de>

******************************************************************************/

#include "system.h"
#include "globals.h"
#include "method.h"

/* exports */

/* command line options */

bool	twostate;			/* '-2' */
bool	threestate;			/* '-3' */
bulk_t	bulk_mode = B_NORMAL;		/* '-b, -B' */
bool	suppress_config_file;		/* '-C' */
bool	nonspam_exits_zero;		/* '-e' */
bool	force;				/* '-F' */
FILE	*fpin = NULL;			/* '-I' */
bool	fisher;				/* '-f' */
bool	logflag;			/* '-l' */
bool	mbox_mode;			/* '-M' */
bool	replace_nonascii_characters;	/* '-n' */
bool	passthrough;			/* '-p' */
bool	quiet;				/* '-q' */
bool	query;				/* '-Q' */
int	Rtable = 0;			/* '-R' */
bool	terse;				/* '-t' */
int	bogotest = 0;			/* '-X', env("BOGOTEST") */
int	verbose;			/* '-v' */

/* config file options */
int	max_repeats;
double	min_dev;
double	spam_cutoff;
double	thresh_stats;

const char	*update_dir;
/*@observer@*/
const char	*stats_prefix;

/* for lexer_v3.l */
bool	header_degen = false;		/* -H 	   - default: disabled */
bool	ignore_case = false;		/* -PI */
bool	header_line_markup = true;	/* -Ph */
bool	tokenize_html_tags = true;	/* -Pt */
bool	degen_enabled = false;		/* -Pd,-PD - default: disabled */
bool	first_match = true;		/* -Pf,-PF - default: enabled  */
#if	0
bool	separate_counts = true;		/* -Ps,-PS - default: enabled  */
#endif
bool	tokenize_html_script = false;	/* -Ps - not yet in use */

/* dual definition options */
method_t *method = NULL;

/* from html.c */
bool strict_check = false;

/* other */
uint	db_cachesize = 0;		/* in MB */
enum	passmode passmode;		/* internal */
bool	msg_count_file = false;
const char *progtype = NULL;
bool	no_stats  = false;		/* true if suppress rstats */

run_t run_type = RUN_UNKNOWN;
