a.out:
	g++ main.o Queue.o Processor.o
Processor.o:
	g++ -c Processor.C
main.o:
	g++ -c main.C
Queue.o:
	g++ -c Queue.C
a.out: main.o Processor.o Queue.o
main.o: Node.h main.C Queue.h Processor.h
Queue.o: Node.h Queue.h Processor.h Queue.C
Processor.o: Node.h Queue.h Processor.h Processor.C
