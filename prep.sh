#!/bin/bash

touch configure.ac
cat <<XXX > configure.ac
  AC_INIT([Tutorial Program], 1.0)
  AM_INIT_AUTOMAKE
  AC_PROG_CC
  AC_CONFIG_FILES(Makefile)
  AC_OUTPUT
XXX

aclocal
autoconf

cat <<XXX > Makefile.am
 bin_PROGRAMS = app			
 app_SOURCES = main.c
XXX

automake --add-missing --foreign

./configure 

touch NEWS
touch README
touch AUTHORS
touch ChangeLog

make
