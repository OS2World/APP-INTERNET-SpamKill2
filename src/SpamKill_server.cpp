/* SpamKill_Server.cpp */

#define  INCL_BASE
#define INCL_DOSSEMAPHORES      /* Semaphore values */
#define INCL_DOSERRORS          /* DOS Error values */
#define INCL_DOSPROCESS
 #include <os2.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
 #include <signal.h>
#include <builtin.h>
#include <time.h>
#include <malloc.h>

#define POKA 0
#include "LSClServer.hpp"

/*+---------------------------------+*/
/*| Internal function prototypes.   |*/
/*+---------------------------------+*/
int SetupSemaphore(void);
int SetupSignals(void);
void _Optlink CLServer_cleanup(void);
int sgCheckForReloadConfig(char *fname,int checktime);
void _Optlink LS_ClientWork(void *param);


int HandleClientQuery(char *buf, char *bufout, int nclient);
int QueryProcessType(void);

/*+---------------------------------+*/
/*| External function prototypes.   |*/
/*+---------------------------------+*/
//int initAll(int configMachine, int subConfig, char confFname[], int AfterRebootMode);
//int VirtualCommandHanle(int cmd, int &data, void *buffer, class NPipe  *LSpipe);

#ifdef __cplusplus
extern "C" {
#endif
int main_bogo(int argc, char **argv, int embedded);
#ifdef __cplusplus
}
#endif

/*************************/
/* Глобальные переменные */
/*************************/
//char szConfigFname[]="Lsoi.cfg";
/* индикатор необходимости аварийного выхода из программы*/
volatile int NeedToExit = 0;


/*+--------------------------------------------------------+*/
/*| Static global variables and local constants.           |*/
/*+--------------------------------------------------------+*/
HMTX  LSServerWork_hmtx     = NULLHANDLE; /* Mutex semaphore handle */

class NPipe LS_pipe[MAX_NUM_THREADS];
struct LS_threads
{
   volatile int semaphore;    // семафор для блокировки одновременного доступа к остальным полям
   volatile int semaphoreGetThreadId;    // семафор того, что нитка записала свой ид
   int num;          // число ниток
   volatile int next_free;    // следующая свободная
   int working;      // =0 на старте, =1 после появления первого живого клиента (защелка)
   int Nclients;     // число живых клиентов
   int thread_id[MAX_NUM_THREADS]; // id'ы ниток
   int hits_total[MAX_NUM_THREADS]; // запросов всего по ниткам
   int hits_min  [MAX_NUM_THREADS]; // запросов за минуту по ниткам
   int hits_hour [MAX_NUM_THREADS]; // запросов за час    по ниткам
   int state [MAX_NUM_THREADS];     // состояние нитки: 0-свободно, 1 - занято
   volatile int threadSemaphore[MAX_NUM_THREADS]; // семафоры на каждую нитку для блокировки одновременного доступа к остальным полям
};

struct LS_threads  LSthreads = { 0,0,0,0,0,0 };


struct LogFileStat *lastLogFileStat;
struct LogFileStat *LogFileStat;
struct LogFileStat *globalErrorLog = NULL;

int globalDebug = 0;
char *globalLogDir = NULL;
char *progname_0;

int detachedMode=0;
int Config=0, subConfig =0;
volatile int Bogofilter_semaphore = UNLOCKED;

int main(int argc, char *argv[], char *envp[])
{  int i,ii,rc,id, idd, symbolName=-1;
   FILE *fp;

//   printf("%s vers %s %s\n", CST_APPLICATION_NAME, VERSION,  __DATE__);


//   initAll(Config,subConfig,szConfigFname,AfterRebootMode);
  if(argc > 1)
  {  rc = main_bogo(argc, argv, 0);
  }

   atexit(CLServer_cleanup);

   SetupSignals();

/* семафор надо устанавливать сразу */
   rc = SetupSemaphore();
   if(rc)
     exit(rc);

   progname_0 = argv[0];


   rc = QueryProcessType();
   if(rc == 4)
       detachedMode = 1;


   for(i=0;i<MAX_NUM_THREADS;i++)
   { LSthreads.thread_id[i] = -1;
      LSthreads.threadSemaphore[i] = 0;
      LSthreads.hits_total[i] = 0; // запросов всего по ниткам
      LSthreads.hits_min  [i] = 0; // запросов за минуту по ниткам
      LSthreads.hits_hour [i] = 0; // запросов за час    по ниткам
   }
   LSthreads.next_free = 0;
M0:
   LSthreads.working = 0; // нужно для организации задержки ожидания запуска первого клиента
   while(__lxchg(&LSthreads.semaphore, LOCKED)) DosSleep(1);
   idd = LSthreads.next_free;
   if(LSthreads.thread_id[idd] != -1)
   {  for(i = 0; i < MAX_NUM_THREADS; i++)
      {  if(LSthreads.thread_id[ii] == -1)
         {     idd = ii;
               break;
         }
      }
   }
   LSthreads.threadSemaphore[idd] = 1;

   for(i = 0; i < MAX_NUM_THREADS; i++)
      {  if( i == idd) continue;
         if(LSthreads.thread_id[i] == -1)
         {     LSthreads.next_free = i;
               break;
         }
      }

   __lxchg(&LSthreads.semaphore, UNLOCKED);
//   while(__lxchg(&LSthreads.semaphoreGetThreadId, LOCKED)) DosSleep(1);
printf("0 Start Thread  idd=%i",idd); fflush(stdout);

   id = _beginthread(LS_ClientWork,NULL, STACK_SIZE,(void *) &idd);
   do
   { DosSleep(1);
   } while(LSthreads.threadSemaphore[idd] == 1);

//   while(LSthreads.semaphoreGetThreadId == LOCKED) DosSleep(1);
   while(__lxchg(&LSthreads.semaphore, LOCKED)) DosSleep(1);
   LSthreads.num++;
   LSthreads.thread_id[idd] = id;
    LSthreads.threadSemaphore[idd] = 3; // отпускаем запущенную нитку в свободный полет
   __lxchg(&LSthreads.semaphore, UNLOCKED);

/* wait for first client connect */
   do
   {  DosSleep(50);
   } while (!LSthreads.working);

  /* wait for all threads exit */
   do
   {  DosSleep(50);
//      rc = sgCheckForReloadConfig(szConfigFname,10000);
//   } while (LSthreads.Nclients);
   } while (LSthreads.num);
//  if(!detachedMode)
 printf("Last Client Exitting with error...\n"); fflush(stdout);
   DosSleep(50);
   goto M0;

}


/************************************/
void _Optlink LS_ClientWork(void *param)
{   int i,rc, rc0,threadNum,id,idd;
    int ncmd,data,l;
    char PipeName[256];
    char str[512];
    char buf[MAX_BUF], bufout[MAX_BUF];

//   HAB   habThread4 = NULLHANDLE;           /* anchor block handle for thread */
//   HMQ   hmqThread4 = NULLHANDLE;           /* message queue handle           */
//   QMSG  qmsgThread4;                       /* message queue structure        */

//   habThread4 = WinInitialize( 0UL );
//   hmqThread4 = WinCreateMsgQueue( habThread4, 0UL );

    _control87(EM_UNDERFLOW,EM_UNDERFLOW);

    threadNum =  LSthreads.next_free;
    if(param)
           threadNum = * ((int *)param);
   if(LSthreads.threadSemaphore[threadNum] != 1)
   {  DosBeep(1000,100);
  //    sgLogError("!!!Error  threadSemaphore[%i]=%i, != 0",threadNum, LSthreads.threadSemaphore[threadNum]);
       printf("!!!Error  threadSemaphore[%i]=%i, != 0\n",threadNum, LSthreads.threadSemaphore[threadNum]);  fflush(stdout);
   }

     LSthreads.threadSemaphore[threadNum]++;  //=2
   do
   { DosSleep(1);
   } while(LSthreads.threadSemaphore[threadNum] != 3);

//    __lxchg(&LSthreads.semaphoreGetThreadId, UNLOCKED);

//  if(!detachedMode)
//    printf("Start thread %i\n",threadNum);  fflush(stdout);
//    sgLogError("Start thread %i",threadNum);

//    DosSleep(50);

/* */
     if(threadNum) sprintf(PipeName,"%s%i",CST_BASE_PIPE_NAME,threadNum);
     else strcpy(PipeName,CST_BASE_PIPE_NAME);

//printf("Crating pipe  %s for thread %i\n",PipeName, threadNum);  fflush(stdout);
    LS_pipe[threadNum] = NPipe(PipeName,SERVER_MODE);
    rc = LS_pipe[threadNum].Create();
    if(rc)
    {  sprintf(str, "Error pipe creating  %s rc=%i",PipeName,rc);
       if(rc == ERROR_INVALID_PARAMETER)
                   strcat(str,"(INVALID PARAMETER)");
       else
          if (rc == ERROR_PIPE_BUSY)
                   strcat(str,"(PIPE_BUSY)");
//       printf("%s\n",str);  fflush(stdout);
//       sgLogError("%s",str);

       if (rc == ERROR_PIPE_BUSY)
           printf("Закройте все клиентские программы и перезапустите сервер\n",str);  fflush(stdout);
       for(i=0;i<10;i++)
       { DosBeep(1000,5+i*10);
         DosBeep(2000+i*10,5+i*10);
       }
       for(i=0; i < MAX_NUM_PIPES; i+=2)
       {  printf("%i %x %s\t",i,LS_pipe[i].Hpipe,LS_pipe[i].name);
          printf("%i %x %s\n",i,LS_pipe[i+1].Hpipe,LS_pipe[i+1].name);
       }
//       sgLogError("Exit from thread %i",threadNum);
       printf("Exit from thread %i",threadNum);
       exit(1);
    }

    rc = LS_pipe[threadNum].Connect();
    if(rc)
    { //  sgLogError("Error connection pipe rc=%i, exit(1) from thread %i",rc,threadNum);
        printf("Error connection pipe rc=%i, exit(1) from thread %i",rc,threadNum);  fflush(stdout);
        exit(1);
    }
    rc = LS_pipe[threadNum].HandShake();
    if(rc)
    {  // sgLogError("Error HandShake pipe rc=%i, exit(2) from thread ",rc,threadNum);
        printf("Error HandShake pipe rc=%i, exit(2) from thread ",rc,threadNum);  fflush(stdout);
       exit(2);
    }

/***********/
// Заранее находим next_free, не равное idd
   while(__lxchg(&LSthreads.semaphore, LOCKED)) DosSleep(1);

   idd = LSthreads.next_free;
   if(LSthreads.threadSemaphore[idd] != 0)
   {  DosBeep(1000,1000);
    //  sgLogError("Error  threadSemaphore[%i]=%i, != 0",idd, LSthreads.threadSemaphore[idd]);
      printf("Error  threadSemaphore[%i]=%i, != 0, threadNum=%i\n",idd, LSthreads.threadSemaphore[idd],threadNum);  fflush(stdout);
   }

   for(i = 0; i < MAX_NUM_THREADS; i++)
      {  if(i == idd) continue;
         if(LSthreads.thread_id[i] == -1)
         {     LSthreads.next_free = i;
               break;
         }
      }
   __lxchg(&LSthreads.semaphore, UNLOCKED);

   LSthreads.threadSemaphore[idd] = 1;
//printf("1 Start Thread [%i] idd=%i",threadNum,idd);  fflush(stdout);
//   __lxchg(&LSthreads.semaphoreGetThreadId, LOCKED);
   id = _beginthread(LS_ClientWork,NULL, STACK_SIZE,&idd);
   do
   { DosSleep(1);
   } while(LSthreads.threadSemaphore[idd] == 1);

//   while(LSthreads.semaphoreGetThreadId == LOCKED) DosSleep(1);
   while(__lxchg(&LSthreads.semaphore, LOCKED)) DosSleep(1);

   LSthreads.Nclients++;     // число живых клиентов
   LSthreads.working = 1;    // =0 на старте, =1 после появления первого живого клиента (защелка)
   LSthreads.num++;
   LSthreads.thread_id[idd] = id;
//   VirtualCommandHanle(LSC_SET_JOB_NCLIENTS, LSthreads.Nclients, NULL,NULL);

   LSthreads.threadSemaphore[idd] = 3;
   __lxchg(&LSthreads.semaphore, UNLOCKED);
    LSthreads.state[threadNum]=0;

      LSthreads.state[threadNum]=0;
      rc = LS_pipe[threadNum].RecvCmdFromClient(&ncmd,&data);
      if(rc)
      {
         if(rc == -1)
         {  rc = LS_pipe[threadNum].QueryState();
            if(rc == ERROR_BAD_PIPE || rc == ERROR_PIPE_NOT_CONNECTED)
                                  goto END; // клиент подох ??
         }
         if(!detachedMode)
                printf("Recv error=%i\n",rc);
//          sgLogError("Recv error=%i ",rc);
//???????          exit(1);
      }
      LSthreads.state[threadNum]=1;
      // printf("Get Cmd=%i,data=%i\n",ncmd,data); fflush(stdout);
//  rc = SQDRpipe.SendCmdToServer(Nargc,l); // команда 1 - передаем число аргументов и длину буфера
     {  int Nargc,l, l1;
        char *Nargv[256], *tok;
        Nargc = ncmd;
        if(Nargc > 256) Nargc = 256;
        l = data;
        if(l > sizeof(buf)) l = sizeof(buf)-1;
        rc = LS_pipe[threadNum].RecvDataFromClient(&buf,&l1, l);
        if(rc)   goto END; // клиент подох ??

        buf[l] = 0;
        for(i = 0; i < Nargc; i++)
        { if(i == 0) tok = strtok(buf," ");
          else       tok = strtok(NULL," ");
          if(!tok)
              break;
          Nargv[i] = tok;
        }
//        printf("Nargc=%i\n",Nargc);
//        for(i = 0; i < Nargc; i++)
//               printf("%i = %s\n",i, Nargv[i]);

//bogofilter still single-thread
   while(__lxchg(&Bogofilter_semaphore, LOCKED))
                                       DosSleep(1);

        rc0 = main_bogo(Nargc, Nargv,1);

   __lxchg(&Bogofilter_semaphore, UNLOCKED);     //cmd=0 == Pipe closed, поэтому делаем +1
        rc = LS_pipe[threadNum].SendCmdToServer(rc0+1, 0);
//        printf("SendCmdToServer [%i] rc=%i\n",threadNum,rc);  fflush(stdout);
     }

END:
    LSthreads.state[threadNum]=0;
    LS_pipe[threadNum].Close();
//    printf("LS_pipe[%i].Close\n",threadNum);  fflush(stdout);

//   sgLogError("Ending thread %i...",threadNum);
   while(__lxchg(&LSthreads.semaphore, LOCKED))
                                       DosSleep(1);
//   sgLogError("End thread %i",threadNum);
   LSthreads.num--;
   LSthreads.thread_id[threadNum] = -1;
   LSthreads.threadSemaphore[threadNum] = 0;
   LSthreads.next_free = threadNum;
   for(i = 0; i < threadNum; i++)
   {   if(LSthreads.thread_id[i] == -1)
       {     LSthreads.next_free = i;
              break;
       }
   }

   LSthreads.Nclients--;     // число живых клиентов
//   VirtualCommandHanle(LSC_SET_JOB_NCLIENTS, LSthreads.Nclients, NULL,NULL);
   __lxchg(&LSthreads.semaphore, UNLOCKED);

//   printf("End thread %i\n",threadNum);  fflush(stdout);

    DosSleep(1);

//  _endthread();
}


/*********************************/
/* Обслуживание запроса клиента  */
/*********************************/



/*******************************************/

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

/**************************************/
void _Optlink CLServer_cleanup(void)
{   int rc;

//    lprgs.Write(szConfigFname);

/* в последнюю очередь освобождаем семафор */
    if(LSServerWork_hmtx)
    {   rc = DosReleaseMutexSem(LSServerWork_hmtx);        /* Relinquish ownership */
        rc = DosCloseMutexSem(LSServerWork_hmtx);          /* Close mutex semaphore */
    }
}

int SetupSemaphore(void)
{
 PID     pidOwner = 0;          /* PID of current mutex semaphore owner */
 TID     tidOwner = 0;          /* TID of current mutex semaphore owner */
 ULONG   ulCount  = 0;          /* Request count for the semaphore */
 APIRET  rc       = NO_ERROR;   /* Return code */

    rc = DosCreateMutexSem(CST_MUTEXSEM_NAME,      /* Semaphore name */
                           &LSServerWork_hmtx, 0, FALSE);  /* Handle returned */
    if (rc != NO_ERROR)
    {
       if(rc == ERROR_DUPLICATE_NAME)
              printf(CST_APPLICATION_NAME " already running\n");
       else
              printf("DosCreateMutexSem error: return code = %u\n", rc);
       return 1;
     }
//  if(!detachedMode)
//       printf("DosCreateMutexSem %i\n",__LINE__);
         /* This would normally be done by another unit of work */
    rc = DosOpenMutexSem(CST_MUTEXSEM_NAME,      /* Semaphore name */
                         &LSServerWork_hmtx);            /* Handle returned */
    if (rc != NO_ERROR) {
       printf("DosOpenMutexSem error: return code = %u\n", rc);
       return 1;
     }
//  if(!detachedMode)
//       printf("DosOpenMutexSem %i\n",__LINE__);

    rc = DosRequestMutexSem(LSServerWork_hmtx,      /* Handle of semaphore */
                            (ULONG) 1000);  /* Timeout  */
    if (rc != NO_ERROR) {
       printf("DosRequestMutexSem error: return code = %u\n", rc);
       return 1;
    }
//  if(!detachedMode)
//      printf("DosRequestMutexSem %i\n",__LINE__);

    rc = DosQueryMutexSem(LSServerWork_hmtx,         /* Handle of semaphore */
                          &pidOwner,    /* Process ID of owner */
                          &tidOwner,    /* Thread ID of owner */
                          &ulCount);    /* Count */
    if (rc != NO_ERROR) {
       printf("DosQueryMutexSem error: return code = %u\n", rc);
       return 1;
    } else if (!detachedMode)  {
       printf("Semaphore owned by PID %u, TID %u.", pidOwner, tidOwner);
       printf("  Request count is %u.\n", ulCount);
    } /* endif */

//  if(!detachedMode)
//       printf("DosQueryMutexSem %i\n",__LINE__);

 return NO_ERROR;
 }

/*******************************************/
static char *SignalCodes[]=
{  "None",
    "illegal instruction - invalid function image", /* SIGILL 1 */
    "invalid access to memory",  /* SIGSEGV      2  */
    "floating point exception ", /* SIGFPE       3  */
    "OS/2 SIGTERM (killprocess) signal", /* SIGTERM      4 */
    "abort() signal",       /* SIGABRT      5 */
    "OS/2 SIGINTR signal",  /* SIGINT       6 */
    "user exception in range 0xa0000000 - 0xbfffffff",  /* SIGINT       7 */
    "user exception in range 0xc0000000 - 0xdfffffff",  /* SIGINT       8 */
    "user exception in range 0xe0000000 - 0xffffffff",  /* SIGINT       9 */
    "OS/2 Ctrl-Break sequence",  /* SIGBREAK    10 */
    NULL
};
//extern "C"  void  TestTempSignalHandler(int sig)
extern "C"  void   CLServer_cleanupHandler(int sig)
 {
    char str[100];
    ULONG Wrote;
    int rc;

    NeedToExit = 1; /* всем остальным ниткам надо срочно сваливать */
    sprintf(str, "\nSignal occurred %x : %s\n\r", sig,SignalCodes[sig]);
    DosWrite(2, (PVOID)str, strlen(str), &Wrote);
    rc = 1;

    exit(1);
 }

/* На случай ошибки fp      */
extern "C"  void   CLServer_cleanupHandlerFP(int sig)
{  static int raz=0;
  _fpreset();

  if(++raz  > 1000000)
           NeedToExit = 1; /* всем остальным ниткам надо срочно сваливать */

//    sgLogError("FP Signal occurred %i",sig);
    printf("FP Signal occurred %i",sig);

   if (SIG_ERR == signal(SIGFPE, CLServer_cleanupHandlerFP)) {
       perror("Could not set SIGFPE");
       exit(10);
    }
  if(++raz  > 2000000)
       exit(20);

}


int SetupSignals(void)
 {
    if (SIG_ERR == signal(SIGABRT, CLServer_cleanupHandler)) {
       perror("Could not set SIGABRT");
       return EXIT_FAILURE;
    }

    if (SIG_ERR == signal(SIGBREAK, CLServer_cleanupHandler)) {
       perror("Could not set SIGBREAK");
       return EXIT_FAILURE;
    }

    if (SIG_ERR == signal(SIGINT, CLServer_cleanupHandler)) {
       perror("Could not set SIGINT");
       return EXIT_FAILURE;
    }

   if (SIG_ERR == signal(SIGFPE, CLServer_cleanupHandlerFP)) {
       perror("Could not set SIGFPE");
       return EXIT_FAILURE;
    }
    if (SIG_ERR == signal(SIGSEGV, CLServer_cleanupHandler)) {
       perror("Could not set SIGSEGV");
       return EXIT_FAILURE;
    }
    if (SIG_ERR == signal(SIGILL, CLServer_cleanupHandler)) {
       perror("Could not set SIGILL");
       return EXIT_FAILURE;
    }
    return 0;
 }


