#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# $Id$

AC_PREREQ(2.59)
AC_INIT([Exchanger], [1.0.0], [cig-mc@geodynamics.org], [Exchanger])
AC_CONFIG_AUX_DIR([./aux-config])
AC_CONFIG_SRCDIR([Exchanger/Exchanger.py])
AC_CONFIG_HEADER([portinfo])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign])

# 'configure' options
AC_ARG_VAR(PYTHON, [Python interpreter])
AC_ARG_VAR(PYTHONPATH, [Python module search path])

# Check for Python.
AM_PATH_PYTHON([2.3])
CIT_PYTHON_INCDIR

# Checks for Python modules and packages.
CIT_CHECK_PYTHON_EGG([pythia >= 0.8-1.0dev-r4617, < 0.8-2.0a, == dev])
CIT_PYTHON_EGG_FLAGS
CIT_PYTHON_EGG_REQUIRES

# Checks for programs.
CIT_PROG_MPICXX
AC_LANG(C++)
AC_PROG_LIBTOOL

# Checks for libraries.
CIT_CHECK_LIB_MPI

# Checks for header files.
CIT_HEADER_MPI

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

dnl end of configure.ac
