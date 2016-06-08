//Victor Maloney Cs 515 Assignment 4

/*
	This is the large test case program for a Litwin hash table.  It insert
	-s about 2500 random keys then deletes 1985 of them finding the longest
	and then printing the leftover fifteen keys.	
*/

#include <iostream.h>
#include <stdlib.h>
#include "Lhash.h"
static long long seed;
int Random();

int main()
{
	Lhash hash;
	int i = 0;
	int help = 0;
	int longest;
	seed = 12345;

	for(i = 0; i < 2000; i++)
	{
		hash.insert(Random());
	}

	longest = hash.findLongest();	
	cout << "The longest with 2000 items is : ";
	cout << longest;
	seed = 12345;

	for(i = 0; i < 1985; i++)
	{
		hash.deletekey(Random());
	}

	cout << "\n\n";
	cout << "The longest is : ";
	longest = hash.findLongest();
	cout << longest;

	hash.print();

	return 0;
}

int Random()
{
	long long a = 16807;
	long long b = 2147483647;
	seed = ((a * seed) % b);
	return (int(seed));
}
