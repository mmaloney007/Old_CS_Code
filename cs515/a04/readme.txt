			Victor Maloney
			Cs 515 Assignment 4

	The object of this assignment was to implement a fully working linear 
hashing scheme with an extendable array.  I was only able to get insert and 
delete to work.  Our program was to implement the following functions.

int insert(key) //inserts a key in the table
int delete(key) //named int deletekey(key) //deletes a key in the table
void print() //prints the hash table
void Findlongest() //return the length of longest bucket

We also were supposed to implement this scramble function as a hash:
int Scramble(int key)
{
const __int64 a = 16807; // with linux use long long instead of __int64 
const __int64 b = 2147483647;
return int((a*key)%b);
}

We also were to implement this test case with output listed under "Output 2" in
the end of the readme:

seed = 12345;
for (i=0;i<2000;++i) HT.insert(Random());
long = FindLongest(); // also print out the length of the longest list;
seed = 12345;
for (i=0;i<1985;++i) HT.delete(Random());
HT.print();

Random is simply a function like Scramble but with a seed instead of a key.

The Linear hash is supposed to be the quickest easiest data structure to date 
that our class has gotten.  I feel it is hard to implement and that if you get 
clustering it can be simply like an unbalanced binary tree. This is teh output 
from my test case that was given to us:

Output 2:

The longest with 2000 items in it is : 7

The longest is : 3
This is the Hash Table as is:
0. 198982189 
1. 505231433 
2. 274354193 
3. 1538715103 
4. 853245353 
5. 
6. 44980042 
7. 1746336852 1857530106 
8. 423531642 
9. 1534944292 65322150 1535500936 
10. 661612144 1024468015 
11. 
12. 
13. 87664233 
n = 15
r = 14
lf = 1.07143

I also outputed the n and r at the movement.  Just to prove that the
program was working correctly.

Output1 (below) is the output from a small test harness below that I came 
up with:

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
	cout << "18";
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
Output 1:


This is the Hash Table as is:
0. 0 
1. 
2. 14 
3. 5 
4. 12 
5. 3 19 
6. 10 
7. 1 17 
8. 8 
9. 15 
10. 6 
11. 13 
12. 4 
13. 11 
14. 2 18 
15. 9 
16. 16 
17. 7 
18. 
n = 20
r = 19
lf = 1.05263
20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
This is the Hash Table as is:
0. 
1. 19 17 
2. 18 
n = 3
r = 3
lf = 1


Now Delete 18

The longest is : 2

This is the Hash Table as is:
0. 
1. 19 17 
2. 18 
n = 3
r = 3
lf = 1
0

This is the Hash Table as is:
0. 
1. 19 17 
n = 2
r = 2
lf = 1

As you can see it also worked is this case so I can deduce that my
insert and delete work for the litwin hash table.  This is also by
far the quickest way to store stuff because as you can see by the second
output which is output one a minimal amount of access are required to find
the data. 
