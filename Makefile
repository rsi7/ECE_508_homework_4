# Create a Makefile for the program. It should have at least the following targets:
#
# • clean – remove executable and all object files
# • debug – make the executable (fib) suitable for debugging (by including –g switch)
# • fib – make the executable (fib) suitable for distribution (don’t include –g switch)
#
# The default target should be fib. The executable should be called fib (for distribution and debug
# version). Consider an additional target “install” which will move the executable to your $HOME/bin
# directory. If that directory is in your PATH then you can just type “fib …” to execute the program
# instead of “./fib…”.
#
# testing: make -n <target> will print the intended sequence in shell

# Environment variables for compiler options
CC = gcc
CFLAGS = -std=c99 -s -O2 -Wall
DEBUG_CFLAGS = -g -pg -std=c99 -Wall -Wextra

# Environment variables for files
SOURCE = $(HEADERS) $(OBJ)
HEADERS = fib.h
OBJ = fib.o main.o
OUTPUT = fib

# Major targets

fib: $(SOURCE)
	$(CC) $(SOURCE) $(CFLAGS) -o $(OUTPUT)

debug: $(SOURCE) $(SYMS)
	$(CC) $(SOURCE) $(DEBUG_CFLAGS) -save-temps -o $(OUTPUT)

clean:
	rm -f *.i *.s *.o *.sym $(OUTPUT)

# Intermediate targets

obj: $(OBJ)
sym: $(OBJ:.o=.sym)
asm: $(OBJ:.o=.s)
pre: $(OBJ:.o=.i)

# Intermediate file generation
	
%.o: %.c
	$(CC) -c $^ $(DEBUG_CFLAGS) -o $*.o

%.sym: %.c
	$(CC) -c $^ -o $*.o $(DEBUG_CFLAGS) -Xassembler -as=$*.sym -Xassembler -L
	rm -f *.o

%.s: %.c
	$(CC) -S $^ -fverbose-asm -o $*.s

%.i: %.c
	$(CC) -E $^ -o $*.i