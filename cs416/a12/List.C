//Victor Maloney CS 416 Assignment 12

/* this is a standard list class modified to be used with a hunter from a
scavenger hunt.  there is nothing special about it and it is dynamcially
allocated as specs require. */ 

#include <iostream.h>
#include "List.h"
#include "Hunter.h"

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

bool List::find(Hunter v, Hunter &value)
{
	Elem *p;

	p = head;
	while (p && p -> info < v){
		p = p -> next;
	}
	if (p && (p -> info == v)){
		value = p -> info;
		return true;
	}
	else
		return false;
}

//finds the item and if it is there it replaces it

void List::replace(Hunter v) 
{
	Elem *p;
	p = head;
	while (p && p -> info < v)
		p = p-> next;

	if (p != 0)
		p -> info = v;
}

//if item is found it is removed and true is returned

bool List::remove(Hunter v)
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

void List::insert(const Hunter &v)
{
	Elem *prev, *p, *ptr;
	prev = 0;
	p = head;
	
	while (p && (p -> info) < v){
		prev = p;
		p = p-> next;
	}
	if (p && p -> info == v){
	}

	else if (prev != 0) {
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

bool List::output(Hunter &value)
{
	static Elem *p;
	static bool first = true;
	if (first){
		p = head;
		first = false;
	}

	if(p){
		cout << p -> info;
		value = p -> info;
		p = p -> next;
		return true;
	}
	
	else
		return false;
}
