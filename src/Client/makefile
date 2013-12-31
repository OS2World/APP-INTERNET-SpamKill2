# makefile
# Created by IBM WorkFrame/2 MakeMake at 13:32:52 on 13 Oct 2003
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker

.SUFFIXES:

.SUFFIXES: \
    .cpp .obj 

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Ss /O /G5 /C %s

{G:\EVGEN\INET\SpamKill\BFilter\src\Client}.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Ss /O /G5 /C %s

all: \
    .\SpamClient.exe

.\SpamClient.exe: \
    .\main.obj
    @echo " Link::Linker "
    icc.exe @<<
     /B" /exepack:2 /packd /optfunc"
     /FeSpamClient.exe 
     .\main.obj
<<

.\main.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\Client\main.cpp \
    {G:\EVGEN\INET\SpamKill\BFilter\src\Client;$(INCLUDE);}LSClServer.hpp
