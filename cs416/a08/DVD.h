//Victor Maloney CS 416 Assignment 8

/*this is a stupid class that has a few operators for a dvd class.  the
price and id is store private.  it has a output and input operator.  it is
a simple class. one boolean operator*/

#ifndef DVD_H
#define DVD_H

#include <iostream.h>

class DVD {

	friend istream& operator >>(istream &s, DVD &v);
		//inputs a DVD, id number first price second

	friend ostream& operator <<(ostream &s, const DVD &v);
		//outputs a DVD id then number

	public:

		DVD();
			//constructs an empty DVD

		float getPrice();
			//returns the price of the DVD

		bool operator !=(int d);
			//returns true if the two id's are not equal

	private:

		int id;
		float price;
};

#endif
