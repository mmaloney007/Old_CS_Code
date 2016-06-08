//Victor Maloney CS 416 Assignment 13

/* this is a template class which can be used with an list.  it makes uses
the head and tail sentinals which makes it easier to insert things into
the list.  it is a great little template class mostly ripped of from the
last assignment with little modifications. */ 

#include <iostream.h>
#include "List.h"

//constructs a list using this arguement for the tail
template<class T>
List<T>::List(char v)
{
	T st(v);
	T stu('\0');
	Elem *p;
	p = new Elem;
	
	head = p;
	head -> info = stu;
	p = new Elem;
	p ->info = st;
	p ->next = 0;
	head ->next = p;	
}

//destructor
template<class T>
List<T>::~List()
{
	Elem *p;
	
	while (head){
		p = head;
		head = head -> next;
		delete p;
	}
}

//inserts the item if the item is already there it throw an exception 
template<class T>
void List<T>::insert(const T &v)
{
	Elem *prev, *p, *ptr;
	prev = 0;
	p = head;
	
	while (p && (p -> info) < v){
		prev = p;
		p = p-> next;
	}
	if (p && (p -> info) == v)
		cerr << "  ** duplicate -> " << v;
	

	else{
		ptr = new Elem;
		ptr -> info = v;
		ptr -> next = p;
		prev -> next = ptr;
	}
}	 
		
//outputs each element of the list
template<class T>
ostream& List<T>::output(ostream &s)
{
	static Elem *p;
		p = head -> next;
	Elem *ptr;
		ptr = p -> next;


		while(ptr != 0){
		s << p -> info;
		p = p -> next;
		ptr = p -> next;
	}
	return s;
}
