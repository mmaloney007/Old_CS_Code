// Victor m. Maloney Assignment 5 003 64 7871

/* this is the code file for the "author" class.  it keeps track of an
authors name and id number.  it has boolean ops for comparision and
sorting.  it uses a string to keep track of the name and has input and
output operators. */

#include <iostream.h>
#include "Aut.h"

//initilizes an author

Aut::Aut()
{
	autid = 0;
	name[0] = '\0';
}

//returns true if id >= the int passed

bool Aut::operator >=(int b) const
{
	return autid >= b;
}

//returns true if author id is not equal to int a

bool Aut::operator !=(int b) const
{
	return autid != b;
}

//returns true if the id number's of the two authors are equal

bool Aut::operator ==(const Aut &b) const
{
	return autid == b.autid;
}

//returns true if left id is less than right id

bool Aut::operator <(const Aut &b) const
{
	return autid < b.autid;
}

//returns true if author id is less than the int id

bool Aut::operator <(int id) const
{
	return autid < id;
}

//puts contents of right op into left hand op

void Aut::operator =(const Aut &b)
{
	strcpy(name, b.name);
	autid = b.autid;
}

//inputs a book, author name and id

istream& operator >>(istream &s, Aut &b)
{
	const int maxAut = 50;
	s >> b.autid;
	s.get(b.name, maxAut);
	return s;
}

//outputs the author's name

ostream& operator <<(ostream &s, const Aut &b)
{
	s << b.name;
	return s;
}
