//Victor Maloney CS 416 Assignment # 12

/* this class defines a hunter in a scavenger hunt.  each hunter has a
name and the items that they have found so far.  the program uses bit
manipulation to control the items found during the hunt.  items are
numbered from 1 through 32 inclusive since there are 32 bits in a long
interger.*/

#include <iostream.h>
#include "Hunter.h"
#include <string.h>

//constructs empty hunter with no name or items

Hunter::Hunter()
{
	myName[0] = '\0';
	items = 0;
}

//constructs hunter with given name and no items

Hunter::Hunter(const char name[])
{
	strcpy(myName, name);
	items = 0;
}

//adds item to those hunter has already found.  If an item is added more than
//once the subsequent additions are ignored

void Hunter::addItem(int item)
{
	unsigned long mask;
	mask = 1L << (item-1);
	items |= mask;
}

//relational and equality operators

bool Hunter::operator ==(const Hunter &v) const
{
	return strcmp(myName, v.myName) == 0;
}

bool Hunter::operator !=(const Hunter &v) const
{
	return strcmp(myName, v.myName) != 0;
}

bool Hunter::operator <(const Hunter &v) const
{
	return strcmp(myName, v.myName) < 0;
}
	
bool Hunter::operator >(const Hunter &v) const
{
	return strcmp(myName, v.myName) > 0;
}

//outputs hunter's name and the items that he/she has found so far

ostream& operator <<(ostream &s, const Hunter &v)
{
	int count = 1;
	unsigned long mask = 1;
	
	cout << v.myName;

	while(mask){
		if(mask &v.items)
			cout << " " << count;
		mask <<= 1;
		count++;
	}
}
	
