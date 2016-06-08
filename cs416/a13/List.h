//Victor MAloney CS 416 Assignment # 12

#ifndef LIST_H
#define LIST_H

/* this list class is a template class which uses sentinals in the class
to make it easier to insert a student or whatever into the list.  so of
the operatoins commonly given are not implemented. */ 

#include <iostream.h>

template <class T>
class List {
	
	public:
		class NotOpen{};
		class ItemHere{};
		
		List(char v);
			//constructs an empty list

		~List();
			//destructor

		void insert(const T &v);
			//inserts the item if item is already there it returns
			//false

		ostream& output(ostream &s);
			//outputs each object in the list

	private:
		struct Elem {
			T info;
			Elem *next;
		};
		Elem *head;
		
		List& operator =(const List &);
			//assignment operator - not implemented

		List(const List &);
			//copy constructor - not implemented
};

#include "List.T"

#endif 


