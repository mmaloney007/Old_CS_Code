a.out:
	g++ main.o Inventory.o Video.o
main.o:
	g++ -c main.C
Inventory.o:
	g++ -c Inventory.C
Video.o:
	g++ -c Video.C
a.out:  main.o Inventory.o Video.o
main.o:  main.C Inventory.h Video.h
Inventory.o: Inventory.C Inventory.h Video.h
Video.o: Video.C Video.h
