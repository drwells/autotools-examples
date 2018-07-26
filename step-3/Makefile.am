# first library: same as step-2, but with a new name.
lib_LTLIBRARIES = libhello.la
libhello_la_SOURCES = $(top_srcdir)/source/hello/hello.cc $(top_srcdir)/include/hello/hello.h
# Since two headers are both named 'hello.h', we want to install them in
# subdirectories. Automake can do this: we need to define the directory (ends in
# 'dir') and then list its headers. All headers in the hello_HEADERS list will
# be put in this directory (even if they did not originate in include/hello/).
hellodir = $(includedir)/hello
hello_HEADERS = include/hello/hello.h

# second library: we can print out integers now!
lib_LTLIBRARIES += libhelloint.la
libhelloint_la_SOURCES = $(top_srcdir)/source/helloint/hello.cc $(top_srcdir)/include/helloint/hello.h
hellointdir = $(includedir)/helloint
helloint_HEADERS = include/helloint/hello.h

# Declare the next example program: this depends on the library we compile
# above. Binaries are, almost always, installed in prefix/bin: however, we will
# ultimately install multiple binaries in multiple subdirectories, so we do
# something different here. Instead of the usual bin_PROGRAMS, we define a new
# output directory for binaries (ends in 'dir') and then list the programs that
# should be installed in that directory (step-3). The next two commands (like in
# step-2) list the source and link dependencies for step-3.
examplesstep3dir = $(bindir)/examples/step-3/
examplesstep3_PROGRAMS = step-3
step_3_SOURCES = $(top_srcdir)/examples/step-3/step-3.cc
step_3_LDADD = libhello.la libhelloint.la

# This is the only part of the makefile that is not strictly declarative: we
# need to explicitly pass the folder including headers to compilation commands.
AM_CXXFLAGS=-I$(top_srcdir)/include/
