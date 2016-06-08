//Victor Maloney CS 416 Assignment number 11

/* this class is a list class built using a chain of dynamically allocated
elements.  it has a find function so it will be order.  it will have an
inventory for a store */

#include <iostream.h>
#include "List.h"
#include "Store.h"

//constructs an empty list

List::List()
{
	head = 0;
}

//destructor

List::~List()
{
	Elem *p;
	
	while (head){
		p = head;
		head = head -> next;
		delete p;
	}
}

//returns true if list is empty

bool List::empty() const
{
	return head == 0;
}

//returns true if v is found and passes it to value

bool List::find(Store v, Store &value)
{
	Elem *p;

	p = head;

	while (p && p -> info < v)
		p = p -> next;

	if (!(p -> info == v))
		return false;
	else
		value = p -> info;
		return true;
}

//finds the item and if it is there it replaces it

void List::replace(Store v) throw(NoItem())
{
	Elem *p;
	p = head;
	while (p && p -> info < v)
		p = p-> next;

	if (p == 0)
		throw NoItem();
	else
		p -> info = v;
}

//if item is found it is removed and true is returned

bool List::remove(Store v)
{
	Elem *prev, *p;
	p = head;

	while(p != 0 && p -> info < v){
		prev = p;
		p = p -> next;
	}
	
	if(p == 0 || p -> info != v)
		return false;
	else if (prev != 0){
		prev -> next = p -> next;
		delete p;
		return true;
	}
	
	else {
		head = p -> next;
		delete p;
		return true;
	}
}

//inserts the item if the item is already there it throw an exception 

void List::insert(const Store &v) throw(ItemHere())
{
	Elem *prev, *p, *ptr;
	prev = 0;
	p = head;
	
	while (p && (p -> info) < v){
		prev = p;
		p = p-> next;
	}
	
	if (p != 0 && p -> info == v)
		throw ItemHere();

	if (prev != 0) {
		ptr = new Elem;
		ptr -> info = v;
		ptr -> next = p;
		prev -> next = ptr;
	}
	else {
		ptr = new Elem;
		ptr -> info = v;
		ptr -> next = p;
		head = ptr;
	}
}	 
		
//outputs each element of the list

ostream& List::output(ostream &s)
{
	Elem *p;
	p = head;
	
	while(p){
		s << p -> info;
		p = p -> next;
	}
	
	return s;
}
