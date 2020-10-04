# This file demonstrates how to compile the micro project on Linux.
#
# To compile MICRO do:
#
# make MICRO
#

GPP = g++
GCC = gcc
MICRO_OUTFILE = "micro.so"

COMPILE_FLAGS = -m32 -fPIC -c -O3 -w -D LINUX -D PROJECT_NAME=\"micro\" -D HAVE_STDINT_H -I ./SDK/amx/

MICRO = -D MICRO $(COMPILE_FLAGS)

all: MICRO

clean:
	-rm -f *~ *.o *.so

MICRO: clean
	$(GPP) $(MICRO) ./SDK/amx/*.c
	$(GPP) $(MICRO) ./SDK/*.cpp
	$(GPP) $(MICRO) *.cpp
	$(GPP) -m32 -O2 -fshort-wchar -shared -o $(MICRO_OUTFILE) *.o
