check_PROGRAMS =

AM_CPPFLAGS = $(GTEST_CPPFLAGS)
AM_LDFLAGS = $(GTEST_LDFLAGS) $(GTEST_CXXFLAGS)

check_PROGRAMS += factorial_tests
factorial_tests_SOURCES = factorial_tests.cpp
factorial_tests_LDADD = \
    ../factorial.o \
    $(GTEST_DIR)/src/gtest-all.o \
    $(GTEST_DIR)/src/gtest_main.o

TESTS = $(check_PROGRAMS)
