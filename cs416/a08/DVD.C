//Victor Maloney CS 416 Assignmet 8

/*this is a class for dvds it is a stupid class.  not very useful unless
for gettign prices and keeping track of them.  it is not a very hard one
to write.  it has output and input ops. it has one boolean operator to
compare dvds.*/

#include <iostream.h>
#include "DVD.h"

//constructs an empty DVD

DVD::DVD()
{
	id = 0;
	price = 0;
}

//returns the price of the DVD

float DVD::getPrice()
{
	return price;
}

//returns true if the two id's of a given dvd are not equal

bool DVD::operator !=(int d)
{
	return id != d;
}

//inputs a DVD, id number first price second

istream& operator >>(istream &s, DVD &v)
{
	s >> v.id >> v.price;
	return s;
}

//outputs a DVD id then price

ostream& operator <<(ostream &s, const DVD &v)
{
	s << v.id << " -- " << v.price << '\n';
	return s;
}
