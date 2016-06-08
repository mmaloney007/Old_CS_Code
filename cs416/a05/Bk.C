//Victor m. maloney Assignment 5 

/* this is the "book" code file.  it has a pointer to the author and has a
string keep track of the title.  it has an add book function, boolean
operators for a sort and an output operator.  a good little class. */

#include <iostream.h>
#include <string.h>
#include "Bk.h"
#include "Aut.h"

//initilizes a book

Bk::Bk()
{
	autPtr = 0;
	title[0] = '\0';
}

//adds the components of a book to the book

void Bk::addBk(char c[], Aut *d)
{
	autPtr = d;
	strcpy(title, c);
}

//returns true if left op is less than right op

bool Bk::operator <(const Bk &c) const
{
	if(*autPtr == *c.autPtr)
		return strcmp(title, c.title) < 0;
	else  
		if(*autPtr < *c.autPtr)	
			return true;
		else 
			return false;
}

//compares the authors of two books, returns true if they are the same

bool Bk::operator ==(const Bk &c) const
{
	if(*autPtr == *c.autPtr)
		return true;
	else
		return false;
}

//returns true if the id of the author of the book is not equal to the intger

bool Bk::operator !=(int c) const
{
	return *autPtr != c;
}

//outputs just the title of a book

void Bk::output()
{
	cout << "    " << title;
}

//puts contents of right book to left book

void Bk::operator =(const Bk &c)
{
	autPtr = c.autPtr;
	strcpy(title, c.title);
}

//outputs title and author of a given book

ostream& operator <<(ostream &s, const Bk &c)
{
	s << *c.autPtr << "\n    " << c.title;
	return s;
} 
