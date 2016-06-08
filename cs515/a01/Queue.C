//Victor Maloney CS 515 Assignment 1
//Correct Circular Queue

/*
this class implements a circular queue.  it is able to enqueue, dequeue, 
construct, destruct, and test if it is empty.  it uses node.h to contain it's 
data.
*/

#include <stdlib.h>
#include <iostream.h>
#include "Queue.h"
#include "Node.h"

//constructs an empty queue

Queue::Queue()
{
	head = 0;
}

//destructor

Queue::~Queue()
{
	Elem *p;
	if(head){
		p = head -> next;
	
		while(p -> next != head)
			p = p -> next;
		
		p -> next = 0;
	
		while(head){
			p = head;
			head = head -> next;
			delete p;
		}
	}
}

//returns true if queue is empty

bool Queue::empty() const
{
	if(head == 0)
		return true;
	else
		return false;
}

//puts a node on the queue

void Queue::enqueue(Node n)
{
	Elem *p;
	Elem *ptr;
	Elem *ptr2;

	if(head){
		p = head -> next;
		while(p -> next != head){
			p = p -> next;
		}
		ptr = new Elem;
		ptr -> next = head;
		ptr -> q = n;
		p -> next = ptr;
	}
	else {
		head = new Elem;
		head -> next = head;
		head -> q = n;
	}
}

//removes an item from the queue and returns it's value

Node Queue::dequeue()
{
	Elem *p;
	Elem *ptr;
	Node tmp;

	if(head -> next == head){
		tmp = head -> q;
		delete head;
		head = 0;
		return tmp;
	}
	else {
		p = head -> next;
		ptr = head -> next;
		while(ptr -> next != head)
			ptr = ptr -> next;
		tmp = head -> q;
		delete head;
		ptr -> next = p;
		head = p;
		return tmp;
	}
} 
void Queue::print()
{
	Elem *p;
	if(head)
	{
		p = head;
		cout << p -> q.size << ' ';
		cout << p -> q.starttime << '\n';

		while(p -> next != head)
		{
			p = p -> next;
			cout << p -> q.size << ' ';
			cout << p-> q.starttime << '\n'; 
		}	
	}
	else
		cerr << "Empty Queue\n";
}
