## Process this file with automake to produce Makefile.in
# $Id$

ACLOCAL_AMFLAGS = -I ./m4

# doc
EXTRA_DIST = \
	doc/Exchanger.doxyconf

# lib
CXX = $(MPICXX)
CXXLD = @CXX@
INCLUDES = $(PYTHIA_CPPFLAGS) -I$(PYTHON_INCDIR) $(MPIINCLUDES)
pkginclude_HEADERS = \
	lib/Array2D.h \
	lib/Array2D.cc \
	lib/Boundary.h \
	lib/BoundedBox.h \
	lib/BoundedMesh.h \
	lib/BoundingBox.h \
	lib/CartesianCoord.h \
	lib/Convertor.h \
	lib/DIM.h \
	lib/exchangers.h \
	lib/Inlet.h \
	lib/Interpolator.h \
	lib/Outlet.h \
	lib/SIUnit.h \
	lib/Sink.h \
	lib/Source.h \
	lib/Spherical2Cartesian.h \
	lib/Utility.h \
	lib/UtilTemplate.h \
	lib/UtilTemplate.cc
lib_LTLIBRARIES = libExchanger.la
libExchanger_la_SOURCES =  \
	lib/Boundary.cc \
	lib/BoundedBox.cc \
	lib/BoundedMesh.cc \
	lib/BoundingBox.cc \
	lib/Convertor.cc \
	lib/exchangers.cc \
	lib/Inlet.cc \
	lib/Interpolator.cc \
	lib/Outlet.cc \
	lib/Sink.cc \
	lib/SIUnit.cc \
	lib/Source.cc \
	lib/Spherical2Cartesian.cc \
	lib/Utility.cc
libExchanger_la_LDFLAGS = -release $(PACKAGE_VERSION)
libExchanger_la_LIBADD = -l_mpimodule -ljournal

# pyre
pkgpython_PYTHON = \
	pyre/CoupledApp.py \
	pyre/Coupler.py \
	pyre/Exchanger.py \
	pyre/Layout.py
nodist_pkgpython_PYTHON = \
	config.py \
	__init__.py
do_subst = sed \
	-e 's|[@]PACKAGE_VERSION[@]|$(PACKAGE_VERSION)|g'
config.py: $(top_builddir)/portinfo $(top_builddir)/Makefile
	$(PYCONFIG) -h $(top_builddir)/portinfo -m $(top_builddir)/Makefile -o $@
__init__.py: $(srcdir)/pyre/__init__.py.in
	$(do_subst) < $(srcdir)/pyre/__init__.py.in > $@ || (rm -f $@ && exit 1)
CLEANFILES = $(nodist_pkgpython_PYTHON)
EXTRA_DIST += \
	pyre/__init__.py.in

# export
export_incdir = $(top_builddir)/include
BUILT_SOURCES = export-pkgincludeHEADERS
CLEANFILES += export-pkgincludeHEADERS
clean-local: clean-pkgincludeHEADERS
export-pkgincludeHEADERS: $(pkginclude_HEADERS)
	$(MAKE) $(AM_MAKEFLAGS) includedir=$(export_incdir) install-pkgincludeHEADERS
	touch $@
clean-pkgincludeHEADERS:
	$(MAKE) $(AM_MAKEFLAGS) includedir=$(export_incdir) uninstall-pkgincludeHEADERS

## end of Makefile.am
