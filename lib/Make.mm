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

PROJ_LIB = $(PROJ_LIBDIR)/libExchanger.$(EXT_LIB)

PROJ_CXX_SRCLIB = \
        -ljournal \

EXTERNAL_INCLUDES += $(PYTHON_INCDIR) $(PYTHIA_DIR)/include

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
	exchangers.cc \


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
	exchangers.h \


EXPORT_LIBS = $(PROJ_LIB)

all: $(PROJ_LIB) export-headers



# version
# $Id: Make.mm,v 1.8 2004/07/02 19:46:23 tan2 Exp $

# End of file
