#
# Makefile for program 2, cs611 Spring 2001
#
#
# note: Alpha/OSF requires the -ieee compiler flag to get "precise" exceptions
#
# also: on Alpha/OSF you must use DEC compilers (not gcc/g++)
#       the GNU compilers don't generate code for "precise" exceptions

prog2: main.o prog2.o
	cc -ieee -g -o prog2 main.o prog2.o

main.o: main.c
	cc -ieee -g -c main.c

DoubleAdd.o: prog2.c
	cc -ieee -g -c prog2.c

clean:
	-rm prog2 main.o prog2.o
