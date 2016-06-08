//Victor Maloney CS 416 assignment number 11

/* this program keeps track of the inventory of a regular electronics
store. It sell, find, add, delete, print, new and quit commands.  The
original inventory is stored in a file and when the program exits the new
inventory will be back at the same file. */

#include <iostream.h>
#include "Store.h"
#include "List.h"
#include <fstream.h>
#include <string.h>

void sell(List&, char[], int);
void find(List&, char[]);
void add(List&, char[], int);

int main()
{
	const int maxCommand = 10;
	const int maxName = 100;
	const int maxModel = 20;
	Store store;
	List list;
	ifstream in;
	ofstream out;
	char command[maxCommand];
	char name[maxName];
	char model[maxModel];
	int quantity;

	cout << "enter database file name: ";
	cin >> name;
	in.open(name, ios::in);

	while(!in){
		cerr << "  ** cannot open [" << name << "] for input - "
			<< "enter new filename ?> ";
		cin >> name;
		in.open(name, ios::in);
	}
	
	in >> store;
	while(in){
		list.insert(store);
		in >> store;
	}

	cout << "enter commands, end with quit\n\n?> ";

	while(cin >> command && strcmp(command, "quit") != 0){
		try {
			if(strcmp(command, "sell") == 0){
				Store value;
				cin >> model;
				Store tmp(model);
				
				if (!list.find(tmp, value))
					throw List::NoItem();
				else {
					cin >> quantity;
					sell(list, model, quantity);
				}
			}
	
			else if(strcmp(command, "find") == 0){
				cin >> model;
				find(list, model);
			}

			else if(strcmp(command, "add") == 0){
				Store value2;
				cin >> model >> quantity;
				Store tmp2(model, quantity);
			
				if(!list.find(tmp2, value2))
					throw List::NoItem();
				else 	
					add(list, model, quantity);
			}

			else if(strcmp(command, "delete") == 0){
				cin >> model;
				Store tmp(model);
				if (!list.remove(tmp))
					throw List::NoItem();
			}

			else if(strcmp(command, "print") == 0)
				list.output(cout);
		
			else if(strcmp(command, "new") == 0){
				Store value3;
				cin >> store;
				if (list.find(store, value3))
					throw List::ItemHere();
				else
				
					list.insert(store);
			}

			else
				cerr << "*** bad command [" << command
					<< "] - ignored\n";
		}
			catch(List::NoStock){
				cerr << "  ** insufficient stock **\n";
			}
		
			catch(List::ItemHere){
				cerr << "  ** item already exists in database **\n";
			}

			catch(List::NoItem){
				cerr << "  ** no such item **\n";
			}
			
		cout << "\n?> ";
	}
	
	in.close();
	out.open(name, ios::out);
	list.output(out);
	out.close();
	cout << "normal termination\n";
	return 0;
}

void sell(List &l, char m[], int q)
{
	Store value;

	Store tmp(m, -q);
	if (l.find(tmp, value)){
		tmp.combine(value);
		l.replace(tmp);
	} 
}

void find(List &l, char m[])
{
	Store value;
	Store tmp(m);

	if(!l.find(tmp, value))
		throw List::NoItem();
	else
		cout << value;
}

void add(List &l, char m[], int q)
{			
	Store value;
	Store tmp(m, q);
	if (l.find(tmp, value)){
		tmp.combine(value);
		l.replace(tmp);
	}
}
