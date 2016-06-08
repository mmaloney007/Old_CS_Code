//Victor Maloney CS 416 Assignment 10

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream.h>
#include "Token.h"

class Queue {

	public:

		Queue();
			//constructs empty queue

		~Queue();
			//destroys queue

		bool empty() const;
			//tells if queue is empty

		void enqueue(Token v);
			//puts value into queue

		int length() const;
			//tells the length of the queue

		Token front() const;
			//tells the value first in line

		void dequeue();
			//removes front element

	private:
		struct Elem{
			Token info;
			Elem *next;
		};
		Elem *head;
		Elem *tail;
};
#endif QUEUE_H
