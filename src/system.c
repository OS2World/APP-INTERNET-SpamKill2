/* $Id: system.c,v 1.10 2003/10/05 20:53:38 relson Exp $ */

/*****************************************************************************

NAME:
   system.c -- bogofilter covers for OS/compiler dependent functions.

******************************************************************************/

#include "common.h"

#if defined(__IBMC__) || defined(__IBMCPP__) || defined(__WATCOMC__)
#define _OS2_
#include "direct.h"
const char * const system_config_file = "bogofilter.cf";
#endif

#ifdef __riscos__
/* static symbols that trigger UnixLib behaviour */
#include <unixlib/local.h> /* __RISCOSIFY_NO_PROCESS */
int __riscosify_control = __RISCOSIFY_NO_PROCESS;
int __feature_imagefs_is_file = 1;
const char *const system_config_file = "<Bogofilter$Dir>.bogofilter/cf";
#endif

bool bf_abspath(const char *path)
{
#ifndef __riscos__
    return (*path == DIRSEP_C);
#elif defined(_OS2)
    return (bool)(strchr(path, ':');
#else
    return (strchr(path, ':') || strchr(path, '$'));
#endif
}

void bf_sleep(long delay)
{
#ifndef _OS2_
    struct timeval timeval;
    timeval.tv_sec  = delay / 1000000;
    timeval.tv_usec = delay % 1000000;
    select(0,NULL,NULL,NULL,&timeval);
#else
/*APIRET DosSleep(ULONG  msec )  */
    DosSleep(1);
#endif
}

int bf_mkdir(const char *path, mode_t mode)
{
    int rc;
#ifndef _OS2_
    rc = mkdir(path, mode);
#else
    rc = mkdir((unsigned char *)path);
#endif
    return rc;
}
