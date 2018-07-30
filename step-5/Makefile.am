# libraries: same as step-3.
lib_LTLIBRARIES = libhello.la
libhello_la_SOURCES = $(top_srcdir)/source/hello/hello.cc $(top_srcdir)/include/step-5/hello/hello.h
hellodir = $(includedir)/step-5/hello
hello_HEADERS = include/step-5/hello/hello.h

lib_LTLIBRARIES += libhelloint.la
libhelloint_la_SOURCES = $(top_srcdir)/source/helloint/hello.cc $(top_srcdir)/include/step-5/helloint/hello.h
hellointdir = $(includedir)/step-5/helloint
helloint_HEADERS = include/step-5/helloint/hello.h

# Unlike step-4, we want to install a configuration header. Automake is smart
# enough to figure out that this is a header-only target and does not require
# compilation.
basedir = $(includedir)/step-5/base
base_HEADERS = include/step-5/base/config.h

# Declare the next example program: this depends on the library we compile above.
examplesstep5dir = $(bindir)/examples/step-5/
examplesstep5_PROGRAMS = step-5
step_5_SOURCES = $(top_srcdir)/examples/step-5/step-5.cc
step_5_LDADD = libhello.la libhelloint.la

# We have to include the build directory include folder as well since that contains config.h.
AM_CXXFLAGS=-I$(top_srcdir)/include -I$(top_builddir)/include

# Unlike step-4, zlib may not be available: in this case, however, these shell
# variables are undefined and will expand to nothing, so we can keep these two
# lines unchanged.
libhelloint_la_CPPFLAGS = $(ZLIB_CFLAGS)
libhelloint_la_LDFLAGS = $(ZLIB_LIBS)
