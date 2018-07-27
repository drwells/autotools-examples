# libraries: same as step-3.
lib_LTLIBRARIES = libhello.la
libhello_la_SOURCES = $(top_srcdir)/source/hello/hello.cc $(top_srcdir)/include/hello/hello.h
hellodir = $(includedir)/hello
hello_HEADERS = include/hello/hello.h

lib_LTLIBRARIES += libhelloint.la
libhelloint_la_SOURCES = $(top_srcdir)/source/helloint/hello.cc $(top_srcdir)/include/helloint/hello.h
hellointdir = $(includedir)/helloint
helloint_HEADERS = include/helloint/hello.h

# Declare the next example program: this depends on the library we compile above.
examplesstep4dir = $(bindir)/examples/step-4/
examplesstep4_PROGRAMS = step-4
step_4_SOURCES = $(top_srcdir)/examples/step-4/step-4.cc
step_4_LDADD = libhello.la libhelloint.la

AM_CXXFLAGS=-I$(top_srcdir)/include/

# this part is new: we need to instruct automake how to use zlib. Note that,
# formally, the include directories are fed to the C preprocessor (not something
# we usually think about) so these should be added to CPPFLAGS.
libhelloint_la_CPPFLAGS = $(ZLIB_CFLAGS)
libhelloint_la_LDFLAGS = $(ZLIB_LIBS)
