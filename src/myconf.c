/*************************************************************************************************
 * Emulation of system calls
 *                                                      Copyright (C) 2000-2003 Mikio Hirabayashi
 * This file is part of QDBM, Quick Database Manager.
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


#include "myconf.h"



/*************************************************************************************************
 * common settings
 *************************************************************************************************/

int _qdbm_dummyfunc(void){
  return 0;
}



/*************************************************************************************************
 * for systems without mmap
 *************************************************************************************************/


#if defined(__IBMC__) || defined(__IBMCPP__) || defined(_SYS_MINGW_) || defined(_SYS_RISCOS_) || defined(MYNOMMAP)


void *_qdbm_mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset){
  char *buf, *wp;
  int rv, rlen;
  if(flags & MAP_FIXED) return MAP_FAILED;
  if(lseek(fd, SEEK_SET, offset) == -1) return MAP_FAILED;
  if(!(buf = malloc(sizeof(int) * 3 + length))) return MAP_FAILED;
  wp = buf;
  *(int *)wp = fd;
  wp += sizeof(int);
  *(int *)wp = offset;
  wp += sizeof(int);
  *(int *)wp = prot;
  wp += sizeof(int);
  rlen = 0;
  while((rv = read(fd, wp + rlen, length - rlen)) > 0){
    rlen += rv;
  }
  if(rv == -1 || rlen != length){
    free(buf);
    return MAP_FAILED;
  }
  return wp;
}


int _qdbm_munmap(void *start, size_t length){
  char *buf, *rp;
  int fd, offset, prot, rv, wlen;
  buf = (char *)start - sizeof(int) * 3;
  rp = buf;
  fd = *(int *)rp;
  rp += sizeof(int);
  offset = *(int *)rp;
  rp += sizeof(int);
  prot = *(int *)rp;
  rp += sizeof(int);
  if(prot & PROT_WRITE){
    if(lseek(fd, offset, SEEK_SET) == -1){
      free(buf);
      return -1;
    }
    wlen = 0;
    while(wlen < length){
      rv = write(fd, rp + wlen, length - wlen);
      if(rv == -1){
        if(errno == EINTR) continue;
        free(buf);
        return -1;
      }
      wlen += rv;
    }
  }
  free(buf);
  return 0;
}


int _qdbm_msync(const void *start, size_t length, int flags){
  char *buf, *rp;
  int fd, offset, prot, rv, wlen;
  buf = (char *)start - sizeof(int) * 3;
  rp = buf;
  fd = *(int *)rp;
  rp += sizeof(int);
  offset = *(int *)rp;
  rp += sizeof(int);
  prot = *(int *)rp;
  rp += sizeof(int);
  if(prot & PROT_WRITE){
    if(lseek(fd, offset, SEEK_SET) == -1) return -1;
    wlen = 0;
    while(wlen < length){
      rv = write(fd, rp + wlen, length - wlen);
      if(rv == -1){
        if(errno == EINTR) continue;
        return -1;
      }
      wlen += rv;
    }
  }
  return 0;
}


#endif



/*************************************************************************************************
 * for MinGW
 *************************************************************************************************/


#if defined(_WIN32) && !defined(__CYGWIN__)


int _qdbm_win32_fcntl(int fd, int cmd, struct flock *lock){
  HANDLE fh;
  OVERLAPPED ol;
  fh = (HANDLE)_get_osfhandle(fd);
  memset(&ol, 0, sizeof(OVERLAPPED));
  ol.Offset = 0;
  ol.OffsetHigh = 0;
  ol.hEvent = 0;
  if(!LockFileEx(fh, lock->l_type == F_WRLCK ? LOCKFILE_EXCLUSIVE_LOCK : 0, 0, 0, 1, &ol))
    return -1;
  return 0;
}


#endif

/*************************************************************************************************
 * for OS/2
 *************************************************************************************************/
#define POKA 0

#if  defined(__IBMC__) || defined(__IBMCPP__)

  #define INCL_DOSFILEMGR   /* File Manager values */
  #define INCL_DOSERRORS    /* DOS error values */
  #include <os2.h>


/*
struct flock {
  int l_type; //= F_WRLCK  0    or  F_RDLCK        1

  int l_whence; //SEEK_SET
  int l_start;  //0
  int l_len;    //0
  int l_pid;
};
*/

int _qdbm_win32_fcntl(int fd, int cmd, struct flock *lock)
{
 FILELOCK  LockArea     = {0},         /* Area of file to lock */
           UnlockArea   = {0};         /* Area of file to unlocf */
 int rc,rc0 = 0;

//   if(lock->type == F_WRLCK)
   {
     LockArea.lOffset = 0L;              /* Start locking at beginning of file */
     LockArea.lRange =  0x7fffffff;      /* Use a lock max range     */
//   }else {
//     UnlockArea.lOffset = 0L;              /* Start locking at beginning of file */
//     UnlockArea.lRange =  0x7fffffff;      /* Use a lock max range     */
   }
/*
if(cmd || (lock->l_type > 1) || lock->l_whence || lock->l_start || lock->l_len )
printf("Function %s not implemented yet\nfd=%x, cmd=%x, lock.type=%x, l_whence=%x, l_start=%x, l_len=%x, l_pid=%x",
     __FUNCTION__, fd, cmd, lock->l_type, lock->l_whence, lock->l_start, lock->l_len, lock->l_pid);
*/

    rc = DosSetFileLocks(fd,        /* File handle   */
                        &UnlockArea,       /* Unlock previous record (if any) */
                        &LockArea,         /* Lock current record */
                        2000L,             /* Lock time-out value of 2 seconds */
                        0L);               /* Exclusive lock, not atomic */
//   printf("DosSetFileLocks rc = %x, cmd=%i\n",rc, cmd);
//    fflush(stdout);
   if(rc ) rc0 = -1;
   return rc0;
}

#endif

#if POKA
 #define INCL_DOSFILEMGR       /* File Manager values */
 #define INCL_DOSERRORS        /* DOS Error values    */
 #include <os2.h>
 #include <stdio.h>
 #include <string.h>

 int main(VOID) {

 HFILE     FileHandle   = NULLHANDLE;  /* File handle */
 ULONG     Action       = 0,           /* Action taken by DosOpen */
           Wrote        = 0,           /* Number of bytes written by DosWrite */
           i            = 0;           /* Loop index */
 CHAR      FileData[40] = "Forty bytes of demonstration text data\r\n";
 APIRET    rc           = NO_ERROR;    /* Return code */
 FILELOCK  LockArea     = {0},         /* Area of file to lock */
           UnlockArea   = {0};         /* Area of file to unlock */

 rc = DosOpen("flock.dat",                   /* File to open */
              &FileHandle,                   /* File handle */
              &Action,                       /* Action taken */
              4000L,                         /* File primary allocation */
              FILE_ARCHIVED,                 /* File attributes */
              FILE_OPEN | FILE_CREATE,       /* Open function type */
              OPEN_ACCESS_READWRITE | OPEN_SHARE_DENYNONE,
              0L);                           /* No extended attributes */
 if (rc != NO_ERROR) {                       /* If open failed */
    printf("DosOpen error: return code = %u\n", rc);
    return 1;
 }
 LockArea.lOffset = 0L;              /* Start locking at beginning of file */
 LockArea.lRange =  40L;             /* Use a lock range of 40 bytes       */

          /* Write 8000 bytes to the file, 40 bytes at a time */
 for (i=0; i<200; ++i) {
   rc = DosSetFileLocks(FileHandle,        /* File handle   */
                        &UnlockArea,       /* Unlock previous record (if any) */
                        &LockArea,         /* Lock current record */
                        2000L,             /* Lock time-out value of 2 seconds */
                        0L);               /* Exclusive lock, not atomic */
   if (rc != NO_ERROR) {
      printf("DosSetFileLocks error: return code = %u\n", rc);
      return 1;
   }

   rc = DosWrite(FileHandle, FileData, sizeof(FileData), &Wrote);
   if (rc != NO_ERROR) {
      printf("DosWrite error: return code = %u\n", rc);
      return 1;
   }

    UnlockArea = LockArea;      /* Will unlock this record on next iteration */
    LockArea.lOffset += 40L;    /* Prepare to lock next record               */

 } /* endfor - 8000 bytes written */
 rc = DosClose(FileHandle);    /* Close file, this releases outstanding locks */
 /* Should check if (rc != NO_ERROR) here ... */
 return NO_ERROR;
 }

#endif


/* END OF FILE */


