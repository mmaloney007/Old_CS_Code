//Victor Maloney CS 515 Assignment 4

#include <iostream.h>
#include <stdlib.h>
#include "Lhash.h"

/* 
	This is teh code file for a Litwin hash table.  It has a constructor,
	insert, deletekey, search, print table, and findlongest function.  It 
	is fairly straight forward.
*/

//Constructor
Lhash::Lhash()
{
	int i = 0;

	n = 0;
	p = 0;
	r = 2;
	l = 0;
	lf = 0;
	m = 2;
	mod = m;

	for(i = 0; i < 2500; i++)
		ht[i] = NULL;
} 

//searchs for a key returning the index
int Lhash::search(int k)
{
	int index;
	int tmphelp;
	int i = 0;
	bucket *tmp;
	bucket *tmp2;
	bucket *tmp3;
	bucket *ptr;
	bucket *t;

	tmphelp = scramble(k);
	index = tmphelp % mod;
	tmp = ht[index];

		while(tmp){
			if((tmp -> key) == k)
				return index; 
			tmp = tmp -> next;
		}

	index = tmphelp % (mod * 2);
	tmp = ht[index];

		while(tmp){
			if((tmp -> key) == k)
				return index; 
			tmp = tmp -> next;
		}

	while(i < r)
	{
	tmp = ht[i];

		while(tmp){
			if((tmp -> key) == k)
				return i; 
			tmp = tmp -> next;
		}
	i++;
	}

	return -1;
}

//this function scrambles the keys
int Lhash::scramble(int key)
{
	const long long a=16807;
	const long long b=2147483647;
	return int((a*key)%b);
}

//this functiion inserts a key
bool Lhash::insert(int k)
{

	int index;
	int tmphelp;
	bucket *tmp;
	bucket *tmp2;
	bucket *tmp3;
	bucket *ptr;
	bucket *t;

	tmphelp = scramble(k);
	index = tmphelp % mod;

	if(index < p)
		index = tmphelp % (mod * 2);

	tmp = ht[index];
	if(tmp == NULL) {
		tmp = new bucket;
		tmp -> key = k;
		tmp -> next = NULL;
		ht[index] = tmp;
	}
	else {

	tmp2 = tmp;
		while(tmp){
			if(tmp -> key == k)
				return false; 
			tmp2 = tmp; 
			tmp = tmp -> next;
		}
		tmp2 -> next = new bucket;
		tmp = tmp2 -> next;
		tmp -> key = k;
		tmp -> next = NULL;
	}
	n++;

	lf = ((float(n))/ (float(r)));

	if(lf > 1.1){
	tmp = ht[p];
	ht[p] = NULL;
	ptr = tmp;

	while(tmp){
	tmphelp = scramble(tmp -> key);
	index = tmphelp % (mod * 2);
	tmp2 = ht[index];

	if(tmp2 == NULL) {
		tmp2 = new bucket;
		tmp2 -> key = tmp -> key;
		tmp2 -> next = NULL;
		ht[index] = tmp2;
	}
	else {

		tmp3 = tmp2;
		while(tmp2){
			tmp3 = tmp2;
			tmp2 = tmp2 -> next;
		}
		tmp3 -> next = new bucket;
		tmp2 = tmp3 -> next;
		tmp2 -> key = tmp -> key;
		tmp2 -> next = NULL;
		}
		tmp = tmp -> next;
	}
	tmp3 = ptr;
	while(ptr){
		tmp3 = ptr;
		ptr = ptr -> next;
		delete tmp3;
	}

	p++;
	r++;
	}

	if(r == (mod * 2)){
		p = 0;
		l++;
		mod = (mod * 2);
	}
	return true;
}

//this functions finds a key if it exists and deletes it
bool Lhash::deletekey(int k)
{
	bool success;
	int index;
	int tmphelp;
	bucket *tmp;
	bucket *tmp2;
	bucket *tmp3;
	bucket *ptr;
	bucket *prev;

	index = search(k);

	if(index == -1)
		 return 0;

	tmp = ht[index];
	if(tmp -> key == k){
		ht[index] = tmp -> next;
		delete tmp;
		tmp = NULL;
		}
	else {
		prev = tmp;
		tmp = tmp -> next;
		while(tmp){
			if((tmp -> key) == k){
				prev -> next = tmp -> next;
			delete tmp;
			tmp = NULL;
			}
			else {
				if(tmp -> next == NULL)
					return false;//success = 0;
				else { 
					prev = tmp; 
					tmp = tmp -> next;
				}
			}
		}
	}	
	n--;
	

	if((float(n)/float(r-1)) <= 1.1)
	{

	tmp = ht[r-1];
	ht[r-1] = NULL;
	ptr = tmp;

	while(tmp){
		tmphelp = scramble(tmp -> key);
	if(mod > 2) 
		index = (tmphelp % (mod / 2));
	else
		index = (tmphelp % (mod * 2));

	tmp2 = ht[index];

	if(tmp2 == NULL) {
		tmp2 = new bucket;
		tmp2 -> key = tmp -> key;
		tmp2 -> next = NULL;
		ht[index] = tmp2;
	}
	else {

		tmp3 = tmp2;
			while(tmp2){
				tmp3 = tmp2;
				tmp2 = tmp2 -> next;
			}
		tmp3 -> next = new bucket;
		tmp2 = tmp3 -> next;
		tmp2 -> key = tmp -> key;
		tmp2 -> next = NULL;
		}
	tmp = tmp -> next;
	}
	tmp3 = ptr;
	while(ptr){
		tmp3 = ptr;
		ptr = ptr -> next;
		delete tmp3;
	}

	p--;

	if(r > 2)
		r = (r-1);
	}	

	if(p < 0){
		if(mod > 2){
			mod = (mod / 2);
			p = (mod - 1);
			l = (l - 1);
		}
		else
			p = 0;
	}
	
	return success;

}

//prints all buckets indicies and contests
void Lhash::print()
{
	cout << "\nThis is the Hash Table as is:\n";

	bucket *tmp;
	int i;
	i = 0;
	while(i < r){

	tmp = ht[i];
	cout << i << ". ";

	while(tmp){
		cout << tmp -> key << " ";
		tmp = tmp -> next;

	}
	i++;

	cout << '\n';
	}
	cout << "n = " << n << '\n';
	cout << "r = " << r << '\n';
	cout << "lf = " <<float(n)/float(r) << '\n';

}

//returns the number of keys in the longest linked list
int Lhash::findLongest()
{
	int i = 0;
	int index = 0;
	int japs = 0; 
	int longest = 0;
	bucket *tmp;

	while(i < (r-1))
	{
	index = i;
	tmp = ht[index];
		while(tmp){
			tmp = tmp -> next;
			japs++;
		}
	if(japs >= longest)
		longest = japs;
	japs = 0; 

	i = i + 1;
	}

	return longest;
}
