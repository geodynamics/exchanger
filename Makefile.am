## Process this file with automake to produce Makefile.in
# $Id$

ACLOCAL_AMFLAGS = -I ./m4

# doc
EXTRA_DIST = \
	doc/Exchanger.doxyconf

# lib
CXX = $(MPICXX)
CXXLD = @CXX@
INCLUDES = $(PYTHON_EGG_CPPFLAGS) -I$(PYTHON_INCDIR) $(MPIINCLUDES)
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
libExchanger_la_LIBADD = $(PYTHON_EGG_LDFLAGS)

# pyre
nobase_pythonegg_PYTHON = \
	Exchanger/CoupledApp.py \
	Exchanger/Coupler.py \
	Exchanger/Exchanger.py \
	Exchanger/Layout.py \
	Exchanger/__init__.py
pythonegginfo_PYTHON = \
	requires.txt
nodist_pythonegginfo_PYTHON = \
	PKG-INFO \
	config.cfg
do_subst = sed \
	-e 's|[@]PACKAGE[@]|$(PACKAGE)|g' \
	-e 's|[@]PACKAGE_VERSION[@]|$(PACKAGE_VERSION)|g' \
	-e 's|[@]prefix[@]|$(prefix)|g' \
	-e 's|[@]exec_prefix[@]|$(exec_prefix)|g' \
	-e 's|[@]includedir[@]|$(includedir)|g' \
	-e 's|[@]libdir[@]|$(libdir)|g'
PKG-INFO: $(srcdir)/PKG-INFO.in
	$(do_subst) < $(srcdir)/PKG-INFO.in > $@ || (rm -f $@ && exit 1)
config.cfg: $(srcdir)/config.cfg.in
	$(do_subst) < $(srcdir)/config.cfg.in > $@ || (rm -f $@ && exit 1)
CLEANFILES = $(nodist_pythonegginfo_PYTHON)
EXTRA_DIST += \
	PKG-INFO.in \
	config.cfg.in

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
