a.out:
	g++ A7.o Matrix.o TwoDArray.o
A7.o:
	g++ -c A7.C
Matrix.o:
	g++ -c Matrix.C
TwoDArray.o:
	g++ -c TwoDArray.C

a.out: A7.o Matrix.o TwoDArray.o
A7.o: A7.C
Matrix.o: Matrix.C Matrix.h TwoDArray.h
TwoDArray.o: TwoDArray.C TwoDArray.h


