#
# Makefile for as611
#

#CC = gcc
CC = cc
CFLAGS = -g

YACC = bison

LEX = flex

as611: scan.o main.o parse.o message.o directives.o symtab.o assemble.o
	$(CC) $(CFLAGS) scan.o main.o parse.o message.o directives.o symtab.o \
	                assemble.o -lfl -o as611

scan.o: y.tab.h defs.h

scan.c:  scan.l
	$(LEX) scan.l
	mv lex.yy.c scan.c

y.tab.h parse.c: parse.y
	$(YACC) -d -y parse.y
	mv y.tab.c parse.c
	$(CC) $(CFLAGS) -c parse.c

main.o: defs.h

parse.o: defs.h 

message.o: 

directives.o: defs.h

assemble.o: defs.h 

lexdbg: scan.l y.tab.h
	$(LEX) scan.l
	$(CC) -DDEBUG lex.yy.c -lfl -o lexdbg
	rm lex.yy.c

y.output: parse.y
	$(YACC) -v -y parse.y

clean:
	-rm *.o parse.c scan.c y.tab.h lexdbg
	-rm as611 y.output

