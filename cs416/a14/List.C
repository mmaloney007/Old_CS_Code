//Victor Maloney CS 416 Assignment 13

/* this is a fairly simple list class that is ripped off basically from
the last assignment.  it also has an iterator in the list class with two
functions yield and reset.  other than that is is simple as can be.  it
doesn't do duplicates also. lots of love.  'the vic' */ 

#include <iostream.h>
#include "List.h"
#include "Word.h"

//constructs a list using this arguement for the tail
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

//inserts the item if the item is already there it throw an exception 
void List::insert(const Word &v)
{
	Elem *prev, *p, *ptr;
	prev = 0;
	p = head;
	
	while (p && (p -> info) < v){
		prev = p;
		p = p-> next;
	}
	if(p && p -> info == v){
	}
	else if(prev != 0){
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

void List::reset()
{
	nextElem = head;
}

bool List::yield(Word &v)
{
	if(nextElem == 0)
		return false;
	else {
		v = nextElem -> info;
		nextElem = nextElem -> next;
		return true;
	}
}
