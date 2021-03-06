#include <stdio.h>

#ifndef NULL
#define NULL 0
#endif
#define status(part,total) fprintf(stderr, "(%d/%d)\n", part, total)

extern long thread_create(void (*)(void*), void*);
extern void thread_yield();
extern long thread_suspend(long thread_id);
extern long thread_continue(long thread_id);
extern long thread_self(void);
extern long thread_kill(long thread_id);

void thread1(void* info);
void thread2(void* info);

main()
{
  long tid1, tid2;
  tid1 = thread_create(thread1, NULL);
  tid2 = thread_create(thread2, NULL);

  if (thread_kill(tid1) != 1) 
    fprintf(stderr, "** Incorrect return value for successful kill\n");
  if (thread_kill(tid1+456) != 0) 
    fprintf(stderr, "** Incorrect return value for unsuccessful kill\n");

  thread_kill(tid2);

  if (thread_kill(thread_self()) == 1)
    fprintf(stderr, "** incorrect return value for attempt to kill main\n");

  thread_yield();
}

void thread1(void* info) 
{
  fprintf(stderr, "** error: killed thread running\n");
  thread_yield();
}

void thread2(void* info)
{
  fprintf(stderr, "** error: killed thread running\n");
  thread_yield();
}
