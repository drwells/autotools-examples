# AC_INIT must be called with, at least, package and version arguments.
AC_INIT([step-1], [0.9])

# Use autotools version 2.69 or newer.
AC_PREREQ([2.69])

# use version 1.9 or newer; do not assume that this is a GNU application. Permit
# the use of source files in subdirectories.
AM_INIT_AUTOMAKE([1.9 foreign subdir-objects])

# This is a C++ project.
AC_LANG(C++)

# Check for a C++ compiler.
AC_PROG_CXX

# Check for a C++ preprocessor.
AC_PROG_CXXCPP

# These files should be automatically generated.
AC_CONFIG_FILES([Makefile])

# Actually write all generated files (in this case, just Makefile, declared
# above)
AC_OUTPUT
