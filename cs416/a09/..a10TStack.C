//Victor Maloney CS 416 Assignment # 9

/*this class is a normal stack class that has all the normal operations we were
tought in class an extra one that makes comparision of operators (precedence
easy)  it is a class written by me the vic*/

#include <iostream.h>
#include "TStack.h"
#include "Token.h"

//constructs an empty stack

TStack::TStack()
{
	store = 0;
}

//destructor

TStack::~TStack()
{
	Elem *p;

	while (store != 0){
		p = store;
		store = store -> next;
		delete p;
	}
}

//returns true if stack is empty

bool TStack::empty() const
{
	return store == 0;
}

//adds value to top of stack

void TStack::push(Token v)
{
	Elem *p;
	
	p = new Elem;
	p -> next = store;
	p -> token = v;
	store = p;
}

//returns the top element of the stack

Token TStack::top() const
{
	if (store == 0)
		throw Empty();
	else
		return store -> token;
}

//returns the number of elements in the stack

int TStack::length() const
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

void TStack::pop()
{
	Elem *p;

	if (store == 0)
		throw Empty();
	else
		p = store;
		store = store -> next;
		delete p;
}

//boolean operator

bool TStack::operator >=(Token v)
{
	if(((*this).top()).symvalue() == '~')
	return true;
	else if((((*this).top()).symvalue() == '*' || 
((*this).top()).symvalue() == '/') && (v.symvalue() == '*' ||
v.symvalue() == '/' || v.symvalue() == '-' || v.symvalue() == '+'))
	return true;
	else if((((*this).top()).symvalue() == '+' ||
((*this).top()).symvalue() == '-') && (v.symvalue() == '-' ||
v.symvalue() == '+'))
	return true;
	else 
	return false;
}
