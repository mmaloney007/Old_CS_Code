//Victor Maloney CS 416 Assignment # 14

#ifndef LIST_H
#define LIST_H

/* this list class is very simple it is basically ripped off of the last assignment.  it has a constructor a destructor and an insert
operator.  it also has an iterator as a data member.  it is fairly simple besides that.  peace out.  */ 

#include <iostream.h>
#include "Word.h"

class List {
	
	public:
		class NotOpen{};
		class ItemHere{};
		
		List();
			//constructs an empty list

		~List();
			//destructor

		void insert(const Word &v);
			//inserts the item if item is already there it returns
			//false
		
		void reset();
		
		bool yield(Word &v);

	private:
		struct Elem {
			Word info;
			Elem *next;
		};
		Elem *head;
		Elem *nextElem;
		
		List& operator =(const List &);
			//assignment operator - not implemented

		List(const List &);
			//copy constructor - not implemented
};

#endif
