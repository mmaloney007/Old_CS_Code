//Victor Maloney CS 416 Assignment 12

/* this is the main program as you can see.  it uses lists of hunters to
keep track of a scavenger hunt.  it has a nice little readhunt function
which cuts down on the bulkness of the main code.  it inputs from the file
hunt.dat before going on to standard input redirect from another file on
the command line. it then outputs the hunters in alphabetical order with 
what they found in numerical order.*/

#include <iostream.h>
#include <fstream.h>
#include "Hunter.h"
#include "List.h"

void readhunt(List&, char [], int);

int main()
{
	const int maxName = 20;
	ifstream in;
	ofstream out;	
	List list;
	char name[maxName];
	int item;
	Hunter value;

	in.open("hunt.dat");
	
	if (in){
		while (in.read((char *) &value, sizeof(value)))
				list.insert(value);
	}

	while (cin >> name){
		cin >> item;
		readhunt(list, name, item);
	}

	if (!in){
		out.open("hunt.dat");
	}
	else {
		in.close();
		out.open("hunt.dat");
	}
	
	while(list.output(value)){
		out.write((char *) &value, sizeof(value));
		cout << '\n';
	}

	out.close();
	cout << "normal termination\n";
	return 0;
}

void readhunt(List &list, char name[], int item)
{
	Hunter hunter(name);
	Hunter val;
	if (list.find(hunter, val)){
		val.addItem(item);
		list.replace(val);
	}

	else {
		hunter.addItem(item);
		list.insert(hunter);
	}
}
