//Victor Maloney CS 515 Assignment 3

#ifndef LHASH_H
#define LHASH_H

/*
	This is the header file for a LITWIN HASH.
	This forward declares all the functions for the litwin hash table.  it
	has a constrcutor, an insert, a deletekey function, along with a 
	print and a findlongest.
	It also has a search and others.
*/

#include <iostream.h>
#include <stdlib.h>

class Lhash {

	public:
		Lhash();
			//constructor

		bool insert(int k);
			//LITWIN insert

		bool deletekey(int k);
			//LITWIN delete

		void print();
			//this method prints all the buckets and their
			//contents

		int findLongest();
			//this finds the longest chain and prints it

		int scramble(int key);
			//Psuedo Random Key Scrambler
		
		int search(int k);
			//finds the key's index

	private:
		struct bucket{
			int key;
			bucket *next;
		};
	
		int n;
		int r;
		int m;
		int p;
		int l;
		int mod;
		float lf;

		bucket *ht[2500];
};
#endif
