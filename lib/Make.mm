# -*- Makefile -*-
#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
# <LicenseText>
#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#

PROJECT = Exchanger
PACKAGE = Exchangermodule

PROJ_LIB = $(BLD_LIBDIR)/libExchanger.$(EXT_LIB)

PROJ_CXX_SRCLIB = \
        -ljournal \
        -lmpimodule

EXTERNAL_INCLUDES += $(PYTHON_INCDIR)
EXTERNAL_LIBPATH += -L$(TOOLS_LIBDIR)

PROJ_SRCS = \
	Boundary.cc \
	BoundedBox.cc \
	BoundedMesh.cc \
	Convertor.cc \
	Inlet.cc \
	Interpolator.cc \
	Outlet.cc \
	SIUnit.cc \
	Sink.cc \
	Source.cc \
	Spherical2Cartesian.cc \
	Utility.cc \
	inlets_outlets.cc \
	util.cc \


all: $(PROJ_LIB)


# version
# $Id: Make.mm,v 1.1.1.1 2004/05/08 01:51:14 tan2 Exp $

# End of file
