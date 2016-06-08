a.out:
	g++ main.o Inventory.o Book.o
main.o:
	g++ -c main.C
Inventory.o:
	g++ -c Inventory.C
Book.o:
	g++ -c Book.C

a.out: main.o Inventory.o Book.o
main.o: main.C Inventory.h Book.h
Inventory.o: Inventory.C Inventory.h Book.h
Book.o: Book.C Book.h
