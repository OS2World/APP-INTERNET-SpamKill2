/* config.h */
/* config for OS2 & VAC3 */
#ifndef BO_CONFIG
#define BO_CONFIG

#define PACKAGE "BFilter"
#define ENABLE_ROBINSON_FISHER
#define SPAM_HEADER_NAME	"X-Bogosity"

#define SIZEOF_INT	4
#define SIZEOF_SHORT	2
#define HAVE_STRCHR     1
#define STDC_HEADERS    1
#define HAVE_SYS_TYPES_H	1
#define HAVE_SYS_STAT_H		1
#define HAVE_FCNTL_H		1
#define HAVE_LIMITS_H		1
#define HAVE_STDARG_H 		1
#define HAVE_FLOAT_H		1

#define TIME_WITH_SYS_TIME	1
#define DB_TYPE		"db"
#define DB_EXT		".db"
#define strncasecmp(x,y,z) strnicmp(x,y,z)
#define strcasecmp(x,y) stricmp(x,y)

#define S_ISDIR(mode)  (((mode) & S_IFDIR) == S_IFDIR)
#define S_ISREG(mode)  (((mode) & S_IFREG) == S_IFREG)
#define S_IRUSR 0
#define S_IXUSR 0
#define S_IWUSR 0

#define xisspace(x) isspace((unsigned char)x)
#define xtoupper(x) toupper((unsigned char)x)
#define xtolower(x) tolower((unsigned char)x)
#define xisdigit(x) isdigit((unsigned char)x)
#define xisascii(x) isascii((unsigned char)x)
#define xislower(x) islower((unsigned char)x)
#define xisalpha(x) isalpha((unsigned char)x)

#define mode_t  int

#if defined(__IBMC__)
  #ifndef inline 
     #define inline  _Inline
  #endif   
#endif

#define GSL_COERCE_DBL(x) (x)

#endif 
//BO_CONFIG