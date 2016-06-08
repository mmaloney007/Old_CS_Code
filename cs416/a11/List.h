//Victor Maloney CS 416 Assignment number 11

#ifndef LIST_H
#define LIST_H

/* this class is a list class built using a chain of dynamically allocated
elements.  It is going to be used to store the inventory for an electronic
store.  It also throws expections for Not item no stock and item here */

#include <iostream.h>
#include "Store.h"

class List {
	
	public:
		class NoItem{};
		class ItemHere{};
		class NoStock{};

		List();
			//constructs an empty list

		~List();
			//destructor

		bool empty() const;
			//returns true if list is empty

		bool find(Store v, Store &value);
			//returns true if v is found and passes it to value

		void replace(Store v) throw(NoItem());
			//finds the item and if it is there it replaces it
	
		bool remove(Store v);
			//if item is found it is removed and true is returned

		void insert(const Store &v) throw(ItemHere());
			//inserts the item if item is already there it returns
			//false

		ostream& output(ostream &s);
			//outputs each object in the list

	private:
		struct Elem {
			Store info;
			Elem *next;
		};
		Elem *head;
		
		List& operator =(const List &);
			//assignment operator - not implemented

		List(const List &);
			//copy constructor - not implemented
};

#endif
