// Victor M. Maloney Assignment 5 003 64 7871

/* this class keeps track of the authors name and id.  it has input and
output operators.  it has boolean operators to help sort and compare and
also has a string to store the name */

#ifndef AUT_H
#define AUT_H

#include <iostream.h>

class Aut {

	friend istream& operator >>(istream &s, Aut &b);
		//inputs a book, author name and id

	friend ostream& operator <<(ostream &s, const Aut &b);
		//outputs the author's name

	public:
		Aut();
			//initilizes an author	

		bool operator >=(int b) const;
			//returns true if id >= the int passed

		bool operator !=(int b) const;
			//returns true if author id is not equal to int a

		bool operator ==(const Aut &b) const;
			//returns true if the id number's of the two authors 
			//are equal

		bool operator <(const Aut &b) const;
			//returns true if left id is less than right id

		bool operator <(int id) const;
			//returns true if author id is less than the int id

		void operator =(const Aut &b);
			//puts contents of right op into left hand op

	private:
		
		enum {maxAut = 50};
		int autid;
		char name[maxAut];
};

#endif
