#include <stdio.h>

#ifndef NULL
#define NULL 0
#endif
extern void thread_create(void (*)(void*), void*);
extern void thread_yield();

void thread1(void*);

main()
{
  thread_create(thread1, NULL);
  thread_yield();

  /* at this point, this is the only thread */
  thread_yield();
}

void thread1(void* fubar) 
{
  /* does nothing */
}
