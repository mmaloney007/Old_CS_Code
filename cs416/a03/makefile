a.out:
	g++ main.o Apart.o
main.o:
	g++ -c main.C
Apart.o:
	g++ -c Apart.C

a.out: main.o Apart.o 
main.o: main.C Apart.h 
Apart.o: Apart.C Apart.h 

