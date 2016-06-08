#include <stdio.h>

#ifndef NULL
#define NULL 0
#endif
#define status(part,total) fprintf(stderr, "(%d/%d)\n", part, total)

extern long thread_create(void (*)(void*), void*);
extern void thread_yield();

void thread1(void* info);
void thread2(void* info);

main()
{
  thread_create(thread1, NULL);
  status(0,5);
  thread_yield();
  status(2,5);
  thread_yield();
  status(5,5);
}

void thread1(void* info) 
{
  status(1,5);
  thread_create(thread2, NULL);
  thread_yield();
  status(4,5);
}

void thread2(void* info) 
{ 
  status(3,5);
  thread_yield();
}
