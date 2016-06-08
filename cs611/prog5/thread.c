//Victor Maloney CS611 Assignment 5

/*
	This file implements a thread library with a selected list of functions
	listed bellow.  You willl find thread_self, thread_continue, thread_kill
	thread_suspend, thread_create, and thread_yield.  This is some assembly
	in a seperate file name "thr_asm.s".  It contains helpers for 
	thread_yield.
*/

#include <stdio.h>
#include <stdlib.h>

//-----initalize integers and others-------------

	// ---Primitaves to implement----

	long thread_self(void);
	long thread_suspend(long thread_id);
	long thread_continue(long thread_id);
	long thread_kill(long thread_id);

	int lengthTCBQ = 0; //---length of active thread Q---
	int lengthSusQ = 0; //---length of suspended thread Q---

	typedef struct t{
		long reg9; //zero bytes
		long reg10; // 8 bytes
		long reg11; // 16 bytes
		long reg12; // 24 bytes
		long reg13; // 32 bytes
		long reg14; // 40 bytes
		long reg15; // 48 bytes
		long regf2; // 56 bytes
		long regf3; // 64 bytes
		long regf4; // 72 bytes
		long regf5; // 80 bytes
		long regf6; // 88 bytes
		long regf7; // 96 bytes
		long regf8; // 104 bytes
		long regf9; // 112 bytes
		long sp; // 120 bytes $30
		long pc; // 128 bytes $26
		long reg16; // 136 bytes
		long reg17; // 144 bytes
		long stackbase;
		long ptrmain;
		struct t *next;
		struct t *prev;
	}TCB;

	//---queue functions---
	//--this queue is emplimented as a cicular queue

	void dequeue(); //---dequeue for regular queue---
	void enqueue(TCB  *v); //---enqueue for regular queue----
	
	TCB *head = 0; // ---regular TCB queue head---
	TCB *tail = 0; // ---regular TCB queue tail---
	TCB *susqh = 0; // ---suspended TCB queue head---
	TCB *susqt = 0; // ---suspended TCB queue tail---
	static mademain = 0; // ---tells if "main's" TCB is made or not---

	TCB *temp; // ---helps in TCB creation---
	char *stk1; // ---helps in TCB creation---

	//whatever function from class

	void whatever_func(void (*func)(void *), void *arg)
	{
		(*func)(arg);
		cleanup();
		lengthTCBQ--;
	}

	//clean up function from class

	int cleanup()
	{
		dequeue();
		if(head != 0)
		{
			sp_yield(head);
		}
	}

	//thread create (makes threads)

	long thread_create(void (*start_func) (void*), void* info)
	{
		if(mademain == 0)
		{
			TCB *tmp;
			char *stk;

			tmp = malloc(sizeof(TCB));
			stk = malloc(16384);

			tmp -> ptrmain = 1;

			tmp -> stackbase = (long)stk;
			tmp -> sp = (long)(stk + 16384);

			enqueue(tmp);
			
			mademain = 1;
		}


		temp = malloc(sizeof(TCB));
		stk1 = malloc(16384);

		temp -> stackbase = (long)stk1;
		temp -> sp = (long)(stk1 + 16384);
		temp -> pc = (long)(&(*whatever_func));
		temp -> reg16 = (long)(&(*start_func));
		temp -> reg17 = (long)info;

		enqueue(temp);

		return (long)temp;
	}

	//thread_yield in c

	void thread_yield(void)
	{
               if(mademain == 0)
               {
			TCB *tmp;
       			char *stk;
			mademain = 1;

	                tmp = malloc(sizeof(TCB));
       			stk = malloc(16384);
	
                        tmp -> ptrmain = 1;             
        	        tmp -> stackbase = (long)stk;
        	       	tmp -> sp = (long)(stk + 16384);

			enqueue(tmp);
		}
		if(lengthTCBQ <= 1)
		{
			return;
		}
		else
		{
			head = head -> next;
			tail = tail -> next;
				
			asm_yield((head -> prev),head);
		}

	}

	//enqueue a tcb ---in the normal queue for active threads---

	void enqueue(TCB *v)
	{
		if(head == 0)
		{
			head = v;
			head -> next = v;
			head -> prev = v;
			tail = head;
		}
		else
		{
			v -> next = head;
			v -> prev = tail;
			tail -> next = v;
			head -> prev = v;
			tail = tail -> next;
		}
		
		lengthTCBQ += 1;
	}

	//dequeue ---removes a tcb and it's memory from active library---

	void dequeue()
	{
		if((head != 0) && (head -> ptrmain != 1))
		{
			TCB *ptr;
		
			ptr = head;
			head = head -> next;
			tail = ptr -> prev;
			head -> prev = ptr -> prev;
	                free((char *)(ptr -> stackbase));
	                free(ptr);
		}
	}

	//thread_self returns the thread_id of the current running thread
	
	long thread_self(void)
	{
		return (long)head;
	}

	//thread_suspend suspends a thread a 1 is returned if succesful
	//a zero otherwise

	long thread_suspend(long thread_id)
	{
		int i = 0;
		TCB *p;
		TCB *ptr = 0;
		p = head;
		for(i = 0;i < lengthTCBQ;i++)
		{
			if((long)(p) == thread_id)
			{
				ptr = p;
				lengthTCBQ--;
			}
				p = p -> next;
		}

		p = susqh;
		for(i = 0;i < lengthSusQ;i++)
		{
			if((long)(p) == thread_id)
			{
				return 1;
			}
			else
			{
				p = p -> next;
			}
		}
		
		if(ptr == 0)
		{
			fprintf(stderr, "thread_suspend could not find the requested thread\n");
			return 0;
		}
		else
		{

			if(ptr == head)
			{
				if(head == (head -> next))
				{
					fprintf(stderr, "Trying to suspend only active thread\n");
					lengthTCBQ++;
					exit(-1);
				}
				else
				{
					head = head -> next;
					i = 33;
				}
			}
		
			if(susqh == 0)
			{
				susqh = ptr;
				susqt = ptr;
				((ptr -> prev) -> next) = ptr -> next;
				((ptr -> next) -> prev) = ptr -> prev;
				ptr -> next = susqh;
				ptr -> prev = susqh;
			}
			else
			{
				((ptr -> prev) -> next) = ptr -> next;
				((ptr -> next) -> prev) = ptr -> prev;
				ptr -> next = susqh;
				ptr -> prev = susqt;
       				susqt -> next = ptr;
				susqh -> prev = ptr;
				susqt = susqt -> next;
			}

			lengthSusQ++;
		
			if(i == 33)
			{
				if(ptr != 0 && head != 0)
				{
					asm_yield(ptr,head);
				}
			}
		}

		return 1;
	}

	//---thread_continue---

	long thread_continue(long thread_id)
	{
		int i;
		TCB *p;
		TCB *ptr = 0;
		p = susqh;
		for(i = 0;i < lengthSusQ;i++)
		{
			if((long)(p) == thread_id)
			{
				ptr = p;
				p = p -> next;
			}
			else
			{
				p = p -> next;
			}
		}
		
		if(ptr == 0)
		{
			fprintf(stderr, "The thread does not exist\n");
			return 0;
		}

		((ptr -> prev) -> next) = ptr -> next;
		((ptr -> next) -> prev) = ptr -> prev;
		enqueue(ptr);

		lengthSusQ--;

		return 1;
	}

	//----thread kill----

	long thread_kill(long thread_id)
	{
		int i;
		TCB *p;
		TCB *ptr;
		ptr = 0;
		p = head;

		if(lengthTCBQ > 1)
		{
			for(i = 0;i < lengthTCBQ;i++)
			{
				if((long)(p) == thread_id)
				{
					ptr = p;
					lengthTCBQ--;
				}
				p = p -> next;
			}
		}
		if(lengthSusQ > 1)
		{
			for(i = 0;i< lengthSusQ;i++)
			{
				if((long)(p) == thread_id)
				{
					ptr = p;
					lengthSusQ--;
				}
				p = p -> next;
			}
		}

		if(ptr == 0)
		{
			fprintf(stderr, "Trying to kill a non-existent thread or main thread\n");
			return 0;
		}
		if(ptr -> ptrmain == 1)
		{
			fprintf(stderr, "Sorry trying to kill main thread\n");
			return 0;
		}

		if(ptr == head)
		{
			TCB *tempory;
			
			tempory = head;
			head = head -> next;
			head -> prev = (tempory -> prev);
			((tempory -> prev) -> next) = head;
			tail = (tempory -> prev);
			free((char *)tempory -> stackbase);
			free(tempory);
		
			if(head != 0)
			{
				sp_yield(head);
			}
		}
		else
		{
			((ptr -> prev) -> next) = ptr -> next;
			((ptr -> next) -> prev) = ptr -> prev;
                        free((char *)(ptr -> stackbase));
                        free(ptr);
		}

		return 1;
	}
