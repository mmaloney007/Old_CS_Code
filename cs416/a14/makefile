a.out:
	g++ Bstring.o Word.o main.o List.o
main.o:
	g++ -c main.C
Bstring.o:
	g++ -c Bstring.C
Word.o:
	g++ -c Word.C
List.o: 
	g++ -c List.C

a.out: main.o Word.o Bstring.o List.o
Word.o: Word.h Word.C Bstring.h
main.o: Bstring.h Word.h main.C List.h
Bstring.o: Bstring.h Bstring.C
List.o: List.h List.C Word.h
