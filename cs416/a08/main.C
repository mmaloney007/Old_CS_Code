//Victor Maloney CS 416 Assignment 8

/*this program uses the two class implementation of the solution.  it uses
a inventory / cart class and a dvd class that is very stupid.  it checks
that commands and the uses functions and is very simple.  all the work is
done in the classes*/

#include <iostream.h>
#include <string.h>
#include "DVD.h"
#include "ShopC.h"
#include "readValue.h"

int main()
{
	enum {maxLine = 50, maxCommand = 10};
	ShopC shopcart;
	ShopC invent;
	DVD movie;
	int id;
	char com[maxCommand];
	char dum[maxLine];

	while (readValue(movie))
		invent.addDVD(movie);

	cout << "enter commands (add, print, or done)\n?> ";
	cin >> com;
	while(strcmp(com, "done")){
		
		if (strcmp(com, "add") == 0){
			cin >> id;
			shopcart.add(invent, id);
		}
	
		else 	if (strcmp(com, "print") == 0)
				shopcart.print();
	
			else {
				cout << "bad command [" << com 
					<< "] - ignored\n";
				cin.getline(dum, maxLine);
			}

		cout << "?> ";
		cin >> com;
	}

	shopcart.print();
	cout << "normal termination\n";
	return 0;
}


