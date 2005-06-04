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
EXTERNAL_LIBDIRS = $(PYTHIA_LIBDIR)
EXTERNAL_LIBPATH += $(foreach dir,$(EXTERNAL_LIBDIRS),-L$(dir))

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
# $Id: Make.mm,v 1.12 2005/06/03 21:51:47 leif Exp $

# End of file
