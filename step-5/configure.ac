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

# Unlike step-4, we will now permit zlib to be an optional dependency.
STEP_5_ENABLE_ZLIB=no
ZLIB_ARGUMENT_MESSAGE=
AC_ARG_ENABLE(zlib,
              AS_HELP_STRING([--enable-zlib],
                             [Enable compression with zlib]),
              AS_CASE([$enableval],
                       [yes], [STEP_5_ENABLE_ZLIB=yes],
                       [no],  [STEP_5_ENABLE_ZLIB=no],
                       [*],   [AC_MSG_ERROR(Please use either --enable-zlib=yes or --enable-zlib=no; the value '$enableval' was not understood)]),
              [STEP_5_ENABLE_ZLIB=yes])

if test "$STEP_5_ENABLE_ZLIB" = "yes"; then
    # we check for the library in the same way we did in step-4:
    AC_CHECK_HEADER(zlib.h, [STEP_5_HAVE_ZLIB_H=yes])
    if test "$STEP_5_HAVE_ZLIB_H" = "yes"; then
        AC_MSG_RESULT(Found zlib.h)
    else
        AC_MSG_ERROR(zlib.h not available!)
    fi

    _old_libs=$LIBS
    LIBS=""
    AC_CHECK_LIB(z, compress2)
    if test "$LIBS" != ""; then
        AC_MSG_RESULT(Found libz)
    else
        AC_MSG_ERROR(libz not available!)
    fi
    ZLIB_LIBS=$LIBS
    LIBS=$_old_libs

    AC_SUBST(ZLIB_LIBS, [$ZLIB_LIBS])
fi

# We need a way to establish, at compile time, that we have ZLIB available: in
# particular, we should conditionally include zlib.h based on the value of
# STEP_5_ENABLE_ZLIB.
#
# To keep things well-organized, we now add another directory which contains
# everything to the hierarchy.
#
# Unlike C projects, since a lot of code tends to live in header files (which
# may in turn be conditionally compiled) in C++ projects, we really do need to
# export the configuration header. This is against autotools' recommendations
# but is necessary for complicated C++ projects with external dependencies. To
# do this, we first generate config.h.tmp and then we prefix all preprocessor
# symbol definitions with STEP_5_: the result is the file
# include/step-5/base/config.h (which will be installed).
AC_CONFIG_HEADERS(include/step-5/base/configtmp.h:include/step-5/base/config.h.in)
# The m4 directory now contains ax_prefix_config_h.m4. This is the standard GNU
# file with one modification: to make the top include guard prettier we hardcode
# in the name of the project.
AX_PREFIX_CONFIG_H(include/step-5/base/config.h,STEP_5,include/step-5/base/configtmp.h)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
