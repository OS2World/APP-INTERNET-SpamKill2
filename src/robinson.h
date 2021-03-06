/* $Id: robinson.h,v 1.7 2003/10/29 18:47:45 relson Exp $ */
/*  constants and declarations for robinson method */

#ifndef	ROBINSON_H
#define	ROBINSON_H

#include <method.h>

#define ROBS			0.010	/* Robinson's s */
#define ROBX			0.415	/* Robinson's x */

#define ROBINSON_GOOD_BIAS	1.0	/* don't give good words more weight */

#define ROBX_W			 ".ROBX"

extern	bool	first_match;
extern	bool	degen_enabled;

typedef	double	rf_get_spamicity(size_t robn, FLOAT P, FLOAT Q);
typedef	void	rf_print_summary(void);
 
/*
** This defines an object oriented API for creating a
** robinson/fisher subclass of method_t.
*/

typedef struct rf_method_s {
    method_t		m;
    rf_get_spamicity	*get_spamicity;
    rf_print_summary	*print_summary;
} rf_method_t;

/*
** Define a struct so stats can be saved for printing.
*/

typedef struct rob_stats_s {
    stats_t s;		/* basic stats */
    u_int32_t robn;
    double p_ln;	/* Robinson P, as a log*/
    double q_ln;	/* Robinson Q, as a log*/
    double p_pr;	/* Robinson P */
    double q_pr;	/* Robinson Q */
} rob_stats_t;

/* needed by fisher.c, else should be declared in robinson.c as static */
extern	double	rob_compute_spamicity(wordhash_t *wordhash, FILE *fp) /*@globals errno@*/;
extern	void	rob_print_stats(FILE *fp);
extern	void	rob_cleanup(void);

extern	rf_method_t rf_robinson_method;

/* needed by fisher.c */
extern	const	parm_desc rob_parm_table[];
extern	void    rob_initialize_with_parameters(rob_stats_t *stats, double _min_dev, double _spam_cutoff);

/* needed by degen.c */
extern double lookup_and_score(const word_t *token, wordprop_t *wordstats);

#endif	/* ROBINSON_H */
