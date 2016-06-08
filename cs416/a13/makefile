a.out:
	g++ main.o Student.o Bstring.o
main.o: 
	g++ -c main.C
Student.o:
	g++ -c Student.C
Bstring.o:
	g++ -c Bstring.C

a.out: main.o Student.o Bstring.o
main.o: Student.h List.h main.C Bstring.h
Student.o: Student.h Student.C
Bstring.o: Bstring.C Bstring.h
