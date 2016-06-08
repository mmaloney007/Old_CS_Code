a.out:
	g++ main.o Token.o TStack.o
main.o:
	g++ -c main.C
Token.o:
	g++ -c Token.C
TStack.o:
	g++ -c TStack.C

a.out: main.o Token.o TStack.o
main.o: main.C Token.h TStack.h
Token.o: Token.C Token.h
TStack.o: TStack.C TStack.h Token.h

