#ifndef XSTRLCPY_H
#define XSTRLCPY_H
#if defined(__IBMC__) || defined(__IBMCPP__)
  #include <stddef.h>
#else
  #include <sys/types.h>
#endif
size_t xstrlcpy(char *, const char *, size_t);

#endif
