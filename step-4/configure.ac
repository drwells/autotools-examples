# This is the same as step-2:
AC_INIT([step-4], [0.9])
AC_PREREQ([2.69])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([1.9 foreign -Wall -Werror subdir-objects])
AM_PROG_AR
LT_INIT([])
AC_LANG(C++)
AC_PROG_CXX
AC_PROG_CXXCPP

# This one is new: we want to use an external library (zlib). Using external
# libraries, like using our own libraries, requires setting up both libraries to
# link against and headers to include.
#
# One way to solve this is pkg-config; however, this is not completely portable
# without issues, so we use something built in to autotools instead.
#
# The first check verifies that the header describing the external library is
# visible. The second argument is run if we can find the header.
AC_CHECK_HEADER(zlib.h, [STEP_4_HAVE_ZLIB_H=yes])
if test "$STEP_4_HAVE_ZLIB_H" = "yes"; then
    AC_MSG_RESULT(Found zlib.h)
else
    AC_MSG_ERROR(zlib.h not available!)
fi

# Now check if we can find the library for zlib: it should be one of libz.a,
# libz.so, libz.dylib, or something else, depending on the platform.
#
# AC_CHECK_LIB prepends "-lz" (or equivalent on another platform) to LIBS. This
# is not quite what we want: we would prefer to only link things that depend on
# zlib on zlib (instead of trying to link *everything* against it). Hence we
# clear LIBS and reset it after calling this function.
#
# The other thing this macro does is set
_old_libs=$LIBS
LIBS=""
AC_CHECK_LIB(z, compress2)
if test "$LIBS" != ""; then # we must have found something
    AC_MSG_RESULT(Found libz)
else
    AC_MSG_ERROR(libz not available!)
fi
ZLIB_LIBS=$LIBS
LIBS=$_old_libs

AC_SUBST(ZLIB_LIBS, [$ZLIB_LIBS])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
