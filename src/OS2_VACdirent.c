/* OS2_VACdirent.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

 #define INCL_DOS
 #include <os2.h>
#include <errno.h>
#include <nerrno.h>
#include <OS2WERR.H> // ToolKit

#include "os2_ErrCodes.h"

#include "OS2_VACdirent.h"

#define xfree    free
#define xmalloc  malloc
#define xcalloc  calloc

/* External functions */
char * GetOS2ErrorMessage(int ierr);

struct dir_ent *readdir(DIR *dirp)
{  int    rc;
   ULONG  ulResultBufLen = sizeof(FILEFINDBUF3);
   ULONG  ulFindCount    = 1;        /* Look for 1 file at a time    */

   if(dirp->last_rc == ERROR_NO_MORE_FILES)
            return NULL;

/* Keep finding the next file until there are no more files */
//     while (rc != ERROR_NO_MORE_FILES) {

    rc = DosFindNext(dirp->hdirFindHandle,      /* Directory handle             */
                     &dirp->FindBuffer,         /* Result buffer                */
                     ulResultBufLen,      /* Result buffer length         */
                     &ulFindCount);       /* Number of entries to find    */

    if (rc != NO_ERROR && rc != ERROR_NO_MORE_FILES)
    {   printf("readdir:WARNING: rc =%d, %s\n", rc, GetOS2ErrorMessage(rc));
        return NULL;
    } else if(rc ==  ERROR_NO_MORE_FILES) {
         dirp->last_rc = rc;
         return NULL;
    }
    strcpy(dirp->d_ent.d_name,dirp->FindBuffer.achName);
//     } /* endwhile */
   dirp->last_rc = rc;

   return &(dirp->d_ent);
}

int closedir(DIR *dirp)
{  int rc;

//     rc = DosFindClose(hdirFindHandle);    /* Close our directory handle */
//     if (rc != NO_ERROR) {
//        printf("DosFindClose error: return code = %u\n",rc);
//        return 1;
//     }
   if(dirp)
   {   rc = DosFindClose(dirp->hdirFindHandle);    /* Close our directory handle */
       xfree((void *)dirp);
       if (rc != NO_ERROR)
          return 1;
   }
   return 0;
}
//  #define INCL_DOSFILEMGR   /* File Manager values */
//  #define INCL_DOSERRORS    /* DOS error values */
//  #include <os2.h>
//  #include <stdio.h>

DIR *opendir(char *name)
{
     HDIR          hdirFindHandle = HDIR_CREATE;
     FILEFINDBUF3  FindBuffer     = {0};      /* Returned from FindFirst/Next */
     ULONG         ulResultBufLen = sizeof(FILEFINDBUF3);
     ULONG         ulFindCount    = 1;        /* Look for 1 file at a time    */
     APIRET        rc             = NO_ERROR; /* Return code                  */
     char fname[FILENAME_MAX];
     int l,i, *ptmp;
     DIR *pdir;

     strcpy(fname,name);
     strcat(fname,"/*.*");
     rc = DosFindFirst( fname,                /* File pattern - all files     */
                        &hdirFindHandle,      /* Directory search handle      */
             FILE_DIRECTORY|FILE_NORMAL,      /* Search attribute             */
                        &FindBuffer,          /* Result buffer                */
                        ulResultBufLen,       /* Result buffer length         */
                        &ulFindCount,         /* Number of entries to find    */
                        FIL_STANDARD);        /* Return Level 1 file info     */
    if(rc != NO_ERROR)
    {   int dl=0;
        if(rc == ERROR_FILE_NOT_FOUND || rc == ERROR_PATH_NOT_FOUND) dl = 1;
        printf("opendir:WARNING: rc =%d, %s\n", rc, GetOS2ErrorMessage(rc));
        return NULL;
    }

     i = sizeof(DIR);

     pdir = (DIR *) xcalloc(i,1);
     pdir->hdirFindHandle = hdirFindHandle;
     pdir->FindBuffer = FindBuffer;
     pdir->last_rc = rc;

     return pdir;
}

char * GetOS2ErrorMessage(int ierr)
{ int i;
static char *Unknown = "Unknown";
  for(i=0; i< sizeof(OS2_ErrMessages) / sizeof(struct OS2_ErrMsg); i++)
  {  if(ierr == OS2_ErrMessages[i].ierrcode)
          return OS2_ErrMessages[i].msg;
  }
  return Unknown;
}

