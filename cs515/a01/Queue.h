//Victor Maloney CS 515 Assignment 1

/*
this is the header file for the circular queue.  it containes the operations 
for enqueue, dequeue, empty, construct, and destruct.  it also uses the 
structure contained in node.h as one of it's data members.
*/

#ifndef QUEUE_H
#define QUEUE_H


#include <stdlib.h>
#include <iostream.h>
#include "Node.h"

class Queue {

	public:
		Queue();
			//creates an empty queue

		~Queue();
			//destructor
	
		bool empty() const;
			//returns true if queue is empty

		void enqueue(Node n);
			//puts a node on the queue

		Node dequeue();
			//removes the front item from the stack and
			//returns a node
		
		void print();
			//prints current items on queue
	
	private:

		struct Elem{
			Node q;
			Elem *next;
		};
		Elem *head;

};
#endif
