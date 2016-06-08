a.out:
	g++ main.o List.o Hunter.o
main.o:
	g++ -c main.C
List.o:
	g++ -c List.C
Hunter.o:
	g++ -c Hunter.C

a.out: main.o List.o Hunter.o
main.o: main.C List.h Hunter.h
List.o: List.C List.h Hunter.h
Hunter.o: Hunter.C Hunter.h
