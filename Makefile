# From https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
# The compiler: gcc for C program
CC = gcc
CXX = g++
MC = mpicc

CFLAGS = -std=c++17 -Wall -O -g

FILES = ./echoraida

all: $(FILES)

echoraida: echoraida.o
	$(CXX) $(CFLAGS) -o echoraida echoraida.o

clean:
	rm -f $(FILES) *.o