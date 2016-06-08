//Victor Maloney Assignment IV

/* this program is designed for use in small book stores.  The
inventory is to be stored in an array, and consists of the book's title, author
and count of each book.  The program asks and respondes to the following
commands buy done sell check print */

#include <iostream.h>
#include "Inventory.h"
#include <string.h> 
#include "Book.h" 
int main()
{
	const int bookName = 200;
	const int commandLength = 20;
	char com[commandLength];	
	Inventory storage;
	Book bk;
	char dummy[bookName];
	cout << "enter commands, terminate with done\n" << "?> ";
	cin >> com;

	while (strcmp(com, "done") != 0){
		
		if (strcmp(com, "buy") == 0){
			cin >> bk;	
			storage.add(bk);
		}
	
		if (strcmp(com, "sell") == 0){
			cin >> bk;
			storage.subtract(bk);
		}

		if (strcmp(com, "check") == 0){
			cin >> bk;
			
			if (storage.find(bk))
				cout << "   book is in stock\n";
				
			else
				cout << "   not in inventory\n";
		}

		if (strcmp(com, "print") == 0){
			cout << "count	book\n-----   ----\n";
			cout << storage;
		}

		if (strcmp(com, "buy") != 0 && strcmp(com, "sell") !=0
			&& strcmp(com, "check") != 0 
			&& strcmp(com, "print") != 0){
			cout << "bad command [" << com << "] - ignored\n";
			cin.getline(dummy, bookName);
		}

		cout << "?> ";
		cin >> com;
	}

	return 0;
}
