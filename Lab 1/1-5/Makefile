#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = gccfilter -c -a g++
CFLAGS  = -g -std=c++11

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
all: lister

# To create the executable file count we need the object files
# countwords.o, counter.o, and scanner.o:
#
lister:  lab1-5.o List.o
	$(CC) $(CFLAGS) -o lister lab1-5.o List.o

# To create the object file countwords.o, we need the source
# files countwords.c, scanner.h, and counter.h:
#
lab1-5.o:  lab1-5.cc List.h
	$(CC) $(CFLAGS) -c lab1-5.cc

# To create the object file counter.o, we need the source files
# counter.c and counter.h:
#
List.o:  List.cc List.h
	$(CC) $(CFLAGS) -c List.cc

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) lister *.o *~
