/*************************************************************************************************
 * Implementation of Depot
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


#include "depot.h"
#include "myconf.h"

#define DP_FILEMODE    00644
#define DP_MAGICNUMB   "[DEPOT]\n\f"
#define DP_MAGICNUML   "[depot]\n\f"
#define DP_HEADSIZ     48
#define DP_FSIZOFF     16
#define DP_BNUMOFF     24
#define DP_RNUMOFF     32
#define DP_DEFBNUM     8191
#define DP_COALMAX     3
#define DP_TMPFSUF     ".dptmp"
#define DP_OPTBLOAD    0.25
#define DP_OPTRUNIT    256
#define DP_IOBUFSIZ    8192


enum {
  DP_RHIFLAGS,
  DP_RHIHASH,
  DP_RHIKSIZ,
  DP_RHIVSIZ,
  DP_RHIPSIZ,
  DP_RHILEFT,
  DP_RHIRIGHT,
  DP_RHNUM
};

enum {
  DP_RECFDEL = 1 << 0,
  DP_RECFREUSE = 1 << 1
};


//EK static int dpbigendian(void);
static int dpbyteswap(int num);
static char *dpstrdup(const char *str);
static int dplock(int fd, int ex);
static int dpwrite(int fd, const void *buf, int size);
static int dpseekwrite(int fd, int off, const void *buf, int size);
static int dpseekwritenum(int fd, int off, int num);
static int dpread(int fd, void *buf, int size);
static int dpseekread(int fd, int off, void *buf, int size);
static int dpfcopy(int destfd, int destoff, int srcfd, int srcoff);
static int dpfirsthash(const char *kbuf, int ksiz);
static int dpsecondhash(const char *kbuf, int ksiz);
static int dpthirdhash(const char *kbuf, int ksiz);
static int dpgetprime(int num);
static int dppadsize(DEPOT *depot, int vsiz);
static int dprecsize(int *head);
static int dprechead(DEPOT *depot, int off, int *head);
static char *dpreckey(DEPOT *depot, int off, int *head);
static char *dprecval(DEPOT *depot, int off, int *head, int start, int max);
static int dpkeycmp(const char *abuf, int asiz, const char *bbuf, int bsiz);
static int dprecsearch(DEPOT *depot, const char *kbuf, int ksiz, int hash,
                       int *bip, int *offp, int *entp, int *head, int delhit);
static int dprecrewrite(DEPOT *depot, int off, int rsiz, const char *kbuf, int ksiz,
                        const char *vbuf, int vsiz, int hash, int left, int right);
static int dprecappend(DEPOT *depot, const char *kbuf, int ksiz, const char *vbuf, int vsiz,
                       int hash, int left, int right);
static int dprecover(DEPOT *depot, int off, int *head, const char *vbuf, int vsiz, int cat);
static int dprecdelete(DEPOT *depot, int off, int *head, int reusable);



/*************************************************************************************************
 * public objects
 *************************************************************************************************/


/* String containing the version information. */
const char *dpversion = _QDBM_VERSION;


/* Last happened error code. */
int dpecode = DP_ENOERR;


/* Get a message string corresponding to an error code. */
const char *dperrmsg(int ecode){
  switch(ecode){
  case DP_ENOERR: return "no error";
  case DP_EFATAL: return "with fatal error";
  case DP_EMODE: return "invalid mode";
  case DP_EBROKEN: return "broken database file";
  case DP_EKEEP: return "existing record";
  case DP_ENOITEM: return "no item found";
  case DP_EALLOC: return "memory allocation error";
  case DP_EMAP: return "memory mapping error";
  case DP_EOPEN: return "open error";
  case DP_ECLOSE: return "close error";
  case DP_ETRUNC: return "trunc error";
  case DP_ESYNC: return "sync error";
  case DP_ESTAT: return "stat error";
  case DP_ESEEK: return "seek error";
  case DP_EREAD: return "read error";
  case DP_EWRITE: return "write error";
  case DP_ELOCK: return "lock error";
  case DP_EUNLINK: return "unlink error";
  case DP_EMKDIR: return "mkdir error";
  case DP_ERMDIR: return "rmdir error";
  case DP_EMISC: return "miscellaneous error";
  }
  return "(invalid ecode)";
}


/* Get a database handle. */
DEPOT *dpopen(const char *name, int omode, int bnum){
  int mode, fd, inode, fsiz, rnum, c, msiz, rc;
  char hbuf[DP_HEADSIZ], *map;
  struct stat sbuf;
  DEPOT *depot;
  assert(name);
//printf("%s\n",__FUNCTION__);

  mode = O_RDONLY;
  if(omode & DP_OWRITER){
    mode = O_RDWR;
    if(omode & DP_OCREAT) mode |= O_CREAT;
  }
#if defined(__IBMC__) || defined(__IBMCPP__)
    mode |= O_BINARY;
#endif
  if((fd = open(name, mode, DP_FILEMODE)) == -1){
    dpecode = DP_EOPEN;
    return NULL;
  }
  if(!(omode & DP_ONOLCK)){
    if(!dplock(fd, omode & DP_OWRITER)){
      close(fd);
      return NULL;
    }
  }
  if((omode & DP_OWRITER) && (omode & DP_OTRUNC)){
    if(ftruncate(fd, 0) == -1){
      close(fd);
      dpecode = DP_ETRUNC;
      return NULL;
    }
  }
  rc = fstat(fd, &sbuf);
  if(rc == -1 || !S_ISREG(sbuf.st_mode)){
    close(fd);
    dpecode = DP_ESTAT;
    return NULL;
  }
  inode = sbuf.st_ino;
  fsiz = sbuf.st_size;
  if((omode & DP_OWRITER) && fsiz == 0){
    memset(hbuf, 0, DP_HEADSIZ);
#if WORDS_BIGENDIAN
//EK    if(dpbigendian()){
      memcpy(hbuf, DP_MAGICNUMB, strlen(DP_MAGICNUMB));
#else
//EK    } else {
      memcpy(hbuf, DP_MAGICNUML, strlen(DP_MAGICNUML));
//EK    }
#endif
    bnum = bnum < 1 ? DP_DEFBNUM : bnum;
    bnum = dpgetprime(bnum);
    memcpy(hbuf + DP_BNUMOFF, &bnum, sizeof(int));
    rnum = 0;
    memcpy(hbuf + DP_RNUMOFF, &rnum, sizeof(int));
    c = 0;
    fsiz = DP_HEADSIZ + bnum * sizeof(int);
    memcpy(hbuf + DP_FSIZOFF, &fsiz, sizeof(int));
    if(!dpseekwrite(fd, 0, hbuf, DP_HEADSIZ) ||
       !dpseekwrite(fd, fsiz - 1, &c, 1)){
      close(fd);
      return NULL;
    }
  }
  if(!dpseekread(fd, 0, hbuf, DP_HEADSIZ)){
    close(fd);
    dpecode = DP_EBROKEN;
    return NULL;
  }
/******* ???????????? ***********/
#if WORDS_BIGENDIAN
  if((memcmp(hbuf, DP_MAGICNUMB, strlen(DP_MAGICNUMB)) != 0) ||
     memcmp(hbuf + DP_FSIZOFF, &fsiz, sizeof(int)) != 0)
#else
  if((memcmp(hbuf, DP_MAGICNUML, strlen(DP_MAGICNUML)) != 0) ||
     (memcmp(hbuf + DP_FSIZOFF, &fsiz, sizeof(int)) != 0))
#endif
  {
    close(fd);
    dpecode = DP_EBROKEN;
    return NULL;
  }
  bnum = *((int *)(hbuf + DP_BNUMOFF));
  rnum = *((int *)(hbuf + DP_RNUMOFF));
  if(bnum < 1 || rnum < 0 || fsiz < DP_HEADSIZ + bnum * sizeof(int)){
    close(fd);
    dpecode = DP_EBROKEN;
    return NULL;
  }
  msiz = DP_HEADSIZ + bnum * sizeof(int);
  map = (char *) mmap(0, msiz, PROT_READ | ((mode & DP_OWRITER) ? PROT_WRITE : 0), MAP_SHARED, fd, 0);
  if(map == MAP_FAILED){
    close(fd);
    dpecode = DP_EMAP;
    return NULL;
  }
  depot = (DEPOT*)malloc(sizeof(DEPOT));
  if(!(depot) || !(depot->name = dpstrdup(name))){
    munmap(map, msiz);
    free(depot);
    close(fd);
    dpecode = DP_EALLOC;
    return NULL;
  }
  depot->wmode = (mode & DP_OWRITER);
  depot->inode = inode;
  depot->fd = fd;
  depot->fsiz = fsiz;
  depot->map = map;
  depot->msiz = msiz;
  depot->buckets = (int *)(map + DP_HEADSIZ);
  depot->bnum = bnum;
  depot->rnum = rnum;
  depot->fatal = FALSE;
  depot->ioff = 0;
  depot->mroff = -1;
  depot->mrsiz = -1;
  depot->align = 0;
  return depot;
}


/* Close a database handle. */
int dpclose(DEPOT *depot){
  int err;
  assert(depot);
//printf("%s\n",__FUNCTION__);
  err = FALSE;
  if(depot->wmode){
    *((int *)(depot->map + DP_FSIZOFF)) = depot->fsiz;
    *((int *)(depot->map + DP_RNUMOFF)) = depot->rnum;
  }
  if(depot->map != MAP_FAILED){
    if(munmap(depot->map, depot->msiz) == -1){
      err = TRUE;
      dpecode = DP_EMAP;
    }
  }
  if(close(depot->fd) == -1){
    err = TRUE;
    dpecode = DP_ECLOSE;
  }
  free(depot->name);
  free(depot);
  return err ? FALSE : TRUE;
}


/* Store a record. */
int dpput(DEPOT *depot, const char *kbuf, int ksiz, const char *vbuf, int vsiz, int dmode){
  int head[DP_RHNUM], next[DP_RHNUM];
  int i, hash, bi, off, entoff, newoff, rsiz, nsiz, fdel, mroff, mrsiz;
  char *tval;
  assert(depot && kbuf && vbuf);
//printf("%s\n",__FUNCTION__);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return FALSE;
  }
  if(!depot->wmode){
    dpecode = DP_EMODE;
    return FALSE;
  }
  if(ksiz < 0) ksiz = strlen(kbuf);
  if(vsiz < 0) vsiz = strlen(vbuf);
  newoff = -1;
  hash = dpsecondhash(kbuf, ksiz);
  switch(dprecsearch(depot, kbuf, ksiz, hash, &bi, &off, &entoff, head, TRUE)){
  case -1:
    depot->fatal = TRUE;
    return FALSE;
  case 0:
    fdel = head[DP_RHIFLAGS] & DP_RECFDEL;
    if(dmode == DP_DKEEP && !fdel){
      dpecode = DP_EKEEP;
      return FALSE;
    }
    if(fdel){
      head[DP_RHIPSIZ] += head[DP_RHIVSIZ];
      head[DP_RHIVSIZ] = 0;
    }
    rsiz = dprecsize(head);
    nsiz = DP_RHNUM * sizeof(int) + ksiz + vsiz;
    if(dmode == DP_DCAT) nsiz += head[DP_RHIVSIZ];
    if(off + rsiz >= depot->fsiz){
      if(rsiz < nsiz){
        head[DP_RHIPSIZ] += nsiz - rsiz;
        rsiz = nsiz;
        depot->fsiz = off + rsiz;
      }
    } else {
      for(i = 0; i < DP_COALMAX && nsiz > rsiz && off + rsiz < depot->fsiz; i++){
        if(off + rsiz == depot->mroff){
          depot->mroff = -1;
          depot->mrsiz = -1;
        }
        if(!dprechead(depot, off + rsiz, next)) return FALSE;
        if(!(next[DP_RHIFLAGS] & DP_RECFREUSE)) break;
        head[DP_RHIPSIZ] += dprecsize(next);
        rsiz += dprecsize(next);
      }
    }
    if(nsiz <= rsiz){
      if(!dprecover(depot, off, head, vbuf, vsiz, dmode == DP_DCAT)){
        depot->fatal = TRUE;
        return FALSE;
      }
    } else {
      tval = NULL;
      if(dmode == DP_DCAT){
        if(!(tval = dprecval(depot, off, head, 0, -1))){
          depot->fatal = TRUE;
          return FALSE;
        }
        tval =(char*) realloc(tval, head[DP_RHIVSIZ] + vsiz);
        if(!(tval)){
          free(tval);
          dpecode = DP_EALLOC;
          depot->fatal = TRUE;
          return FALSE;
        }
        memcpy(tval + head[DP_RHIVSIZ], vbuf, vsiz);
        vsiz += head[DP_RHIVSIZ];
        vbuf = tval;
      }
      mroff = depot->mroff;
      mrsiz = depot->mrsiz;
      if(!dprecdelete(depot, off, head, TRUE)){
        free(tval);
        depot->fatal = TRUE;
        return FALSE;
      }
      if(mroff > 0 && nsiz <= mrsiz){
        if(!dprecrewrite(depot, mroff, mrsiz, kbuf, ksiz, vbuf, vsiz,
                         hash, head[DP_RHILEFT], head[DP_RHIRIGHT])){
          free(tval);
          depot->fatal = TRUE;
          return FALSE;
        }
        newoff = mroff;
      } else {
        if((newoff = dprecappend(depot, kbuf, ksiz, vbuf, vsiz,
                                 hash, head[DP_RHILEFT], head[DP_RHIRIGHT])) == -1){
          free(tval);
          depot->fatal = TRUE;
          return FALSE;
        }
      }
      free(tval);
    }
    if(fdel) depot->rnum++;
    break;
  default:
    if((newoff = dprecappend(depot, kbuf, ksiz, vbuf, vsiz, hash, 0, 0)) == -1){
      depot->fatal = TRUE;
      return FALSE;
    }
    depot->rnum++;
    break;
  }
  if(newoff > 0){
    if(entoff > 0){
      if(!dpseekwritenum(depot->fd, entoff, newoff)){
        depot->fatal = TRUE;
        return FALSE;
      }
    } else {
      depot->buckets[bi] = newoff;
    }
  }
  return TRUE;
}


/* Delete a record. */
int dpout(DEPOT *depot, const char *kbuf, int ksiz){
  int head[DP_RHNUM], hash, bi, off, entoff;
  assert(depot && kbuf);
//printf("%s\n",__FUNCTION__);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return FALSE;
  }
  if(!depot->wmode){
    dpecode = DP_EMODE;
    return FALSE;
  }
  if(ksiz < 0) ksiz = strlen(kbuf);
  hash = dpsecondhash(kbuf, ksiz);
  switch(dprecsearch(depot, kbuf, ksiz, hash, &bi, &off, &entoff, head, FALSE)){
  case -1:
    depot->fatal = TRUE;
    return FALSE;
  case 0:
    break;
  default:
    dpecode = DP_ENOITEM;
    return FALSE;
  }
  if(!dprecdelete(depot, off, head, FALSE)){
    depot->fatal = TRUE;
    return FALSE;
  }
  depot->rnum--;
  return TRUE;
}


/* Retrieve a record. */
char *dpget(DEPOT *depot, const char *kbuf, int ksiz, int start, int max, int *sp){
  int head[DP_RHNUM], hash, bi, off, entoff, rc;
  char *vbuf=NULL;
  assert(depot && kbuf && start >= 0);
//printf("%s\n",__FUNCTION__);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return NULL;
  }
  if(ksiz < 0) ksiz = strlen(kbuf);
  hash = dpsecondhash(kbuf, ksiz);
  rc = dprecsearch(depot, kbuf, ksiz, hash, &bi, &off, &entoff, head, FALSE);
  switch(rc){
  case -1:
    depot->fatal = TRUE;
    return NULL;
  case 0:
    break;
  default:
    dpecode = DP_ENOITEM;
    return NULL;
  }
  if(start > head[DP_RHIVSIZ]){
    dpecode = DP_ENOITEM;
    return NULL;
  }
  if(!(vbuf = dprecval(depot, off, head, start, max))){
    depot->fatal = TRUE;
    return NULL;
  }
  if(sp){
    if(max < 0){
      *sp = head[DP_RHIVSIZ];
    } else {
      *sp = max < head[DP_RHIVSIZ] ? max : head[DP_RHIVSIZ];
    }
  }
  return vbuf;
}


/* Get the size of the value of a record. */
int dpvsiz(DEPOT *depot, const char *kbuf, int ksiz){
  int head[DP_RHNUM], hash, bi, off, entoff;
  assert(depot && kbuf);
//printf("%s\n",__FUNCTION__);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return -1;
  }
  if(ksiz < 0) ksiz = strlen(kbuf);
  hash = dpsecondhash(kbuf, ksiz);
  switch(dprecsearch(depot, kbuf, ksiz, hash, &bi, &off, &entoff, head, FALSE)){
  case -1:
    depot->fatal = TRUE;
    return -1;
  case 0:
    break;
  default:
    dpecode = DP_ENOITEM;
    return -1;
  }
  return head[DP_RHIVSIZ];
}


/* Initialize the iterator of a database handle. */
int dpiterinit(DEPOT *depot){
  assert(depot);
//printf("%s\n",__FUNCTION__);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return FALSE;
  }
  depot->ioff = 0;
  return TRUE;
}


/* Get the next key of the iterator. */
char *dpiternext(DEPOT *depot, int *sp){
  int off, head[DP_RHNUM];
  char *kbuf;
  assert(depot);
//printf("%s\n",__FUNCTION__);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return NULL;
  }
  off = DP_HEADSIZ + depot->bnum * sizeof(int);
  off = off > depot->ioff ? off : depot->ioff;
  while(off < depot->fsiz){
    if(!dprechead(depot, off, head)){
      depot->fatal = TRUE;
      return NULL;
    }
    if(head[DP_RHIFLAGS] & DP_RECFDEL){
      off += dprecsize(head);
    } else {
      if(!(kbuf = dpreckey(depot, off, head))){
        depot->fatal = TRUE;
        return NULL;
      }
      depot->ioff = off + dprecsize(head);
      if(sp) *sp = head[DP_RHIKSIZ];
      return kbuf;
    }
  }
  dpecode = DP_ENOITEM;
  return NULL;
}


/* Set alignment of a database handle. */
int dpsetalign(DEPOT *depot, int align){
  assert(depot);
//printf("%s\n",__FUNCTION__);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return FALSE;
  }
  if(!depot->wmode){
    dpecode = DP_EMODE;
    return FALSE;
  }
  depot->align = align;
  return TRUE;
}


/* Synchronize contents of updating a database with the file and the device. */
int dpsync(DEPOT *depot){
  assert(depot);
//printf("%s\n",__FUNCTION__);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return FALSE;
  }
  if(!depot->wmode){
    dpecode = DP_EMODE;
    return FALSE;
  }
  *((int *)(depot->map + DP_FSIZOFF)) = depot->fsiz;
  *((int *)(depot->map + DP_RNUMOFF)) = depot->rnum;
  if(msync(depot->map, depot->msiz, MS_SYNC) == -1){
    dpecode = DP_EMAP;
    depot->fatal = TRUE;
    return FALSE;
  }
  if(fsync(depot->fd) == -1){
    dpecode = DP_ESYNC;
    depot->fatal = TRUE;
    return FALSE;
  }
  return TRUE;
}


/* Optimize a database. */
int dpoptimize(DEPOT *depot, int bnum){
  DEPOT *tdepot;
  char *name;
  int i, err, off, head[DP_RHNUM], ksizs[DP_OPTRUNIT], vsizs[DP_OPTRUNIT], unum;
  char *kbufs[DP_OPTRUNIT], *vbufs[DP_OPTRUNIT];
  assert(depot);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return FALSE;
  }
  if(!depot->wmode){
    dpecode = DP_EMODE;
    return FALSE;
  }
  name = (char *)malloc(strlen(depot->name) + strlen(DP_TMPFSUF) + 1);
  if(!(name)){
    dpecode = DP_EALLOC;
    depot->fatal = FALSE;
    return FALSE;
  }
  sprintf(name, "%s%s", depot->name, DP_TMPFSUF);
  bnum = dpgetprime(bnum > 0 ? bnum : (int)(depot->rnum * (1.0 / DP_OPTBLOAD)) + 1);
  if(!(tdepot = dpopen(name, DP_OWRITER | DP_OCREAT | DP_OTRUNC, bnum))){
    free(name);
    depot->fatal = TRUE;
    return FALSE;
  }
  free(name);
  tdepot->align = depot->align;
  err = FALSE;
  off = DP_HEADSIZ + depot->bnum * sizeof(int);
  unum = 0;
  while(off < depot->fsiz){
    if(!dprechead(depot, off, head)){
      err = TRUE;
      break;
    }
    if(!(head[DP_RHIFLAGS] & DP_RECFDEL)){
      kbufs[unum] = dpreckey(depot, off, head);
      ksizs[unum] = head[DP_RHIKSIZ];
      vbufs[unum] = dprecval(depot, off, head, 0, -1);
      vsizs[unum] = head[DP_RHIVSIZ];
      unum++;
      if(unum >= DP_OPTRUNIT){
        for(i = 0; i < unum; i++){
          if(kbufs[i] && vbufs[i]){
            if(!dpput(tdepot, kbufs[i], ksizs[i], vbufs[i], vsizs[i], DP_DKEEP)) err = TRUE;
          } else {
            err = TRUE;
          }
          free(kbufs[i]);
          free(vbufs[i]);
          if(err) break;
        }
        unum = 0;
      }
    }
    off += dprecsize(head);
    if(err) break;
  }
  for(i = 0; i < unum; i++){
    if(kbufs[i] && vbufs[i]){
      if(!dpput(tdepot, kbufs[i], ksizs[i], vbufs[i], vsizs[i], DP_DKEEP)) err = TRUE;
    } else {
      err = TRUE;
    }
    free(kbufs[i]);
    free(vbufs[i]);
    if(err) break;
  }
  if(!dpsync(tdepot)) err = TRUE;
  if(err){
    unlink(tdepot->name);
    dpclose(tdepot);
    depot->fatal = TRUE;
    return FALSE;
  }
  if(munmap(depot->map, depot->msiz) == -1){
    dpclose(tdepot);
    dpecode = DP_EMAP;
    depot->fatal = TRUE;
    return FALSE;
  }
  depot->map = (char*)MAP_FAILED;
  if(ftruncate(depot->fd, 0) == -1){
    dpclose(tdepot);
    unlink(tdepot->name);
    dpecode = DP_ETRUNC;
    depot->fatal = TRUE;
    return FALSE;
  }
  if(dpfcopy(depot->fd, 0, tdepot->fd, 0) == -1){
    dpclose(tdepot);
    unlink(tdepot->name);
    depot->fatal = TRUE;
    return FALSE;
  }
  depot->fsiz = tdepot->fsiz;
  depot->bnum = tdepot->bnum;
  depot->ioff = 0;
  depot->mroff = -1;
  depot->mrsiz = -1;
  depot->msiz = tdepot->msiz;
  depot->map = (char*)mmap(0, depot->msiz, PROT_READ | PROT_WRITE, MAP_SHARED, depot->fd, 0);
  if(depot->map == MAP_FAILED){
    dpecode = DP_EMAP;
    depot->fatal = TRUE;
    return FALSE;
  }
  depot->buckets = (int *)(depot->map + DP_HEADSIZ);
  if(!(name = dpname(tdepot))){
    dpclose(tdepot);
    unlink(tdepot->name);
    depot->fatal = TRUE;
    return FALSE;
  }
  if(!dpclose(tdepot)){
    free(name);
    unlink(tdepot->name);
    depot->fatal = TRUE;
    return FALSE;
  }
  if(unlink(name) == -1){
    free(name);
    dpecode = DP_EUNLINK;
    depot->fatal = TRUE;
    return FALSE;
  }
  free(name);
  return TRUE;
}


/* Get the name of a database. */
char *dpname(DEPOT *depot){
  char *name;
  assert(depot);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return NULL;
  }
  if(!(name = dpstrdup(depot->name))){
    dpecode = DP_EALLOC;
    depot->fatal = TRUE;
    return NULL;
  }
  return name;
}


/* Get the size of a database file. */
int dpfsiz(DEPOT *depot){
  assert(depot);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return -1;
  }
  return depot->fsiz;
}


/* Get the number of the elements of the bucket array. */
int dpbnum(DEPOT *depot){
  assert(depot);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return -1;
  }
  return depot->bnum;
}


/* Get the number of the used elements of the bucket array. */
int dpbusenum(DEPOT *depot){
  int i, hits;
  assert(depot);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return -1;
  }
  hits = 0;
  for(i = 0; i < depot->bnum; i++){
    if(depot->buckets[i]) hits++;
  }
  return hits;
}


/* Get the number of the records stored in a database. */
int dprnum(DEPOT *depot){
  assert(depot);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return -1;
  }
  return depot->rnum;
}


/* Check whether a database handle is a writer or not. */
int dpwritable(DEPOT *depot){
  assert(depot);
  return depot->wmode;
}


/* Check whether a database has a fatal error or not. */
int dpfatalerror(DEPOT *depot){
  assert(depot);
  return depot->fatal;
}


/* Get the inode number of a database file. */
int dpinode(DEPOT *depot){
  assert(depot);
  return depot->inode;
}


/* Get the file descriptor of a database file. */
int dpfdesc(DEPOT *depot){
  assert(depot);
  return depot->fd;
}


/* Remove a database file. */
int dpremove(const char *name){
  struct stat sbuf;
  DEPOT *depot;
  assert(name);
  if(stat(name, &sbuf) == -1){
    dpecode = DP_ESTAT;
    return FALSE;
  }
  if((depot = dpopen(name, DP_OWRITER | DP_OTRUNC, -1)) != NULL) dpclose(depot);
  if(unlink(name) == -1){
    dpecode = DP_EUNLINK;
    return FALSE;
  }
  return TRUE;
}


/* Convert a database file for another platform with different byte order. */
int dpeconv(const char *name, int big){
  int i, ifd, ofd, mybig, fbig, fsiz, bnum, rnum, err, rhead[DP_RHNUM], off, ksiz, vsiz, psiz;
  char *tname, hbuf[DP_HEADSIZ], *bbuf, *rbuf;
  int mode;
  assert(name);
  mode = O_RDONLY;
#if defined(__IBMC__) || defined(__IBMCPP__)
    mode |= O_BINARY;
#endif

  if((ifd = open(name, mode, DP_FILEMODE)) == -1){
    dpecode = DP_EOPEN;
    return FALSE;
  }
  if(!dplock(ifd, FALSE) || !dpseekread(ifd, 0, hbuf, DP_HEADSIZ)){
    close(ifd);
    return FALSE;
  }
  mybig = WORDS_BIGENDIAN;
  fbig = FALSE;
  if(!memcmp(hbuf, DP_MAGICNUMB, strlen(DP_MAGICNUMB))){
    fbig = TRUE;
  } else if(!memcmp(hbuf, DP_MAGICNUML, strlen(DP_MAGICNUML))){
    fbig = FALSE;
  } else {
    close(ifd);
    dpecode = DP_EBROKEN;
    return FALSE;
  }
  tname = (char *)malloc(strlen(name) + strlen(DP_TMPFSUF) + 1);
  if(!(tname)){
    close(ifd);
    dpecode = DP_EALLOC;
    return FALSE;
  }
  sprintf(tname, "%s%s", name, DP_TMPFSUF);
  mode = O_WRONLY | O_CREAT | O_TRUNC;
#if defined(__IBMC__) || defined(__IBMCPP__)
    mode |= O_BINARY;
#endif

  if((ofd = open(tname, mode, DP_FILEMODE)) == -1){
    free(tname);
    close(ifd);
    dpecode = DP_EOPEN;
    return FALSE;
  }
  fsiz = *((int *)(hbuf + DP_FSIZOFF));
  bnum = *((int *)(hbuf + DP_BNUMOFF));
  rnum = *((int *)(hbuf + DP_RNUMOFF));
  if(mybig ? !fbig : fbig){
    fsiz = dpbyteswap(fsiz);
    bnum = dpbyteswap(bnum);
    rnum = dpbyteswap(rnum);
  }
  if(fsiz < 1 || bnum < 1 || rnum < 0){
    free(tname);
    close(ifd);
    close(ofd);
    dpecode = DP_EBROKEN;
    return FALSE;
  }
  strcpy(hbuf, big ? DP_MAGICNUMB : DP_MAGICNUML);
  if(big ? !fbig : fbig){
    *((int *)(hbuf + DP_FSIZOFF)) = dpbyteswap(*((int *)(hbuf + DP_FSIZOFF)));
    *((int *)(hbuf + DP_BNUMOFF)) = dpbyteswap(*((int *)(hbuf + DP_BNUMOFF)));
    *((int *)(hbuf + DP_RNUMOFF)) = dpbyteswap(*((int *)(hbuf + DP_RNUMOFF)));
  }
  if(!dpseekwrite(ofd, 0, hbuf, DP_HEADSIZ)){
    free(tname);
    close(ifd);
    close(ofd);
    return FALSE;
  }
  bbuf = (char *)malloc(bnum * sizeof(int));
  if(!(bbuf)){
    free(tname);
    close(ifd);
    close(ofd);
    dpecode = DP_EALLOC;
    return FALSE;
  }
  if(!dpseekread(ifd, DP_HEADSIZ, bbuf, bnum * sizeof(int))){
    free(tname);
    free(bbuf);
    close(ifd);
    close(ofd);
    return FALSE;
  }
  if(big ? !fbig : fbig){
    for(i = 0; i < bnum * sizeof(int); i += sizeof(int)){
      *((int *)(bbuf + i)) = dpbyteswap(*((int *)(bbuf + i)));
    }
  }
  if(!dpseekwrite(ofd, DP_HEADSIZ, bbuf, bnum * sizeof(int))){
    free(tname);
    free(bbuf);
    close(ifd);
    close(ofd);
    return FALSE;
  }
  free(bbuf);
  err = FALSE;
  off = DP_HEADSIZ + bnum * sizeof(int);
  while(off < fsiz){
    if(!dpseekread(ifd, off, rhead, sizeof(rhead))){
      err = TRUE;
      break;
    }
    ksiz = rhead[DP_RHIKSIZ];
    vsiz = rhead[DP_RHIVSIZ];
    psiz = rhead[DP_RHIPSIZ];
/* ?????? */
    if(mybig ? !fbig : fbig){
      ksiz = dpbyteswap(ksiz);
      vsiz = dpbyteswap(vsiz);
      psiz = dpbyteswap(psiz);
    }
    if(ksiz < 0 || vsiz < 0 || psiz < 0){
      dpecode = DP_EBROKEN;
      err = TRUE;
      break;
    }
    rbuf = (char *) malloc(sizeof(rhead) + ksiz + vsiz + psiz);
    if(!(rbuf)){
      dpecode = DP_EALLOC;
      err = TRUE;
      break;
    }
    if(big ? !fbig : fbig){
      for(i = 0; i < DP_RHNUM; i++){
        rhead[i] = dpbyteswap(rhead[i]);
      }
    }
    memcpy(rbuf, rhead, sizeof(rhead));
    if(!dpseekread(ifd, off + sizeof(rhead), rbuf + sizeof(rhead), ksiz + vsiz + psiz) ||
       !dpseekwrite(ofd, -1, rbuf, sizeof(rhead) + ksiz + vsiz + psiz)){
      free(rbuf);
      err = TRUE;
      break;
    }
    free(rbuf);
    off += sizeof(rhead) + ksiz + vsiz + psiz;
  }
  close(ifd);
  close(ofd);
  if(rename(tname, name) == -1){
    dpecode = DP_EMISC;
    err = TRUE;
  }
  free(tname);
  return err ? FALSE : TRUE;
}


/* Hash function used inside Depot. */
int dpinnerhash(const char *kbuf, int ksiz){
  assert(kbuf);
//printf("%s\n",__FUNCTION__);
  if(ksiz < 0) ksiz = strlen(kbuf);
  return dpfirsthash(kbuf, ksiz);
}


/* Hash function which is independent from the hash functions used inside Depot. */
int dpouterhash(const char *kbuf, int ksiz){
  assert(kbuf);
//printf("%s\n",__FUNCTION__);
  if(ksiz < 0) ksiz = strlen(kbuf);
  return dpthirdhash(kbuf, ksiz);
}


/* Get a prime number not less than a number. */
int dpprimenum(int num){
  assert(num > 0);
  return dpgetprime(num);
}



/*************************************************************************************************
 * Functions for Experts
 *************************************************************************************************/


/* Synchronize updating contents on memory. */
int dpmemsync(DEPOT *depot){
  assert(depot);
//printf("%s\n",__FUNCTION__);
  if(depot->fatal){
    dpecode = DP_EFATAL;
    return FALSE;
  }
  if(!depot->wmode){
    dpecode = DP_EMODE;
    return FALSE;
  }
  *((int *)(depot->map + DP_FSIZOFF)) = depot->fsiz;
  *((int *)(depot->map + DP_RNUMOFF)) = depot->rnum;
  if(msync(depot->map, depot->msiz, MS_ASYNC) == -1){
    dpecode = DP_EMAP;
    depot->fatal = TRUE;
    return FALSE;
  }
  return TRUE;
}



/*************************************************************************************************
 * private objects
 *************************************************************************************************/

#if 0 //EK
/* Check whether the byte order of the platform is big endian or not.
   The return value is true if bigendian, else, it is false. */
static int dpbigendian(void){
  char buf[sizeof(int)];
  *(int *)buf = 1;
  return !buf[0];
}
#endif

/* Get a byte-reversed integer.
   `num' specifies an original integer.
   The return value is the swapped integer of the original integer. */
static int dpbyteswap(int num){
  char buf[sizeof(int)];
  int i;
//printf("%s\n",__FUNCTION__);
  for(i = 0; i < sizeof(int); i++){
    buf[i] = ((char *)&num)[sizeof(int)-i-1];
  }
  return *(int *)buf;
}


/* Get a copied string.
   `str' specifies an original string.
   The return value is a copied string whose region is allocated by `malloc'. */
static char *dpstrdup(const char *str){
  int len;
  char *buf;
  assert(str);
  len = strlen(str);
  buf = (char *)malloc(len + 1);
  if(!(buf)) return NULL;
  memcpy(buf, str, len + 1);
  return buf;
}


/* Lock a file descriptor.
   `fd' specifies a file descriptor.
   `ex' specifies whether an exclusive lock or a shared lock is performed.
   The return value is true if successful, else, it is false. */
static int dplock(int fd, int ex){
  struct flock lock;
  assert(fd >= 0);
  memset(&lock, 0, sizeof(struct flock));
  lock.l_type = ex ? F_WRLCK : F_RDLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 0;
  lock.l_pid = 0;
  while(fcntl(fd, F_SETLKW, &lock) == -1){
    if(errno != EINTR){
      dpecode = DP_ELOCK;
      return FALSE;
    }
  }
  return TRUE;
}


/* Write into a file.
   `fd' specifies a file descriptor.
   `buf' specifies a buffer to write.
   `size' specifies the size of the buffer.
   The return value is the size of the written buffer, or, -1 on failure. */
static int dpwrite(int fd, const void *buf, int size){
  const char *lbuf;
  int rv, wb;
  assert(fd >= 0 && buf && size >= 0);
//printf("%s\n",__FUNCTION__);
  lbuf = (const char*) buf;
  rv = 0;
  do {
    wb = write(fd, lbuf, size);
    switch(wb){
    case -1: if(errno != EINTR) return -1;
    case 0: break;
    default:
      lbuf += wb;
      size -= wb;
      rv += wb;
      break;
    }
  } while(size > 0);
  return rv;
}


/* Write into a file at an offset.
   `fd' specifies a file descriptor.
   `off' specifies an offset of the file.
   `buf' specifies a buffer to write.
   `size' specifies the size of the buffer.
   The return value is true if successful, else, it is false. */
static int dpseekwrite(int fd, int off, const void *buf, int size){
  char *lbuf;
  assert(fd >= 0 && buf && size >= 0);
//printf("%s\n",__FUNCTION__);
  if(size < 1) return TRUE;
  lbuf = (char *)buf;
  if(off < 0){
    if(lseek(fd, 0, SEEK_END) == -1){
      dpecode = DP_ESEEK;
      return FALSE;
    }
  } else {
    if(lseek(fd, off, SEEK_SET) != off){
      dpecode = DP_ESEEK;
      return FALSE;
    }
  }
  if(dpwrite(fd, lbuf, size) != size){
    dpecode = DP_EWRITE;
    return FALSE;
  }
  return TRUE;
}


/* Write an integer into a file at an offset.
   `fd' specifies a file descriptor.
   `off' specifies an offset of the file.
   `num' specifies an integer.
   The return value is true if successful, else, it is false. */
static int dpseekwritenum(int fd, int off, int num){
  assert(fd >= 0);
  return dpseekwrite(fd, off, &num, sizeof(int));
}


/* Read from a file and store the data into a buffer.
   `fd' specifies a file descriptor.
   `buffer' specifies a buffer to store into.
   `size' specifies the size to read with.
   The return value is the size read with, or, -1 on failure. */
static int dpread(int fd, void *buf, int size){
  char *lbuf;
  int i, bs;
//printf("%s\n",__FUNCTION__);
  assert(fd >= 0 && buf && size >= 0);
  lbuf = (char *)buf;
  for(i = 0; i < size && (bs = read(fd, lbuf + i, size - i)) != 0; i += bs){
    if(bs == -1 && errno != EINTR) return -1;
  }
  return i;
}


/* Read from a file at an offset and store the data into a buffer.
   `fd' specifies a file descriptor.
   `off' specifies an offset of the file.
   `buffer' specifies a buffer to store into.
   `size' specifies the size to read with.
   The return value is true if successful, else, it is false. */
static int dpseekread(int fd, int off, void *buf, int size){
  char *lbuf;
  assert(fd >= 0 && off >= 0 && buf && size >= 0);
  lbuf = (char *)buf;
  if(lseek(fd, off, SEEK_SET) != off){
    dpecode = DP_ESEEK;
    return FALSE;
  }
  if(dpread(fd, lbuf, size) != size){
    dpecode = DP_EREAD;
    return FALSE;
  }
  return TRUE;
}


/* Copy data between files.
   `destfd' specifies a file descriptor of a destination file.
   `destoff' specifies an offset of the destination file.
   `srcfd' specifies a file descriptor of a source file.
   `srcoff' specifies an offset of the source file.
   The return value is the size copied with, or, -1 on failure. */
static int dpfcopy(int destfd, int destoff, int srcfd, int srcoff){
  char iobuf[DP_IOBUFSIZ];
  int sum, iosiz;
//printf("%s\n",__FUNCTION__);
  if(lseek(srcfd, srcoff, SEEK_SET) == -1 || lseek(destfd, destoff, SEEK_SET) == -1){
    dpecode = DP_ESEEK;
    return -1;
  }
  sum = 0;
  while((iosiz = dpread(srcfd, iobuf, DP_IOBUFSIZ)) > 0){
    if(dpwrite(destfd, iobuf, iosiz) == -1){
      dpecode = DP_EWRITE;
      return -1;
    }
    sum += iosiz;
  }
  if(iosiz < 0){
    dpecode = DP_EREAD;
    return -1;
  }
  return sum;
}


/* Get the first hash value.
   `kbuf' specifies the pointer to the region of a key.
   `ksiz' specifies the size of the key.
   The return value is 31 bit hash value of the key. */
static int dpfirsthash(const char *kbuf, int ksiz){
  unsigned int sum;
  int i;
  assert(kbuf && ksiz >= 0);
//printf("%s\n",__FUNCTION__);
  if(ksiz == sizeof(int)){
    memcpy(&sum, kbuf, sizeof(int));
  } else {
    sum = 751;
  }
  for(i = 0; i < ksiz; i++){
    sum = sum * 31 + ((const unsigned char *)kbuf)[i];
  }
  return (sum * 87767623) & 0x7FFFFFFF;
}


/* Get the second hash value.
   `kbuf' specifies the pointer to the region of a key.
   `ksiz' specifies the size of the key.
   The return value is 31 bit hash value of the key. */
static int dpsecondhash(const char *kbuf, int ksiz){
  unsigned int sum;
  int i;
//printf("%s\n",__FUNCTION__);
  assert(kbuf && ksiz >= 0);
  sum = 19780211;
  for(i = ksiz - 1; i >= 0; i--){
    sum = sum * 37 + ((const unsigned char *)kbuf)[i];
  }
  return (sum * 43321879) & 0x7FFFFFFF;
}


/* Get the third hash value.
   `kbuf' specifies the pointer to the region of a key.
   `ksiz' specifies the size of the key.
   The return value is 31 bit hash value of the key. */
static int dpthirdhash(const char *kbuf, int ksiz){
  unsigned int sum;
  int i;
//printf("%s\n",__FUNCTION__);
  assert(kbuf && ksiz >= 0);
  sum = 774831917;
  for(i = ksiz - 1; i >= 0; i--){
     sum = sum * 29 + ((const unsigned char *)kbuf)[i];
 }
  return (sum * 5157883) & 0x7FFFFFFF;
}


/* Get a prime number not less than a number.
   `num' specified a positive number.
   The return value is a prime number not less than the specified number. */
static int dpgetprime(int num){
  int primes[] = {
    1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 43, 47, 53, 59, 61, 71, 79, 83,
    89, 103, 109, 113, 127, 139, 157, 173, 191, 199, 223, 239, 251, 283, 317, 349,
    383, 409, 443, 479, 509, 571, 631, 701, 761, 829, 887, 953, 1021, 1151, 1279,
    1399, 1531, 1663, 1789, 1913, 2039, 2297, 2557, 2803, 3067, 3323, 3583, 3833,
    4093, 4603, 5119, 5623, 6143, 6653, 7159, 7673, 8191, 9209, 10223, 11261,
    12281, 13309, 14327, 15359, 16381, 18427, 20479, 22511, 24571, 26597, 28669,
    30713, 32749, 36857, 40949, 45053, 49139, 53239, 57331, 61417, 65521, 73727,
    81919, 90107, 98299, 106487, 114679, 122869, 131071, 147451, 163819, 180221,
    196597, 212987, 229373, 245759, 262139, 294911, 327673, 360439, 393209, 425977,
    458747, 491503, 524287, 589811, 655357, 720887, 786431, 851957, 917503, 982981,
    1048573, 1179641, 1310719, 1441771, 1572853, 1703903, 1835003, 1966079,
    2097143, 2359267, 2621431, 2883577, 3145721, 3407857, 3670013, 3932153,
    4194301, 4718579, 5242877, 5767129, 6291449, 6815741, 7340009, 7864301,
    8388593, 9437179, 10485751, 11534329, 12582893, 13631477, 14680063, 15728611,
    16777213, 18874367, 20971507, 23068667, 25165813, 27262931, 29360087, 31457269,
    33554393, 37748717, 41943023, 46137319, 50331599, 54525917, 58720253, 62914549,
    67108859, 75497467, 83886053, 92274671, 100663291, 109051903, 117440509,
    125829103, 134217689, 150994939, 167772107, 184549373, 201326557, 218103799,
    234881011, 251658227, 268435399, 301989881, 335544301, 369098707, 402653171,
    436207613, 469762043, 503316469, 536870909, 603979769, 671088637, 738197503,
    805306357, 872415211, 939524087, 1006632947, 1073741789, 1207959503,
    1342177237, 1476394991, 1610612711, 1744830457, 1879048183, 2013265907, -1
  };
  int i;
  assert(num > 0);
  for(i = 0; primes[i] > 0; i++){
    if(num <= primes[i]) return primes[i];
  }
  return primes[i-1];
}


/* Get the padding size of a record.
   `vsiz' specifies the size of the value of a record.
   The return value is the padding size of a record. */
static int dppadsize(DEPOT *depot, int vsiz){
  int mod;
  assert(depot && vsiz >= 0);
  if(depot->align > 0){
    mod = vsiz % depot->align;
    return mod == 0 ? 0 : depot->align - mod;
  } else if(depot->align < 0){
    return (int)(vsiz * (2.0 / (1 << -(depot->align))));
  }
  return 0;
}


/* Get the size of a record in a database file.
   `head' specifies the header of  a record.
   The return value is the size of a record in a database file. */
static int dprecsize(int *head){
  assert(head);
  return DP_RHNUM * sizeof(int) + head[DP_RHIKSIZ] + head[DP_RHIVSIZ] + head[DP_RHIPSIZ];
}


/* Read the header of a record.
   `depot' specifies a database handle.
   `off' specifies an offset of the database file.
   `head' specifies a buffer for the header.
   The return value is true if successful, else, it is false. */
static int dprechead(DEPOT *depot, int off, int *head){
  assert(depot && off >= 0 && head);
  if(off > depot->fsiz){
    dpecode = DP_EBROKEN;
    return FALSE;
  }
  if(!dpseekread(depot->fd, off, head, DP_RHNUM * sizeof(int))) return FALSE;
  if(head[DP_RHIKSIZ] < 0 || head[DP_RHIVSIZ] < 0 || DP_RHIPSIZ < 0 ||
     head[DP_RHILEFT] < 0 || head[DP_RHIRIGHT] < 0){
    dpecode = DP_EBROKEN;
    return FALSE;
  }
  return TRUE;
}


/* Read the entitiy of the key of a record.
   `depot' specifies a database handle.
   `off' specifies an offset of the database file.
   `head' specifies the header of a record.
   The return value is a key data whose region is allocated by `malloc', or NULL on failure. */
static char *dpreckey(DEPOT *depot, int off, int *head){
  char *kbuf;
  int ksiz;
  assert(depot && off >= 0);
  ksiz = head[DP_RHIKSIZ];
  kbuf = (char *)malloc(ksiz + 1);
  if(!(kbuf)){
    dpecode = DP_EALLOC;
    return NULL;
  }
  if(!dpseekread(depot->fd, off + DP_RHNUM * sizeof(int), kbuf, ksiz)){
    free(kbuf);
    return NULL;
  }
  kbuf[ksiz] = '\0';
  return kbuf;
}


/* Read the entitiy of the value of a record.
   `depot' specifies a database handle.
   `off' specifies an offset of the database file.
   `head' specifies the header of a record.
   `start' specifies the offset address of the beginning of the region of the value to be read.
   `max' specifies the max size to be read.  If it is negative, the size to read is unlimited.
   The return value is a value data whose region is allocated by `malloc', or NULL on failure. */
static char *dprecval(DEPOT *depot, int off, int *head, int start, int max){
  char *vbuf;
  int vsiz;
  assert(depot && off >= 0 && start >= 0);
  head[DP_RHIVSIZ] -= start;
  if(max < 0){
    vsiz = head[DP_RHIVSIZ];
  } else {
    vsiz = max < head[DP_RHIVSIZ] ? max : head[DP_RHIVSIZ];
  }
  vbuf = (char *) malloc(vsiz + 1);
  if(!(vbuf)){
    dpecode = DP_EALLOC;
    return NULL;
  }
  if(!dpseekread(depot->fd, off + DP_RHNUM * sizeof(int) + head[DP_RHIKSIZ] + start, vbuf, vsiz)){
    free(vbuf);
    return NULL;
  }
  vbuf[vsiz] = '\0';
  return vbuf;
}


/* Compare two keys.
   `abuf' specifies the pointer to the region of the former.
   `asiz' specifies the size of the region.
   `bbuf' specifies the pointer to the region of the latter.
   `bsiz' specifies the size of the region.
   The return value is 0 if two equals, positive if the formar is big, else, negative. */
static int dpkeycmp(const char *abuf, int asiz, const char *bbuf, int bsiz)
{ int rc;
  assert(abuf && asiz >= 0 && bbuf && bsiz >= 0);
  if(asiz > bsiz) return 1;
  if(asiz < bsiz) return -1;
  rc = memcmp(abuf, bbuf, asiz);
  return rc;
}


/* Search a record.
   `depot' specifies a database handle.
   `kbuf' specifies the pointer to the region of a key.
   `ksiz' specifies the size of the region.
   `hash' specifies the second hash value of the key.
   `bip' specifies the pointer to the region to assign the index of the corresponding record.
   `offp' specifies the pointer to the region to assign the last visited node in the hash chain,
   or, -1 if the hash chain is empty.
   `entp' specifies the offset of the last used joint, or, -1 if the hash chain is empty.
   `head' specifies the pointer to the region to store the header of the last visited record in.
   `delhit' specifies whether a deleted record corresponds or not.
   The return value is 0 if successful, 1 if there is no corresponding record, -1 on error. */
static int dprecsearch(DEPOT *depot, const char *kbuf, int ksiz, int hash,
                       int *bip, int *offp, int *entp, int *head, int delhit){
  int off, entoff, thash, kcmp;
  char *tkey;
  assert(depot && kbuf && ksiz >= 0 && hash >= 0 && bip && offp && entp && head);
  *bip = dpfirsthash(kbuf, ksiz) % depot->bnum;
  off = depot->buckets[*bip];
  *offp = -1;
  *entp = -1;
  entoff = -1;
  while(off != 0){
    if(!dprechead(depot, off, head)) return -1;
    thash = head[DP_RHIHASH];
    if(hash > thash){
      entoff = off + DP_RHILEFT * sizeof(int);
      off = head[DP_RHILEFT];
    } else if(hash < thash){
      entoff = off + DP_RHIRIGHT * sizeof(int);
      off = head[DP_RHIRIGHT];
    } else {
      if(!(tkey = dpreckey(depot, off, head))) return -1;
      kcmp = dpkeycmp(kbuf, ksiz, tkey, head[DP_RHIKSIZ]);
      free(tkey);
      if(kcmp > 0){
        entoff = off + DP_RHILEFT * sizeof(int);
        off = head[DP_RHILEFT];
      } else if(kcmp < 0){
        entoff = off + DP_RHIRIGHT * sizeof(int);
        off = head[DP_RHIRIGHT];
      } else {
        if(!delhit && (head[DP_RHIFLAGS] & DP_RECFDEL)){
          entoff = off + DP_RHILEFT * sizeof(int);
          off = head[DP_RHILEFT];
        } else {
          *offp = off;
          *entp = entoff;
          return 0;
        }
      }
    }
  }
  *offp = off;
  *entp = entoff;
  return 1;
}


/* Overwrite a record.
   `depot' specifies a database handle.
   `off' specifies the offset of the database file.
   `rsiz' specifies the size of the existing record.
   `kbuf' specifies the pointer to the region of a key.
   `ksiz' specifies the size of the region.
   `vbuf' specifies the pointer to the region of a value.
   `vsiz' specifies the size of the region.
   `hash' specifies the second hash value of the key.
   `left' specifies the offset of the left child.
   `right' specifies the offset of the right child.
   The return value is true if successful, or, false on failure. */
static int dprecrewrite(DEPOT *depot, int off, int rsiz, const char *kbuf, int ksiz,
                        const char *vbuf, int vsiz, int hash, int left, int right){
  int head[DP_RHNUM], psiz, hoff, koff, voff, c;
  assert(depot && off >= 1 && rsiz > 0 && kbuf && ksiz >= 0 && vbuf && vsiz >= 0);
//printf("%s\n",__FUNCTION__);
  psiz = rsiz - sizeof(head) - ksiz - vsiz;
  head[DP_RHIFLAGS] = 0;
  head[DP_RHIHASH] = hash;
  head[DP_RHIKSIZ] = ksiz;
  head[DP_RHIVSIZ] = vsiz;
  head[DP_RHIPSIZ] = psiz;
  head[DP_RHILEFT] = left;
  head[DP_RHIRIGHT] = right;
  hoff = off;
  koff = hoff + sizeof(head);
  voff = koff + ksiz;
  c = 0;
  if(!dpseekwrite(depot->fd, hoff, head, sizeof(head)) ||
     !dpseekwrite(depot->fd, koff, kbuf, ksiz) ||
     !dpseekwrite(depot->fd, voff, vbuf, vsiz) ||
     (psiz > 0 && !dpseekwrite(depot->fd, voff + vsiz + psiz - 1, &c, 1))) return FALSE;
  return TRUE;
}


/* Write a record at the end of a database file.
   `depot' specifies a database handle.
   `kbuf' specifies the pointer to the region of a key.
   `ksiz' specifies the size of the region.
   `vbuf' specifies the pointer to the region of a value.
   `vsiz' specifies the size of the region.
   `hash' specifies the second hash value of the key.
   `left' specifies the offset of the left child.
   `right' specifies the offset of the right child.
   The return value is the offset of the record, or, -1 on failure. */
static int dprecappend(DEPOT *depot, const char *kbuf, int ksiz, const char *vbuf, int vsiz,
                       int hash, int left, int right){
  int head[DP_RHNUM], psiz, off, hoff, koff, voff, c;
  assert(depot && kbuf && ksiz >= 0 && vbuf && vsiz >= 0);
  psiz = dppadsize(depot, vsiz);
  head[DP_RHIFLAGS] = 0;
  head[DP_RHIHASH] = hash;
  head[DP_RHIKSIZ] = ksiz;
  head[DP_RHIVSIZ] = vsiz;
  head[DP_RHIPSIZ] = psiz;
  head[DP_RHILEFT] = left;
  head[DP_RHIRIGHT] = right;
  off = depot->fsiz;
  hoff = off;
  koff = hoff + sizeof(head);
  voff = koff + ksiz;
  c = 0;
  if(!dpseekwrite(depot->fd, hoff, head, sizeof(head)) ||
     !dpseekwrite(depot->fd, koff, kbuf, ksiz) ||
     !dpseekwrite(depot->fd, voff, vbuf, vsiz) ||
     (psiz > 0 && !dpseekwrite(depot->fd, voff + vsiz + psiz - 1, &c, 1))) return -1;
  depot->fsiz += sizeof(head) + vsiz + ksiz + psiz;
  return off;
}


/* Overwrite the value of a record.
   `depot' specifies a database handle.
   `off' specifies the offset of the database file.
   `head' specifies the header of the record.
   `vbuf' specifies the pointer to the region of a value.
   `vsiz' specifies the size of the region.
   `cat' specifies whether it is concatenate mode or not.
   The return value is true if successful, or, false on failure. */
static int dprecover(DEPOT *depot, int off, int *head, const char *vbuf, int vsiz, int cat){
  int hsiz, hoff, voff;
  assert(depot && off >= 0 && head && vbuf && vsiz >= 0);
  if(depot->mroff == off) depot->mroff = -1;
  if(cat){
    head[DP_RHIFLAGS] = 0;
    head[DP_RHIPSIZ] -= vsiz;
    head[DP_RHIVSIZ] += vsiz;
    hsiz = DP_RHNUM * sizeof(int);
    hoff = off;
    voff = hoff + DP_RHNUM * sizeof(int) + head[DP_RHIKSIZ] + head[DP_RHIVSIZ] - vsiz;
  } else {
    head[DP_RHIFLAGS] = 0;
    head[DP_RHIPSIZ] += head[DP_RHIVSIZ] - vsiz;
    head[DP_RHIVSIZ] = vsiz;
    hsiz = DP_RHNUM * sizeof(int);
    hoff = off;
    voff = hoff + DP_RHNUM * sizeof(int) + head[DP_RHIKSIZ];
  }
  if(!dpseekwrite(depot->fd, hoff, head, hsiz) ||
     !dpseekwrite(depot->fd, voff, vbuf, vsiz)) return FALSE;
  return TRUE;
}


/* Delete a record.
   `depot' specifies a database handle.
   `off' specifies the offset of the database file.
   `head' specifies the header of the record.
   `reusable' specifies whether the region is reusable or not.
   The return value is true if successful, or, false on failure. */
static int dprecdelete(DEPOT *depot, int off, int *head, int reusable){
  assert(depot && off >= 0 && head);
  if(reusable){
    depot->mroff = off;
    depot->mrsiz = dprecsize(head);
  }
  return dpseekwritenum(depot->fd, off + DP_RHIFLAGS * sizeof(int),
                        DP_RECFDEL | (reusable ? DP_RECFREUSE : 0));
}



/* END OF FILE */
