//Victor Maloney Assignment IV

/*
this class keeps track of an inventory books and other things.  it adds
books and subtracts books and has a find device.  it also sorts them for
output
*/

#include <iostream.h>
#include "Inventory.h"
#include "Book.h"

//constructs an empty inventory

Inventory::Inventory()
{
	int i;
	
	numBooks = 0;
	books[maxBooks];
	for (i=0; i < maxBooks; i++)	
		counts[i] = 0;
}

//adds specified book to inventory

void Inventory::add(const Book &book)
{
	int i, j;
	int index;
	
	if (find(book, index))	
		counts[index]++;
	
	else {
		for(i=numBooks; i > 0 && book < books[i-1]; i--);
		for(j=numBooks-1; j >= i && j < numBooks; j--){
			books[j+1] = books[j];
			counts[j+1] = counts[j];
		}

		books[i] = book;
		counts[i] = 1;
		numBooks++;
	}
}

//removes specified book from inventory

void Inventory::subtract(const Book &book)
{
	int i;
	int index;

	if (find(book, index)){
		
		if (counts[index] == 1){
			
			for(i=index; i < numBooks; i++){
				books[i] = books[i+1];
				counts[i] = counts[i+1];
			}
			numBooks--;
		}

		else
			counts[index]--;
	}
	
	else
		cout << "  *** book not in inventory ***\n";
}	

//returns true if book is found in inventory

bool Inventory::find(const Book &book) const
{
	int high, low, mid;
	low = 0;
	high = numBooks - 1;
	mid = (low + high)/2;

	while (low <= high && books[mid] != book){
		
		if (books[mid] < book)
			low = mid + 1;
		else
			high = mid - 1;
	
		mid = (low + high)/2;
	}
	
	if (low <= high) 
		return true;
	else
		return false;
}

//outputs inventory, books and counts

ostream& operator <<(ostream &s, const Inventory &v)
{
	int i;
	for (i=0; i < v.numBooks; i++)
		s << v.counts[i] << "   " << v.books[i] << '\n';
	return s;
}

//private operation used to find if a book is found and where it is found

bool Inventory::find(const Book &book, int &index) const
{
	int high, low, mid;
	low = 0;
	high = numBooks -1;
	mid = (low + high)/2;
	
	while (low <= high && books[mid] != book){
		
		if (books[mid] < book)
			low = mid + 1;
		else
			high = mid - 1;
		
		mid = (low + high)/2;
	}
	
	if (low <= high){
		index = mid;
		return true;
	}

	else
		return false;
}
