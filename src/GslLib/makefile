# makefile
# Created by IBM WorkFrame/2 MakeMake at 11:34:26 on 8 Oct 2003
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Lib::Library Tool

.SUFFIXES:

.SUFFIXES: \
    .c .obj 

.c.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Igsl /Ispecfunc /Ss /O /Gm /G5 /Oi /C %s

{G:\EVGEN\INET\SpamKill\BFilter\src\GslLib}.c.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Igsl /Ispecfunc /Ss /O /Gm /G5 /Oi /C %s

all: \
    ..\gsl.lib

..\gsl.lib: \
    .\s_trig.obj \
    .\s_psi.obj \
    .\s_zeta.obj \
    .\gsl_cdf_chisq.obj \
    .\gsl_cdf_gamma.obj \
    .\gsl_err_error.obj \
    .\gsl_err_stream.obj \
    .\gsl_sys_fdiv.obj \
    .\gsl_sys_infnan.obj \
    .\gsl_sys_pow_int.obj \
    .\s_elementary.obj \
    .\s_erfc.obj \
    .\s_exp.obj \
    .\s_expint.obj \
    .\s_gamma_inc.obj \
    .\s_log.obj
    @echo " Lib::Library Tool "
    ilib.exe  /nol ..\gsl.lib @makefile.rf;

.\s_trig.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\s_trig.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}gsl_err_error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}chebyshev.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}cheb_eval.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}eval.h

.\s_psi.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\s_psi.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}gsl_err_error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}chebyshev.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}cheb_eval.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}eval.h

.\s_log.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\s_log.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}gsl_err_error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}chebyshev.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}cheb_eval.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}eval.h

.\s_gamma_inc.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\s_gamma_inc.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}gsl_err_error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}eval.h

.\s_expint.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\s_expint.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}gsl_err_error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}chebyshev.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}cheb_eval.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}eval.h

.\s_exp.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\s_exp.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}gsl_err_error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}eval.h

.\s_erfc.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\s_erfc.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}chebyshev.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}cheb_eval.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}eval.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}check.h

.\s_elementary.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\s_elementary.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}gsl_err_error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}eval.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}check.h

.\gsl_sys_pow_int.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\gsl_sys_pow_int.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h

.\gsl_sys_infnan.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\gsl_sys_infnan.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h

.\gsl_sys_fdiv.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\gsl_sys_fdiv.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h

.\gsl_err_stream.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\gsl_err_stream.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h

.\gsl_err_error.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\gsl_err_error.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h

.\gsl_cdf_gamma.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\gsl_cdf_gamma.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}gsl_err_error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}chebyshev.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}cheb_eval.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}eval.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}../specfunc/gamma.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}check.h

.\gsl_cdf_chisq.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\gsl_cdf_chisq.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h

.\s_zeta.obj: \
    G:\EVGEN\INET\SpamKill\BFilter\src\GslLib\s_zeta.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}config.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}gsl_err_error.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}chebyshev.h \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}cheb_eval.c \
    {G:\EVGEN\INET\SpamKill\BFilter\src\GslLib;gsl;specfunc;$(INCLUDE);}eval.h
