//Victor Maloney Assignment IV

/*
  this class creates strings that will keep track of authors and titles
  of books that you input.  it supplies operators for input and
  comparision.  like he said in class though it is not very realistic as
  nothing is stored in secondary memory. 
*/

#include <iostream.h>
#include <string.h>
#include "Book.h"


//constructs empty book type

Book::Book()
{
	_auth[0] = '\0';
	_titl[0] = '\0';
}

//puts contents of rvar into lvar

void Book::operator =(const Book &c)
{
	strcpy(_auth, c._auth);
	strcpy(_titl, c._titl);
}

//returns true if lefthand op is bigger than righthand op

bool Book::operator >(const Book &c) const
{
	if (strcmp(_auth, c._auth) > 0)
		return true;
	else 	
		if (strcmp(_titl, c._titl) > 0 && strcmp(_auth, c._auth) == 0)
			return true;
		else
			return false;
	
}

//returns true if rvar is bigger than lvar

bool Book::operator <(const Book &c) const
{
	if (strcmp(_auth, c._auth) < 0)
		return true;
	else
		if (strcmp(_auth, c._auth) == 0 && strcmp(_titl, c._titl) < 0)
			return true;
		else
			return false;
}

//returns true if books are not equal

bool Book::operator !=(const Book &c) const
{
	if (strcmp(_auth, c._auth) != 0)
		return true;
	else
		if(strcmp(_auth, c._auth) == 0 && strcmp(_titl, c._titl) != 0)
			return true;
		else
			return false;
}

//inputs the author and title of the said book

istream& operator >>(istream &s, Book &c)
{
	char ch;
	char dum;
	int i = 0;
	int j = 0;

	s >> dum;
	s.get(ch);
	
	while(ch != '"'){
		c._auth[i++] = ch;
		s.get(ch);
	}
	
	c._auth[i] = '\0';

	s >> dum;
	s.get(ch);

	while(ch != '"'){
		c._titl[j++] = ch;
		s.get(ch);
	} 

	c._titl[j] = '\0';

	return s;
}

//outputs the author and title of a given book

ostream& operator <<(ostream &s, const Book &c)
{
	s << c._auth << "   " << c._titl;
	return s;
}
