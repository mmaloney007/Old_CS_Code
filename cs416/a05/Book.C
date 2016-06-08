
#ifndef BK_H
#define BK_H

/* This class defines a book which has 2 parts a title and an author pointer
It is used with the Author class.  It has an output operator and a few 
relational operators. */

#include <iostream.h>
#include "Aut.h"

class Bk {
	
	friend ostream& operator << (ostream &s, const Bk &c);
		//outputs a book, author and title
	
	public:
		Bk();
			//constructs an empty book

		void addBk(char c[], Aut *d);
			//adds a book, the pointer to an author and the title

		bool operator <(const Bk &c) const;
			//returns true if left hand operator is less than right

		bool operator ==(const Bk &c) const;
			//returns true if the author of the two books is the same
			

		bool operator !=(int c) const;
			//returns true if the author of the book is not equal 
			//to the intger passed

		void output();
			//outputs just the title of the book
		
		void operator =(const Bk &c);
			//adds contents of right book to left book

	private:

		enum{ maxTit = 150};
		Aut *autPtr;
		char title[maxTit];
};

#endif	
