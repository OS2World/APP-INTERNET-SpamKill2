# makefile
# Created by IBM WorkFrame/2 MakeMake at 21:11:49 on 6 Nov 2003
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker

.SUFFIXES:

.SUFFIXES: \
    .c .cpp .obj 

.c.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Tl16 /IQDBM /Ispecfunc /Ss /Q /Wclscmpcndcnscnvcpydcleffenuextgengnrgotinilanobsordparporppcprorearettrdtruunduniuse /O /Gm /G5 /Gf /Gi /Oi /C %s

{G:\EVGEN\INET\SpamKill\BFilter\src}.c.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Tl16 /IQDBM /Ispecfunc /Ss /Q /Wclscmpcndcnscnvcpydcleffenuextgengnrgotinilanobsordparporppcprorearettrdtruunduniuse /O /Gm /G5 /Gf /Gi /Oi /C %s

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Tl16 /IQDBM /Ispecfunc /Ss /Q /Wclscmpcndcnscnvcpydcleffenuextgengnrgotinilanobsordparporppcprorearettrdtruunduniuse /O /Gm /G5 /Gf /Gi /Oi /C %s

{G:\EVGEN\INET\SpamKill\BFilter\src}.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Tl16 /IQDBM /Ispecfunc /Ss /Q /Wclscmpcndcnscnvcpydcleffenuextgengnrgotinilanobsordparporppcprorearettrdtruunduniuse /O /Gm /G5 /Gf /Gi /Oi /C %s

all: \
    .\SpamKill2.exe

.\SpamKill2.exe: \
    .\xstrdup.obj \
    .\xstrlcpy.obj \
    .\base64.obj \
    .\bf_exit.obj \
    .\bogoconfig.obj \
    .\bogofilter.obj \
    .\bogoreader.obj \
    .\bool.obj \
    .\buff.obj \
    .\charset.obj \
    .\collect.obj \
    .\configfile.obj \
    .\datastore.obj \
    .\datastore_qdbm.obj \
    .\db_error.obj \
    .\debug.obj \
    .\degen.obj \
    .\depot.obj \
    .\error.obj \
    .\fgetsl.obj \
    .\find_home.obj \
    .\find_home_tildeexpand.obj \
    .\find_home_user.obj \
    .\fisher.obj \
    .\format.obj \
    .\getopt.obj \
    .\globals.obj \
    .\graham.obj \
    .\ipmpar.obj \
    .\lexer.obj \
    .\lexer_v3.obj \
    .\main.obj \
    .\maint.obj \
    .\method.obj \
    .\mime.obj \
    .\msgcounts.obj \
    .\myconf.obj \
    .\OS2_VACdirent.obj \
    .\passthrough.obj \
    .\paths.obj \
    .\qp.obj \
    .\register.obj \
    .\robinson.obj \
    .\rstats.obj \
    .\snprintf.obj \
    .\SpamKill_server.obj \
    .\strlcat.obj \
    .\strlcpy.obj \
    .\swap_32bit.obj \
    .\system.obj \
    .\textblock.obj \
    .\token.obj \
    .\transaction.obj \
    .\uudecode.obj \
    .\word.obj \
    .\wordhash.obj \
    .\wordlists.obj \
    .\wordlists_base.obj \
    .\xatof.obj \
    .\xatoi.obj \
    .\xcalloc.obj \
    .\xmalloc.obj \
    .\xmemrchr.obj \
    .\xmem_error.obj \
    .\xrealloc.obj \
    {$(LIB)}gsl.lib
    @echo " Link::Linker "
    icc.exe @<<
     /B" /exepack:2 /st:200000 /packd /optfunc"
     /FeSpamKill2.exe 
     gsl.lib 
     .\xstrdup.obj
     .\xstrlcpy.obj
     .\base64.obj
     .\bf_exit.obj
     .\bogoconfig.obj
     .\bogofilter.obj
     .\bogoreader.obj
     .\bool.obj
     .\buff.obj
     .\charset.obj
     .\collect.obj
     .\configfile.obj
     .\datastore.obj
     .\datastore_qdbm.obj
     .\db_error.obj
     .\debug.obj
     .\degen.obj
     .\depot.obj
     .\error.obj
     .\fgetsl.obj
     .\find_home.obj
     .\find_home_tildeexpand.obj
     .\find_home_user.obj
     .\fisher.obj
     .\format.obj
     .\getopt.obj
     .\globals.obj
     .\graham.obj
     .\ipmpar.obj
     .\lexer.obj
     .\lexer_v3.obj
     .\main.obj
     .\maint.obj
     .\method.obj
     .\mime.obj
     .\msgcounts.obj
     .\myconf.obj
     .\OS2_VACdirent.obj
     .\passthrough.obj
     .\paths.obj
     .\qp.obj
     .\register.obj
     .\robinson.obj
     .\rstats.obj
     .\snprintf.obj
     .\SpamKill_server.obj
     .\strlcat.obj
     .\strlcpy.obj
     .\swap_32bit.obj
     .\system.obj
     .\textblock.obj
     .\token.obj
     .\transaction.obj
     .\uudecode.obj
     .\word.obj
     .\wordhash.obj
     .\wordlists.obj
     .\wordlists_base.obj
     .\xatof.obj
     .\xatoi.obj
     .\xcalloc.obj
     .\xmalloc.obj
     .\xmemrchr.obj
     .\xmem_error.obj
     .\xrealloc.obj
<<

.\xstrdup.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\xstrdup.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrdup.h

.\xrealloc.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\xrealloc.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h

.\xmem_error.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\xmem_error.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h

.\xmemrchr.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\xmemrchr.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmemrchr.h

.\xmalloc.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\xmalloc.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h

.\xcalloc.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\xcalloc.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h

.\xatoi.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\xatoi.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xatox.h

.\xatof.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\xatof.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xatox.h

.\wordlists_base.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\wordlists_base.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists_base.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}paths.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrdup.h

.\wordlists.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\wordlists.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists_base.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogofilter.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}datastore.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}find_home.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}paths.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrdup.h

.\wordhash.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\wordhash.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordhash.h

.\word.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\word.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h

.\uudecode.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\uudecode.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}uudecode.h

.\transaction.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\transaction.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}datastore.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}maint.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}transaction.h

.\token.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\token.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogoreader.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}charset.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}token.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}mime.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}msgcounts.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmemrchr.h

.\textblock.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\textblock.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}textblock.h

.\system.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\system.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}direct.h

.\swap_32bit.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\swap_32bit.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}swap.h

.\strlcpy.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\strlcpy.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h

.\strlcat.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\strlcat.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h

.\SpamKill_server.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\SpamKill_server.cpp \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}LSClServer.hpp

.\snprintf.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\snprintf.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h

.\rstats.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\rstats.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogofilter.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}robinson.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}rstats.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}msgcounts.h

.\robinson.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\robinson.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists_base.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogoconfig.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogofilter.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}datastore.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}robinson.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordhash.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}collect.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}rstats.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}token.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}degen.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}msgcounts.h

.\register.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\register.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists_base.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogofilter.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}datastore.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}format.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}configfile.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordhash.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}collect.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}register.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}token.h

.\qp.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\qp.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}qp.h

.\paths.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\paths.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}paths.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrdup.h

.\passthrough.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\passthrough.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogofilter.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}format.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}configfile.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}passthrough.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}fgetsl.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}textblock.h

.\OS2_VACdirent.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\OS2_VACdirent.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}OS2_VACdirent.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}os2_ErrCodes.h

.\myconf.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\myconf.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}myconf.h

.\msgcounts.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\msgcounts.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists_base.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}datastore.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}fgetsl.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}msgcounts.h

.\mime.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\mime.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}base64.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrdup.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}mime.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}qp.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}uudecode.h

.\method.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\method.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists_base.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogofilter.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}method.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}configfile.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordhash.h

.\maint.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\maint.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists_base.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}datastore.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}maint.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrdup.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}transaction.h

.\main.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\main.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists_base.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogoconfig.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogofilter.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}datastore.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}paths.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}passthrough.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}token.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}mime.h

.\lexer_v3.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\lexer_v3.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}charset.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}token.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}mime.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}msgcounts.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}textblock.h

.\lexer.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\lexer.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}base64.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogoreader.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}charset.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}token.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}mime.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}msgcounts.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}qp.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}textblock.h

.\ipmpar.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\ipmpar.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h

.\graham.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\graham.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists_base.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogofilter.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}datastore.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}graham.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordhash.h

.\globals.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\globals.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogofilter.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}method.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}configfile.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordhash.h

.\getopt.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\getopt.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}getopt.h

.\format.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\format.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogoconfig.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogofilter.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}format.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrdup.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}method.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}configfile.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordhash.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}snprintf.h

.\fisher.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\fisher.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}fisher.h

.\find_home_user.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\find_home_user.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}find_home.h

.\find_home_tildeexpand.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\find_home_tildeexpand.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}find_home.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrdup.h

.\find_home.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\find_home.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}find_home.h

.\fgetsl.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\fgetsl.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}fgetsl.h

.\error.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\error.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}snprintf.h

.\depot.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\depot.cpp \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}depot.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}myconf.h

.\degen.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\degen.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}robinson.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}degen.h

.\debug.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\debug.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h

.\db_error.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\db_error.c

.\datastore_qdbm.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\datastore_qdbm.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}datastore.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}paths.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrdup.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}snprintf.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}datastore_db.h

.\datastore.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\datastore.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}datastore.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}maint.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}datastore_db.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}swap.h

.\configfile.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\configfile.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists_base.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogofilter.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bool.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}find_home.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}format.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}maint.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xatox.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrdup.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}configfile.h

.\collect.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\collect.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}charset.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordhash.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}collect.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}token.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}mime.h

.\charset.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\charset.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}charset.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrdup.h

.\buff.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\buff.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}fgetsl.h

.\bool.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\bool.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bool.h

.\bogoreader.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\bogoreader.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogoreader.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}paths.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}token.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}OS2_VACdirent.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}snprintf.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}fgetsl.h

.\bogofilter.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\bogofilter.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists_base.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogoconfig.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogofilter.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogoreader.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}method.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}configfile.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordhash.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}collect.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}passthrough.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}register.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}rstats.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}token.h

.\bogoconfig.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\bogoconfig.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrlcpy.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists_base.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}getopt.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogoconfig.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogofilter.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bogoreader.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}bool.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}charset.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}datastore.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}find_home.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}format.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}lexer.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}maint.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}paths.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xatox.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrdup.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}method.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}graham.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}robinson.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}fisher.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}buff.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}configfile.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordhash.h

.\bf_exit.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\bf_exit.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}wordlists_base.h

.\base64.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\base64.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}common.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}base64.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}debug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}memdebug.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}globals.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}word.h

.\xstrlcpy.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\xstrlcpy.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xstrlcpy.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}xmalloc.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}system.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src;QDBM;specfunc;$(INCLUDE);}config.h
