a.out:
	g++ main.o Bk.o Aut.o
main.o:
	g++ -c main.C
Bk.o:
	g++ -c Bk.C
Aut.o:
	g++ -c Aut.C

a.out: main.o Bk.o Aut.o
main.o: main.C Bk.h Aut.h
Bk.o: Bk.C Bk.h Aut.h
Aut.o: Aut.C Aut.h
