AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = minefield
minefield_SOURCES = minefield.cpp src/mine.cpp
AM_CXXFLAGS = -std=c++11 -Iinclude
include_HEADERS = include/mine.h

clean::
	rm -rf .deps *.o minefield
