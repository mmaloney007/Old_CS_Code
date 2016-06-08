//Victor Maloney Assignment IV

/*
  this class helps one to keep track of books in a book store as it uses
  strings to keep track of authors and titles.  it has input and output
  operators as well as comparision ops for ease of use.
*/

#ifndef BOOK_H
#define BOOK_H

#include <iostream.h>

class Book {

	friend istream& operator >>(istream &s, Book &c);
		//takes in the author and title of a given book

	friend ostream& operator <<(ostream &s, const Book &c);
		//sends out the author and title of a given book

	public:
		Book();
			//constructs an empty book

		void operator =(const Book &c);
			//puts the contents of the right hand operand into 
				//lefthand operator
	
		bool operator >(const Book &c) const;
			//returns true if lefthand op is bigger than righthand
				//operator

		bool operator <(const Book &c) const;
			//returns true if lefthand op is less than righthand op

		bool operator !=(const Book &c) const;
			//returns true if books are not equal

	private:
		enum {maxAuth = 99, maxTitl = 199}D;
		char _auth[maxAuth];
		char _titl[maxTitl];
};

#endif


