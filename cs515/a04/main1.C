//Victor Maloney Cs 515 Assignment 4

/*
	LITWIN HASH Main Program
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


	for(i = 0; i < 20; i++)
	{
		help = (i);
		hash.insert(help);
	}

	hash.print();

	longest = hash.findLongest();	
	cout << longest;

	for(i = 0; i < 17; i++)
	{
		help = i;
		hash.deletekey(help);
		cout << help << ' ';
	}
	cerr << "After second while \n";

	hash.print();
	cout << "\n\n";
	cout << "Now Delete 18";
	cout << "\n\n";
	cout << "The longest is : ";
	longest = hash.findLongest();
	cout << longest; 
	cout << '\n';

	hash.print();

	hash.deletekey(18);

	longest = hash.findLongest();
	cout << longest; 
	cout << '\n'; 
	hash.print();

	return 0;
}
