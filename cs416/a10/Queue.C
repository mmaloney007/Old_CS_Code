//Victor Maloney CS 416 Assignment # 10

/* this class is the queue class.  It is a first in first out structure.  It
has all the normal operations, enqueue, dequeue, length, front, and
empty.  It holds tokens for evaluating postfix expressions. */

#include <iostream.h>
#include "Queue.h"
#include "Token.h"
#include "Stack.h"

//constructs an empty queue

Queue::Queue()
{
	head = 0;
}

//destructor

Queue::~Queue()
{
	Elem *p;
		
	while(head){
		p = head;
		head = head -> next;
		delete p;
	}
}

//returns true if queue is empty

bool Queue::empty() const
{
	return head == 0;
}

//returns the front element of the queue

Token Queue::front() const
{
	if (head == 0)
		throw Stack::Empty();
	else
		return head -> info;
}

//adds token to the end of the queue

void Queue::enqueue(Token v)
{
	Elem *p;
	
	if (head == 0){
		head = new Elem;
		tail = head;
		head -> info = v;
		head -> next = 0;
	}

	else {
		p = new Elem;
		p -> info = v;
		p -> next = 0;
		tail -> next = p;
		tail = p;
	}
}

//removes front token from queue

void Queue::dequeue() 
{
	Elem *p;

	if (head == 0)
		throw Stack::Empty();
	else {
		p = head;
		head = head -> next;
		delete p;
	}
}
