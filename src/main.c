/* $Id: main.c,v 1.79 2003/11/03 00:35:47 m-a Exp $ */

/*****************************************************************************

NAME:
   main.c -- detect spam and bogons presented on standard input.

AUTHOR:
   Eric S. Raymond <esr@thyrsus.com>

CONTRIBUTORS:
   Integrate patch by Zeph Hull and Clint Adams to present spamicity in
   X-Spam-Status header in -p (passthrough) mode.

******************************************************************************/

#include "common.h"

#include <stdlib.h>

#include "bogoconfig.h"
#include "bogofilter.h"
#include "datastore.h"
#include "mime.h"
#include "passthrough.h"
#include "paths.h"
#include "token.h"
#include "wordlists.h"
#include "xmalloc.h"


extern char *optarg;// = NULL;
extern int optind;// = 1;

const char *progname = "bogofilter";

/* Function Definitions */

//int main_bogo(int argc, char **argv)
//{  return 0;
//}
//int main(int argc, char **argv) /*@globals errno,stderr,stdout@*/
int main_bogo(int argc, char **argv, int embedded) /*@globals errno,stderr,stdout@*/
{
    rc_t status;
    ex_t exitcode = EX_OK;
static start = 1;
int t0;
static int total = 0;
  optind = 0;
t0 = clock();
    progtype = build_progtype(progname, DB_TYPE);

    process_args_and_config_file(argc, argv, true);
    argc -= optind;
    argv += optind;
/* OS2
    if (logflag)
       openlog("bogofilter", LOG_PID, LOG_MAIL);
*/
    /* open all wordlists */
//if(start)
    open_wordlists((run_type == RUN_NORMAL) ? DB_READ : DB_WRITE);

if(start && embedded)
{  start = 0;
   suppress_config_file = 1;
}

    output_setup();

    status = bogofilter(argc, argv);

    switch (status) {
    case RC_SPAM:      exitcode = EX_SPAM;     break;
    case RC_HAM:       exitcode = EX_HAM;      break;
    case RC_UNSURE:    exitcode = EX_UNSURE;   break;
    case RC_OK:                exitcode = EX_OK;       break;
    default:
       fprintf(dbgout, "Unexpected status code - %d\n", status);
//       exit(EX_ERROR);
       return EX_ERROR;
    }
//printf("main_bogo done %i\n", clock()-t0); fflush(stdout);

    if (nonspam_exits_zero && exitcode != EX_ERROR)
       exitcode = EX_OK;

    close_wordlists(false);
if(start)  //should be done atexit ?
{
    free_wordlists();
}
    /* cleanup storage */
    ds_cleanup();
    mime_cleanup();
    token_cleanup();

    MEMDISPLAY;

/* OS2
    if (logflag)
       closelog();
*/
//  exit(exitcode);

//     total +=  clock()-t0;
//printf("main_bogo return %i\n", total); fflush(stdout);

    return exitcode;
}

/* End */
