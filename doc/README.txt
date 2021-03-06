# $Id: README,v 1.10 2003/09/25 01:38:31 m-a Exp $

		bogofilter -- fast Bayesian spam filtering

This package implements a fast Bayesian spam filter along the lines suggested 
by Paul Graham in his article "A Plan For Spam".

This version substantially improves on Paul's proposal by doing smarter
lexical analysis.  In particular, hostames and IP addresses are retained
as recognition features rather than broken up. Various kinds of MTA 
cruft such as dates and message-IDs are discarded so as not to bloat
the word lists.


*** DOCUMENTATION ***

It is recommended, although not necessary, that you install the GNU
Scientific Library (GSL) version 1.4 or newer before configuring
bogofilter. This allows bogofilter to link dynamically against a
system-wide GSL rather than statically against a shipped GSL subset,
conserving memory and disk space.

When installed, there are man pages for bogofilter, bogoutil,
bogolexer, and bogoupgrade.  Additional documentation is in
/usr/src/bogofilter-1.2.3/doc or comparable directory (depending on
your operating system).

If you've installed the source code, the  doc directory and its
subdirectories contain most of bogofilter's documentation.  In it are
a variety of README files, the xml originals for the man pages , and
other documents.  Additionally, many of the directories in the
bogofilter hierarchy have their own README files.

If you use mutt, see the bogofilter(1) manual page for helpful macros
you can add to your .muttrc.


*** BUILDING BOGOFILTER ***

When updating, check the RELEASE.NOTES files.

For fresh installs, check the rest of this file and the INSTALL file.

You can safely ignore any of these compile time warnings:

warning: unused parameter ...
warning: format not a string literal, argument types not checked


*** CONFIGURATION ***

The default location for the configuration files is /etc on Linux and
/usr/local/etc on all other systems, unless you override with
--sysconfdir=/etc.  A sample config file, bogofilter.cf.example is
included with the distribution.


*** CHANGING BOGOFILTER ***

If you make modifications to bogofilter, you may need to have a recent
DocBook XML tool chain, the xmlto program, PassiveTeX and XMLTeX, a
recent automake (1.7) and autoconf (2.5X) and Perl 5.6 or newer
installed to be able to rebuild bogofilter.

These requirements do not apply if you are building an unmodified
tarball.


*** NEWEST SOFTWARE ***

For the most recent version of this software, see: 

	http://sourceforge.net/projects/bogofilter/

The latest stable version can be downloaded.  The development source
is in a CVS repository on SourceForge and can also be downloaded.


							Eric S. Raymond
							August 2002
