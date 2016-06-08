
all:	test1 test2 test3 test4a test4b test5 testkill1 testkill2 testkill3 testsusp1 testsusp2 testsusp3
tests: test1 test2 test3 test4a test4b test5
prob: testkill1 testkill2 testkill3 testsusp1 testsusp2 testsusp3
test1:
	gcc test1.c thread.c thr_asm.s -o test1
test2:
	gcc test2.c thread.c thr_asm.s -o test2
test3: 
	gcc test3.c thread.c thr_asm.s -o test3 
test4a:
	gcc test4a.c thread.c thr_asm.s -o test4a
test4b:
	gcc test4b.c thread.c thr_asm.s -o test4b
test5:
	gcc test5.c thread.c thr_asm.s -o test5
testkill1:
	gcc testkill1.c thread.c thr_asm.s -o testkill1
testkill2:
	gcc testkill2.c thread.c thr_asm.s -o testkill2
testkill3:
	gcc testkill3.c thread.c thr_asm.s -o testkill3
testsusp1:
	gcc testsusp1.c thread.c thr_asm.s -o testsusp1
testsusp2:
	gcc testsusp2.c thread.c thr_asm.s -o testsusp2
testsusp3:
	gcc testsusp3.c thread.c thr_asm.s -o testsusp3

test1: test1.c thread.c thr_asm.s
test2: test2.c thread.c thr_asm.s
test3: test3.c thread.c thr_asm.s
test4a: test4a.c thread.c thr_asm.s
test4b: test4b.c thread.c thr_asm.s
test5: test5.c thread.c thr_asm.s
testkill1: testkill1.c thread.c thr_asm.s
testkill2: testkill2.c thread.c thr_asm.s
testkill3: testkill3.c thread.c thr_asm.s
testsusp1: testsusp1.c thread.c thr_asm.s
testsusp2: testsusp2.c thread.c thr_asm.s
testsusp3: thread.c thr_asm.s testsusp3.c

clean:
	rm test1 test2 test3 test4a test4b test5 testkill1 testkill2 testkill3 testsusp1 testsusp2 testsusp3
