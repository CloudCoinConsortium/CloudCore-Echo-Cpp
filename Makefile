# From https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
# The compiler: gcc for C program
CC = gcc
CXX = g++
MC = mpicc

# Compiler Flags:
#  -std=c++17	Use the C++17 standard
#  -g 			adds debugging information to the executable file
#  -Wall		turns on most, but not all, compiler warnings
#  -Wextra		enables some extra warning flags that are not enabled by -Wall.
#  -pedantic	print warnings when non-standard C++ is used

CXXFLAGS = -std=c++17 -Wall -Wextra -O -g -pedantic

FILES = ./echoraida ./test

all: $(FILES)

# 	-o 		specifies the output filename
echoraida: echoraida.o raida.o
	$(CXX) $(CXXFLAGS) echoraida.o raida.o -o echoraida -lpthread -lcurl

test: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o test -lpthread -lcurl

echoraida.o: echoraida.cpp raida.h
	$(CXX) $(CXXFLAGS) -c echoraida.cpp

raida.o: raida.cpp raida.h
	$(CXX) $(CXXFLAGS) -c raida.cpp

clean:
	rm -f $(FILES) *.o