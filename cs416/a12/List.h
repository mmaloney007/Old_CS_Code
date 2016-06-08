//Victor MAloney CS 416 Assignment # 12

#ifndef LIST_H
#define LIST_H

/* this is a standard list class to be used with a hunter.  it is
dynamically allocated as specs desire.  the copy constructor and the
assignment operator are not implemented.  that is all cause stone cold
said so. */ 

#include <iostream.h>
#include "Hunter.h"

class List {
	
	public:

		List();
			//constructs an empty list

		~List();
			//destructor

		bool empty() const;
			//returns true if list is empty

		bool find(Hunter v, Hunter &value);
			//returns true if v is found and passes it to value

		void replace(Hunter v);
			//finds the item and if it is there it replaces it
	
		bool remove(Hunter v);
			//if item is found it is removed and true is returned

		void insert(const Hunter &v);
			//inserts the item if item is already there it returns
			//false

		bool output(Hunter &value);
			//outputs each object in the list

	private:
		struct Elem {
			Hunter info;
			Elem *next;
		};
		Elem *head;
		
		List& operator =(const List &);
			//assignment operator - not implemented

		List(const List &);
			//copy constructor - not implemented
};

#endif 



