# -*- Makefile -*-
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
# <LicenseText>
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

PROJECT = Exchanger
PACKAGE = main

RECURSE_DIRS = \
    lib \
    tests 

#--------------------------------------------------------------------------
#

all:
	BLD_ACTION="all" $(MM) recurse

PROJ_CLEAN =
clean::
	BLD_ACTION="clean" $(MM) recurse

tidy::
	BLD_ACTION="tidy" $(MM) recurse


# version
# $Id: Make.mm,v 1.1 2004/05/08 01:51:14 tan2 Exp $

# End of file
