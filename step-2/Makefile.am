# Declare the library: libtool can build either a shared or static library, we
# just have to declare its dependencies.
lib_LTLIBRARIES = libstep2.la
# source files for the library:
libstep2_la_SOURCES = $(top_srcdir)/source/hello.cc $(top_srcdir)/include/step-2/hello.h
# headers to install for the library:
include_HEADERS = $(top_srcdir)/include/step-2/hello.h

# Declare the next example program: this depends on the library we compile above.
bin_PROGRAMS = step-2
step_2_SOURCES = $(top_srcdir)/examples/step-2/step-2.cc
step_2_LDADD = libstep2.la

# This is the only part of the makefile that is not strictly declarative: we
# need to explicitly pass the folder including headers to compilation commands.
AM_CXXFLAGS=-I$(top_srcdir)/include/
