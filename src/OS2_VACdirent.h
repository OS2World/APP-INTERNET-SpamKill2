/* OS2_VACdirent.h */

#ifndef OS2_VACDIRENT_H
#define OS2_VACDIRENT_H

struct _dircontents
{
  char *                _d_entry;
  long                  _d_size;
  unsigned short        _d_attr;
  unsigned short        _d_time;
  unsigned short        _d_date;
  struct _dircontents * _d_next;
};

struct dir_ent
{  char d_name[FILENAME_MAX]; /* File name, 0 terminated   */
};

struct _dirdesc
{
  int                   dd_id;
  long                  dd_loc;
  struct _dircontents * dd_contents;
  struct _dircontents * dd_cp;
  struct dir_ent       d_ent;
  HDIR          hdirFindHandle;
  FILEFINDBUF3  FindBuffer;      /* Returned from FindFirst/Next */
  int last_rc;                   /* last rc code */
};

typedef struct _dirdesc DIR;
#define dirent  dir_ent 

DIR *opendir(char *name);
int closedir(DIR *dirp);
struct dir_ent *readdir(DIR *dirp);



#endif
 //OS2_VACDIRENT_H
