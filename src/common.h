/* $Id: common.h,v 1.38 2003/11/01 15:11:13 m-a Exp $ */

/*****************************************************************************

NAME:
   common.h -- common definitions and prototypes for bogofilter

******************************************************************************/

#ifndef COMMON_H
#define COMMON_H

#include "config.h"

#if defined(HAVE_LIMITS_H)
  #include <limits.h>
#elif defined(HAVE_SYS_PARAM_H)
  #include <sys/param.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#ifdef HAVE_SYSLOG_H
#include <syslog.h>
#endif

#include "system.h"	/* defines bool, uint32_t */
#include "debug.h"

#ifdef	ENABLE_MEMDEBUG
#include "memdebug.h"
#else
#define	MEMDISPLAY
#endif

typedef uint32_t YYYYMMDD;	/* date as YYYYMMDD */

/* for easier debugging - can be disabled */
#if	0
#define	D		/* size adjustment */
#define	Z(n)		/* mark end of string */
#else
#define	D	1	/* size adjustment */
#define	Z(n) n=(byte)'\0' /* mark end of string */
#endif

/* length of token will not exceed this... */
#define MAXTOKENLEN	30

typedef enum sh_e { IX_SPAM = 0, 	/* index for SPAM */
		    IX_GOOD = 1, 	/* index for GOOD */
		    IX_SIZE = 2, 	/* array size     */
		    IX_UNDF = 3 	/* ... undefined  */
} sh_t;

#ifndef max
 #define max(x, y)	(((x) > (y)) ? (x) : (y))
#endif
#ifndef min
 #define min(x, y)	(((x) < (y)) ? (x) : (y))
#endif

#define	NL	"\n"
#define	CRLF	"\r\n"

#if defined(PATH_MAX)
#define PATH_LEN PATH_MAX
#elif defined(MAXPATHLEN)
#define PATH_LEN MAXPATHLEN
#else
#define PATH_LEN 1024
#endif


#define COUNTOF(array)	(uint) (sizeof(array)/sizeof(array[0]))

typedef unsigned char byte;

enum dbmode_e { DB_READ = 0, DB_WRITE = 1 };
typedef enum dbmode_e dbmode_t;

#define BIT(n)	(1 << n)

typedef enum rc_e { RC_SPAM	= 0,
		    RC_HAM	= 1,
		    RC_UNSURE	= 2,
		    RC_OK,
		    RC_MORE	}  rc_t;

typedef enum ex_e { EX_SPAM	= RC_SPAM,
		    EX_HAM	= RC_HAM,
		    EX_UNSURE	= RC_UNSURE,
		    EX_OK	= 0,
		    EX_ERROR	= 3 } ex_t;

typedef enum run_e {
    RUN_UNKNOWN= 0,
    RUN_NORMAL = BIT(0),
    RUN_UPDATE = BIT(1),
    REG_SPAM   = BIT(2),
    REG_GOOD   = BIT(3),
    UNREG_SPAM = BIT(4),
    UNREG_GOOD = BIT(5)
} run_t;
extern run_t run_type;
extern bool  run_classify;
extern bool  run_register;

typedef struct {
    double mant;
    int    exp;
} FLOAT;

typedef enum priority_e {
    PR_NONE,		/* 0 */
    PR_ENV_HOME,	/* 1 */
    PR_CFG_SITE,	/* 2 */
    PR_CFG_USER,	/* 3 */
    PR_CFG_UPDATE,	/* 4 */
    PR_ENV_BOGO,	/* 5 */
    PR_COMMAND		/* 6 */
} priority_t;

typedef enum bulk_e {
    B_NORMAL,
    B_CMDLINE,
    B_STDIN
} bulk_t;

typedef enum wl_e { WL_M_UNKNOWN ='U',
		    WL_M_SEPARATE='S',
		    WL_M_COMBINED='C' } wl_t;

#include "globals.h"

/* Represents the secondary data for a word key */
typedef struct {
    int freq;
    u_int32_t	good;
    u_int32_t	bad;
    double prob;
} wordprop_t;

extern void bf_abort(void);
extern void bf_exit(void);

#define internal_error do { fprintf(stderr, "Internal error in %s:%u\n", __FILE__, __LINE__); abort(); } while(0)

#endif
