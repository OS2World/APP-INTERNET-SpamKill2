/* $Id: xmalloc.h,v 1.1 2003/02/03 16:55:15 relson Exp $ */

#ifndef XMALLOC_H
#define XMALLOC_H

/*@noreturn@*/
void xmem_error(const char *)
#ifdef __GNUC__
 __attribute__((noreturn))
#endif
   ;

/*@noreturn@*/
void xmem_toolong(const char *)
#ifdef __GNUC__
 __attribute__((noreturn))
#endif
   ;

/*@only@*/ /*@out@*/ /*@notnull@*/
void *xmalloc(size_t size);

void xfree(/*@only@*/ /*@null@*/ void *ptr);

/*@only@*/ /*@out@*/ /*@notnull@*/
void *xcalloc(size_t nmemb, size_t size);

/*@only@*/ /*@out@*/ /*@notnull@*/
void *xrealloc(/*@only@*/ void *ptr, size_t size);
#endif
