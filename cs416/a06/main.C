//Victor Maloney Cs 416 assignment 6

/* this main program is only used to invoke functions through an string
command input in the prompt.  it uses to classes to control funtions that
would be invoke in the classes developed for a video store to keep track
and rent out movies to constumers. */

#include <iostream.h> 
#include "Inventory.h"
#include "Video.h"

int main()
{
	const int maxT = 150;

	Inventory store;
	int i; 
	int id;
	int n=0;
	char com[30];
	char tit[maxT];
	char dum[maxT];
	char ch;
	Video vid;

	cout << "?> ";
	cin >> com;
	
	while(strcmp(com, "exit") != 0){
		
		if (strcmp(com, "rent") == 0){
			cin >> id;
			vid = id;
			store.rentaVideo(vid);
		}

		else if (strcmp(com, "return") == 0){
			cin >> id;
			vid = id;
			store.returnVideo(vid);
		}

		else if (strcmp(com, "check") == 0){
			cin.get(ch);
			cin.get(tit, maxT);	
			vid = tit;
			store.checkVideo(vid);
		}

		else if (strcmp(com, "printid") == 0){
			cout << "id\tin\tout\ttitle\n";
			store.printId(cout);
		}

		else if (strcmp(com, "printtitle") == 0){
			cout << "id\tin\tout\ttitle\n";
			store.printTitle(cout);
		}
	
		else {
			cout << "bad command [" << com << "] - ignored\n";
			cin.getline(dum, maxT);
		}
	
		cout << "?> ";
		cin >> com;
	}

	return 0;
}
