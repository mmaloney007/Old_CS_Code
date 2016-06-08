xcache: xcache.o cache.o
	gcc -o xcache xcache.o cache.o

xcache.o: xcache.c cache.h
	gcc -c xcache.c

cache.o: cache.c cache.h
	gcc -c cache.c
