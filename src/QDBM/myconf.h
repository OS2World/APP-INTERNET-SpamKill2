/*************************************************************************************************
 * System configurations for QDBM
 *                                                      Copyright (C) 2000-2003 Mikio Hirabayashi
 * This file is part of QDBM, Quick DataBase Manager.
 * QDBM is free software; you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation; either version 2 of the
 * License, or any later version.
 * QDBM is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with QDBM;
 * if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA.
 *************************************************************************************************/


#ifndef _MYCONF_H                        /* duplication check */
#define _MYCONF_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************
 * headers
 *************************************************************************************************/


#if defined(_WIN32) && !defined(__CYGWIN__)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <windows.h>
#include <io.h>

#elif defined(__IBMC__) || defined(__IBMCPP__)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <stdarg.h>
#include <errno.h>
#include <sys\types.h>
#include <sys\stat.h>
#include <fcntl.h>
#include <io.h>

#define S_ISDIR(mode)  (((mode) & S_IFDIR) == S_IFDIR)
#define S_ISREG(mode)  (((mode) & S_IFREG) == S_IFREG)
#define WORDS_BIGENDIAN 0  //EK

#else

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <dirent.h>

#endif



/*************************************************************************************************
 * for dosish file systems
 *************************************************************************************************/


#if defined(__CYGWIN__) || defined(_WIN32)

#undef open

#define \
open(pathname, flags, mode) \
open(pathname, flags | O_BINARY, mode)

#endif



/*************************************************************************************************
 * for systems without mmap
 *************************************************************************************************/


#if defined(_WIN32) && !defined(__CYGWIN__)

#undef PROT_EXEC
#undef PROT_READ
#undef PROT_WRITE
#undef PROT_NONE
#undef MAP_FIXED
#undef MAP_SHARED
#undef MAP_PRIVATE
#undef MAP_FAILED
#undef MS_ASYNC
#undef MS_SYNC
#undef MS_INVALIDATE
#undef mmap
#undef munmap
#undef msync

#define PROT_EXEC      (1 << 0)
#define PROT_READ      (1 << 1)
#define PROT_WRITE     (1 << 2)
#define PROT_NONE      (1 << 3)
#define MAP_FIXED      1
#define MAP_SHARED     2
#define MAP_PRIVATE    3
#define MAP_FAILED     ((void *)-1)
#define MS_ASYNC       (1 << 0)
#define MS_SYNC        (1 << 1)
#define MS_INVALIDATE  (1 << 2)

#define \
mmap(start, length, prot, flags, fd, offset) \
_qdbm_mmap(start, length, prot, flags, fd, offset)

#define \
munmap(start, length) \
_qdbm_munmap(start, length)

#define \
msync(start, length, flags) \
_qdbm_msync(start, length, flags)

void *_qdbm_mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset);
int _qdbm_munmap(void *start, size_t length);
int _qdbm_msync(const void *start, size_t length, int flags);

#endif

#if defined(__IBMC__) || defined(__IBMCPP__)
#undef PROT_EXEC
#undef PROT_READ
#undef PROT_WRITE
#undef PROT_NONE
#undef MAP_FIXED
#undef MAP_SHARED
#undef MAP_PRIVATE
#undef MAP_FAILED
#undef MS_ASYNC
#undef MS_SYNC
#undef MS_INVALIDATE
#undef mmap
#undef munmap
#undef msync

#define PROT_EXEC      (1 << 0)
#define PROT_READ      (1 << 1)
#define PROT_WRITE     (1 << 2)
#define PROT_NONE      (1 << 3)
#define MAP_FIXED      1
#define MAP_SHARED     2
#define MAP_PRIVATE    3
#define MAP_FAILED     ((void *)-1)
#define MS_ASYNC       (1 << 0)
#define MS_SYNC        (1 << 1)
#define MS_INVALIDATE  (1 << 2)

#define \
mmap(start, length, prot, flags, fd, offset) \
_qdbm_mmap(start, length, prot, flags, fd, offset)

#define \
munmap(start, length) \
_qdbm_munmap(start, length)

#define \
msync(start, length, flags) \
_qdbm_msync(start, length, flags)

void *_qdbm_mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset);
int _qdbm_munmap(void *start, size_t length);
int _qdbm_msync(const void *start, size_t length, int flags);

#endif


/*************************************************************************************************
 * for MinGW
 *************************************************************************************************/


#if defined(_WIN32) && !defined(__CYGWIN__)

#undef F_WRLCK
#undef F_RDLCK
#undef F_SETLK
#undef F_SETLKW
#undef fcntl
#undef ftruncate
#undef fsync
#undef mkdir

#define F_WRLCK        0
#define F_RDLCK        1
#define F_SETLK        0
#define F_SETLKW       0

struct flock {
  int l_type;
  int l_whence;
  int l_start;
  int l_len;
  int l_pid;
};

#define \
fcntl(fd, cmd, lock) \
_qdbm_win32_fcntl(fd, cmd, lock)

#define \
ftruncate(fd, length) \
_chsize(fd, length)

#define \
fsync(fd) \
(0)

#define \
mkdir(pathname, mode) \
mkdir(pathname)

int _qdbm_win32_fcntl(int fd, int cmd, struct flock *lock);

#endif

#if defined(__IBMC__) || defined(__IBMCPP__)

#define F_WRLCK        0
#define F_RDLCK        1
#define F_SETLK        0
#define F_SETLKW       0

struct flock {
  int l_type;
  int l_whence;
  int l_start;
  int l_len;
  int l_pid;
};

#define \
fcntl(fd, cmd, lock) \
_qdbm_win32_fcntl(fd, cmd, lock)

#define \
mkdir(pathname, mode) \
mkdir(pathname)

int _qdbm_win32_fcntl(int fd, int cmd, struct flock *lock);

#define \
ftruncate(fd, length) \
_chsize(fd, length)

#define \
fsync(fd) \
(0)

#endif


/*************************************************************************************************
 * for environments without file locking
 *************************************************************************************************/


#if defined(MYNOLOCK)

#undef fcntl

#define \
fcntl(fd, cmd, lock) \
(0)

#endif



/*************************************************************************************************
 * common settings
 *************************************************************************************************/


#ifndef _QDBM_VERSION                    /* dummy version */
#define _QDBM_VERSION  "0.0.0"
#endif

#undef TRUE
#define TRUE           1
#undef FALSE
#define FALSE          0

const char *_qdbm_copyright(void);

#ifdef __cplusplus
}
#endif


#endif                                   /* duplication check */


/* END OF FILE */
