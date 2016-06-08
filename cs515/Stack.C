//Victor Maloney CS 416 Assignment # 9

#include <iostream.h>
#include "Stack.h"

//constructs an empty stack

Stack::Stack()
{
	store = 0;
}

//destructor

Stack::~Stack()
{
	Elem *p;

	while (store != 0){
		p = store;
		store = store -> next;
		delete p;
	}
}

//returns true if stack is empty

bool Stack::empty() const
{
	return store == 0;
}

//adds value to top of stack

void Stack::push(int v)
{
	Elem *p;
	
	p = new Elem;
	p -> next = store;
	p -> val = v;
	store = p;
}

//returns the top element of the stack

int Stack::top() const
{
	if (store == 0)
		cerr << "Stack is Empty\n";
	else
		return store -> val;
}

//returns the number of elements in the stack

int Stack::length() const
{
	Elem *p;
	int count;

	p = store;
	count = 0;
	
	while (p != 0){
		count++;
		p = p -> next;
	}

	return count;
}

//removes top element from stack

void Stack::pop()
{
	Elem *p;

	if (store == 0)
		throw Empty();
	else
		p = store;
		store = store -> next;
		delete p;
}
