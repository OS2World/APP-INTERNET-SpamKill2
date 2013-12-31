/* шаблон универсального пайпного клиента */
/* main.cpp */
#define DEBUG 0

#define INCL_DOS
#define  INCL_BASE
#include <os2.h>

#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <builtin.h>
#include <signal.h>


#include "LSClServer.hpp"

#define VERSION "0.08"
#define sgLogError printf

/* Internal functions prototypes */
void usage(void);
char * sg_fgets(char *buf, int buflen, int fd);
int sg_puts(char *buf, int fd);

int SendQueryToServer(char *qurl, char *bufout,int bufoutlen);
int QueryProcessType(void);


struct LogFileStat *globalErrorLog = NULL;
struct LogFile *globalLogFile = NULL;

struct LogFileStat *lastLogFileStat;
struct LogFileStat *LogFileStat;


char **globalArgv ;
char **globalEnvp ;

int globalDebug = 0;
int globalPid = 0;
char *globalLogDir = NULL;

int sockSquid= -1;
static const char *hello_string = "hi there\n";
char *progname;
char *ExternMachine = NULL;

class NPipe SQDRpipe;


HMTX   SQDR_hmtx     = NULLHANDLE; /* Mutex semaphore handle */

int main(int argc, char *argv[], char *envp[])
{
  int ch,i,ii,rep, data, l, Nargc, ncmd, rc,rc0=99, isfound=0;
static  char buf[MAX_BUF], PipeName[256],bufout[MAX_BUF];
  char str[256], *Nargv[256];
  char *redirect;
  time_t t;
      int fd=-1;
      int t0,t01;

  Nargc = argc;
  for(i=0; i<Nargc;i++) Nargv[i] = argv[i];
  progname = argv[0];

  if(argc == 1 || !stricmp(argv[1],"-help") || !stricmp(argv[1],"/help") ||  !stricmp(argv[1],"-?") || !stricmp(argv[1],"/?"))
  {  usage();
     exit(-1);
  }

  if(!stricmp(argv[1],"-remote") )
  {   if(argc <= 3)
      { usage();
        exit(-1);
      }
      ExternMachine = argv[2];
      Nargc -= 2;
      for(i=1; i<Nargc;i++) Nargv[i] = argv[i+2];
  }

  globalArgv = argv;
  globalEnvp = envp;

/*****************************************************/

    rc = DosOpenMutexSem(CST_MUTEXSEM_NAME,      /* Semaphore name */
                         &SQDR_hmtx);            /* Handle returned */

//printf("[%i] DosOpenMutexSem rc=%i  ",globalPid,rc); fflush(stdout);

    DosCloseMutexSem(SQDR_hmtx);
    isfound = 0;
 for(rep=0;rep<40+MAX_NUM_PIPES; rep++)
 {
   for(i=0;i<MAX_NUM_PIPES;i++)
   {  ii = i;
      if(ExternMachine)
      {  if(ii) sprintf(buf,"\\\\%s\\%s%i",ExternMachine,CST_BASE_PIPE_NAME,ii);
         else sprintf(buf,"\\\\%s\\%s",ExternMachine,CST_BASE_PIPE_NAME);
      } else {
         if(ii) sprintf(buf,"%s%i",CST_BASE_PIPE_NAME,ii);
         else strcpy(buf,CST_BASE_PIPE_NAME);
      }
      strcpy(PipeName,buf);
      SQDRpipe = NPipe(buf,CLIENT_MODE);

      rc = SQDRpipe.Open();
      if(rc == ERROR_PIPE_BUSY)
               continue;
      if(rc == ERROR_PATH_NOT_FOUND)
      { continue;
      }
      if(rc)
      {  sgLogError("Error open pipe %s rc=%i", PipeName,rc);
         if(rc == ERROR_INVALID_PARAMETER) printf("(Hедопустимый паpаметp");
         exit(-1);
      }
      isfound = 1;
      break;
    }
    if(isfound) break;
    i = 0;
    if(rep > 2) i = 1 + rep/4;
    DosSleep(i);
  }
//   printf("1 Open pipe %s, i=%i ,%i,  %x, rc=%i\n",buf,i, rep, SQDRpipe.Hpipe,rc);

    if(!SQDRpipe.Hpipe)
    {
       if(ExternMachine)
         sprintf(buf,"\\\\%s\\%s[%i-%i]",ExternMachine,CST_BASE_PIPE_NAME,1,MAX_NUM_PIPES);
       else
         sprintf(buf,"%s[%i-%i]",CST_BASE_PIPE_NAME,1,MAX_NUM_PIPES);
       sgLogError("Can't open pipe(s) %s, Exitting", buf);
       exit(-2);
    }
    rc = SQDRpipe.HandShake();
//    printf("HandShake=%i\n",rc);
    if(rc ==  HAND_SHAKE_ERROR)
    {
        printf("Error handshake\n",rc);
        sgLogError("Error handshake  pipe, Exitting");
        exit(-1);
    }
/*********************/
    buf[0] = 0;
    for(i=0;i<Nargc;i++)
    {  strcat(buf,Nargv[i]);
       if(i != Nargc-1)  strcat(buf," ");
    }
    l = strlen(buf);
    rc = SQDRpipe.SendCmdToServer(Nargc,l); // команда 1 - передаем число аргументов и длину буфера
    if(!rc)
    { // printf("Send cmd %i %i\n",Nargc,l);
       rc = SQDRpipe.SendDataToServer(buf, l);  //передаем буфер
       if(!rc)
       { // printf("Send buf %s\n",buf);
          rc = SQDRpipe.RecvCmdFromClient(&ncmd, &data); //получаем код возврата
          if(!rc && ncmd != 0)   //ncmd = 0 == Pipe closed
             rc0 = ncmd;
//    printf("Send cmd %s rc=%i\n",buf,rc0);
//          printf("Get  %i (rc=%i)\n",ncmd, rc);
       }
    }


/*********************/
//    sgLogError("LSclient stopped, close rc=%i",rc);

   _fcloseall();

  exit(rc0);
}


void usage(void)
{
  fprintf(stderr,
         "Usage: SpamClient [-help|-?] | [-remote MachineName] [arg1 arg2 ....]\n");
  fprintf(stderr, "Options:\n");
  fprintf(stderr, "  -help|-?    : show this help msg\n");
  fprintf(stderr, "  -remote     : remote server mashine name\n");
  fprintf(stderr, "  arg1 arg2   : a set of args to send to local or remote server\n");
  exit(-1);
}


/************************/
int SendQueryToServer(char *qurl, char *bufout,int bufoutlen)
{  int l,rc,ncmd,data;
   if(!qurl)
      return -1;
   l = strlen(qurl);
   if(!l)
      return -2;
   l++; //+ zero at end of string
   rc = SQDRpipe.SendCmdToServer(1,l); // команда 1 - послать данные о запросе
   if(rc)
      return rc;
   rc = SQDRpipe.SendDataToServer((void *)qurl, l);
   if(rc)
      return rc;
   rc = SQDRpipe.RecvCmdFromClient(&ncmd,&data);
   if(rc)
      return rc;
   switch(ncmd)
   {  case 1:
        l = data;
        rc = SQDRpipe.RecvDataFromClient(bufout,&l,bufoutlen);
          break;

   }

   return rc;
}


int QueryProcessType(void)
{
    PTIB   ptib = NULL;          /* Thread information block structure  */
    PPIB   ppib = NULL;          /* Process information block structure */
    APIRET rc   = NO_ERROR;      /* Return code                         */
    int prtype;

    rc = DosGetInfoBlocks(&ptib, &ppib);
    if (rc != NO_ERROR)
    {  printf ("DosGetInfoBlocks error : rc = %u\n", rc);
          return 1;
    }

    prtype = ppib->pib_ultype;
/*
  pib_ultype (ULONG)
     Process' type code.

     The following process' type codes are available:

     0         Full screen protect-mode session
     1         Requires real mode. Dos emulation.
     2         VIO windowable protect-mode session
     3         Presentation Manager protect-mode session
     4         Detached protect-mode process.

*/
    return prtype;
}


