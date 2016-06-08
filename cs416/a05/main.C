// Victor M. Maloney Assignment 5 003 64 7871

/*This program sorts a book store and outputs the author only once
and outputs each books title only once.  it uses a pointer to the authors
name to save space which is different from assignment four as it is closer
to what would really happen*/

#include <iostream.h>
#include "Aut.h"
#include "Bk.h" 

int main()
{
	enum {maxTit = 150, maxAut = 100, maxBoo = 1000};
	Aut idname;
	Aut *authorp;
	int little;
	int id;
	int bottom;
	int middle;
	int top;
	int numBooks;
	char title[maxTit];
	Aut aut[maxAut];
	Bk books[maxBoo];
	Bk book, tmp;
	int i = 0, j = 0, k = 0;
	Bk *bptr[maxBoo];
	
	while (cin >> idname && idname >= 0){
		aut[i++] = idname;
	}
	
	while (cin >> id){
		bottom = 0;
		top = i;
		middle = (bottom + top)/2;
		
		while (bottom <= top && aut[middle] != id){
			
			if (aut[middle] < id)
				bottom = middle + 1;
			else
				top = middle - 1;		
			
			middle = (bottom + top)/2;
		}

		if (bottom <= top){
			cin.get(title, maxTit);
			authorp = &aut[middle];
			book.addBk(title, authorp);
			books[j++] = book;
		}
		else {
			cin.getline(title, maxTit);
			cout <<"aut[" <<id<< "] not found - ignore title\n";
		}
	}

	for(i=0; i < j; i++)
		bptr[i] = &books[i];
		
	for(i=0; i < j-1; i++){
		little = i;
		for(k=i+1; k < j; k++)
			if(*bptr[k] < *bptr[little])
				little = k;
		tmp = *bptr[i];
		*bptr[i] = *bptr[little];
		*bptr[little] = tmp;
	}
	cout << "\n\n" << *bptr[0];

	for(i=0; i < j-1 ; i++)
		if(*bptr[i] == *bptr[i+1]){
			cout << '\n';
			(*bptr[i+1]).output();
		}
		else
			cout << "\n\n" << *bptr[i+1]; 
	cout << "\n\n";		
	return 0;
}
	
