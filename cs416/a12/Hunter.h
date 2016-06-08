//Victor Maloney CS 416 Assignment 12

#ifndef HUNTER_H
#define HUNTER_H

/* comment */

#include <iostream.h>

class Hunter {
	friend ostream& operator <<(ostream &s, const Hunter &v);
		//outputs hunter's name and the items that he/she has
		//found so far

	public:
		Hunter();
			//constructs empty hunter with no name or items

		Hunter(const char name[]);
			//constructs hunter with given name and no items

		void addItem(int item);
			//adds item to those hunter has found already.
			//if an item is added more than once the subsequent
			//additions are ignored.

		//relational and equality operators
		bool operator ==(const Hunter &v) const;
		bool operator !=(const Hunter &v) const;
		bool operator <(const Hunter &v) const;
		bool operator >(const Hunter &v) const;

	private:
		enum{namelen = 26};
		char myName[namelen];
		unsigned long items;
};

#endif
