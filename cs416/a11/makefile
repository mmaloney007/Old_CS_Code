a.out:
	g++ main.o Store.o List.o
main.o:
	g++ -c main.C
Store.o:
	g++ -c Store.C
List.o:
	g++ -c List.C

a.out: main.o Store.o List.o
main.o: main.C Store.h List.h
Store.o: Store.C Store.h
List.o: List.C List.h Store.h

clean:
	rm -f List.o a.out main.o Store.o
