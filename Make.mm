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
    pyre

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
# $Id: Make.mm,v 1.3 2005/01/21 20:19:08 tan2 Exp $

# End of file
