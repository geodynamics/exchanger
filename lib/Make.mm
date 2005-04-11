# -*- Makefile -*-
#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
# <LicenseText>
#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#

PROJECT = Exchanger
PACKAGE = libExchanger

PROJ_SAR = $(BLD_LIBDIR)/$(PACKAGE).$(EXT_SAR)
PROJ_DLL = $(BLD_LIBDIR)/$(PACKAGE).$(EXT_SO)
PROJ_TMPDIR = $(BLD_TMPDIR)/$(PROJECT)/$(PACKAGE)
PROJ_CLEAN += $(PROJ_DLL) $(PROJ_SAR)

PROJ_CXX_SRCLIB = \
        -ljournal \

EXTERNAL_INCLUDES += $(PYTHON_INCDIR) $(PYTHIA_DIR)/include $(PYTHIA_INCDIR)
EXTERNAL_LIBPATH += -L$(PYTHIA_LIBDIR)

PROJ_SRCS = \
	Boundary.cc \
	BoundedBox.cc \
	BoundedMesh.cc \
	BoundingBox.cc \
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
	BoundingBox.h \
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


EXPORT_LIBS = $(PROJ_SAR)
EXPORT_BINS = $(PROJ_DLL)

all: $(PROJ_SAR) export

export:: export-headers export-libraries export-binaries

# version
# $Id: Make.mm,v 1.11 2005/04/11 11:17:12 steve Exp $

# End of file
