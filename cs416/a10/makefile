a.out:
	gcc main.o Token.o Stack.o Queue.o
main.o:
	gcc -c main.C
Token.o:
	gcc -c Token.C
Stack.o:
	gcc -c Stack.C
Queue.o:
	gcc -c Queue.C

a.out: main.o Token.o Stack.o
main.o: main.C Token.h Stack.h
Token.o: Token.C Token.h
Stack.o: Stack.C Stack.h Token.h
Queue.o: Token.h Queue.C Queue.h
