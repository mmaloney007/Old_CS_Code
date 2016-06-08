a.out:
	g++ main.o Lhash.o
main.o:
	g++ -c main.C
Lhash.o:
	g++ -c Lhash.C
a.out: main.o Lhash.o
main.o: main.C Lhash.h
Lhash.o: Lhash.C Lhash.h 
