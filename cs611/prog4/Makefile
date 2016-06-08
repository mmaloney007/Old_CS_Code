#
# This builds example programs that use the dynamic linker.
#
all: test1 test2 test3 test4 test5

test1: test1.o DLstub.o dynamicLinker.o zero.obj one.obj
	gcc -g test1.o DLstub.o dynamicLinker.o -o test1

test1.o: test1.c DL.h
	gcc -c -g test1.c

test2: test2.o DLstub.o dynamicLinker.o zero.obj one.obj
	gcc -g test2.o DLstub.o dynamicLinker.o -o test2

test2.o: test2.c DL.h
	gcc -c -g test2.c

test3: test3.o DLstub.o dynamicLinker.o two.obj three.obj
	gcc -g test3.o DLstub.o dynamicLinker.o -o test3

test3.o: test3.c DL.h
	gcc -c -g test3.c

test4: test4.o DLstub.o dynamicLinker.o six.obj
	gcc -g test4.o DLstub.o dynamicLinker.o -o test4

test4.o: test4.c DL.h
	gcc -c -g test4.c

test5: test5.o DLstub.o dynamicLinker.o seven.obj
	gcc -g test5.o DLstub.o dynamicLinker.o -o test5

test5.o: test5.c DL.h
	gcc -c -g test5.c

DLstub.o: DLstub.s
	as -g DLstub.s -o DLstub.o

dynamicLinker.o: dynamicLinker.c DL.h
	gcc -c -g dynamicLinker.c

zero.obj: zero
	zero >zero.obj

zero: zero.o genObjectFile.o
	gcc zero.o genObjectFile.o -o zero

zero.o: zero.c DL.h
	gcc -c -O zero.c

one.obj: one
	one >one.obj

one: one.o genObjectFile.o
	gcc one.o genObjectFile.o -o one

one.o: one.c DL.h
	gcc -c -O one.c

two.obj: two
	two >two.obj

two: two.o genObjectFile.o
	gcc two.o genObjectFile.o -o two

two.o: two.c DL.h
	gcc -c -O two.c

three.obj: three
	three >three.obj

three: three.o genObjectFile.o
	gcc three.o genObjectFile.o -o three

three.o: three.c DL.h
	gcc -c -O three.c

six.obj: six
	six >six.obj

six: six.o genObjectFile.o
	gcc six.o genObjectFile.o -o six

six.o: six.c DL.h
	gcc -c -O six.c

seven.obj: seven
	seven >seven.obj

seven: seven.o genObjectFile.o
	gcc seven.o genObjectFile.o -o seven

seven.o: seven.c DL.h
	gcc -c -O seven.c

clean:
	-rm -f test1 test2 test3 one zero one.obj zero.obj two.obj three.obj
	-rm -f test1.o test2.o DLstub.o dynamicLinker.o zero.o one.o
	-rm -f two.o three.o test3.o six.o test4.o six.obj seven.o test5.o
	-rm -f seven.obj test4 test5 six seven three two

