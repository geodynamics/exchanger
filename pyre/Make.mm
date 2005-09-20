# -*- Makefile -*-
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
# <LicenseText>
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

PROJECT = Exchanger
PACKAGE = pyre


#--------------------------------------------------------------------------
#

all: export

release: tidy
	cvs release .

update: clean
	cvs update .

init:
	sed -e 's|@PACKAGE_VERSION@|1.0.0|g' < __init__.py.in > __init__.py

#--------------------------------------------------------------------------
#
# export

EXPORT_PYTHON_MODULES = \
	__init__.py \
	CoupledApp.py \
	Coupler.py \
	Exchanger.py \
	Layout.py \


export:: init export-python-modules
	$(RM) $(RMFLAGS) __init__.py __init__.pyc

# version
# $Id: Make.mm,v 1.2 2004/06/11 17:20:55 tan2 Exp $

# End of file
