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

EXPORT_HEADERS = \
	Array2D.h \
	Array2D.cc \
	Boundary.h \
	BoundedBox.h \
	BoundedMesh.h \
	CartesianCoord.h \
	Convertor.h \
	DIM.h \
	Inlet.h \
	Interpolator.h \
	Outlet.h \
	SIUnit.h \
	Sink.h \
	Source.h \
	Spherical2Cartesian.h \
	Utility.h \
	UtilTemplate.h \
	UtilTemplate.cc \
	inlets_outlets.h \
	util.h \


EXPORT_LIBS = $(PROJ_LIB)

all: $(PROJ_LIB) export

export:: release-headers export-libraries


# version
# $Id: Make.mm,v 1.3 2004/05/08 08:48:50 tan2 Exp $

# End of file
