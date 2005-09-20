#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# $Id$

AC_PREREQ(2.59)
AC_INIT([Exchanger], [1.0.0], [cig-mc@geodynamics.org], [Exchanger])
AC_CONFIG_AUX_DIR([./aux-config])
AC_CONFIG_SRCDIR([pyre/Exchanger.py])
AC_CONFIG_HEADER([portinfo])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign])

# 'configure' options
AC_ARG_VAR(PYTHON, [Python interpreter])
AC_ARG_VAR(PYTHONPATH, [Python module search path])

# Checks for programs.
AM_PATH_PYTHON([2.3])
CIT_PYTHON_INCDIR
CIT_PROG_MPICXX
AC_LANG(C++)
AC_PROG_LIBTOOL
CIT_PROG_PYCONFIG

# Checks for Python modules and packages.
CIT_PATH_PYTHIA([0.8], [mpi])

# Checks for libraries.
CIT_CHECK_LIB_MPI

# Checks for header files.
CIT_HEADER_MPI

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

dnl end of configure.ac
