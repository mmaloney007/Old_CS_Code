//Victor Maloney Assignment II 

/* this program is designed to help keep track of student records
such as credits, id and mine has a nifty little charge procedure
in the class enjoy*/

#include <iostream.h>
#include "readInfo.h"
#include "Class.h"

void readInfo(Class, int &);

int main()
{
	const int max = 250;
	Class mike[max];
	char c;
	int n;
	int id;
	int cred;
	int mid;
	int high;
	int i = 0;
	int j = 0;
	int low = 0;
	int small = 0;
	Class tmp;
	readInfo(mike, n);
	cout << "\nsorted student data\n\nid courses credit\n\n";
	// sort section
	for(i=0; i < n-1; i++){
			small = i;
		for(j=i+1; j < n; j++)
			if(mike[j] < mike[small])
				small = j;
				tmp = mike[i];
				mike[i] = mike[small];
				mike[small] = tmp;
	}
	for(i=0; i < n; i++)
		cout << mike[i] << '\n';
	cout << "\nenter commands, exit with x\n?> ";
	cin >> c;
	// command section
	while (c != 'x'){
	// help section
		if(c == 'h'){
			cout << "\nthis program responds to the";
			cout << " following "; 
			cout << "commmands\n\na id credits -- adds course of";
			cout << " given credits for students\nd id credits ";
			cout << "-- drops course of given credits for "; 
			cout << "students\n";
			cout << "h -- prints this help message\n";
			cout << "x -- causes program to terminate\n\n";
			}
	// add and drop section
		if(c == 'a' || c == 'd'){
			cin >> id >> cred;
			low = 0;
			high = n - 1;
			mid = (low + high)/2;
			while(low <= high && mike[mid] != id){ 
			    if(mike[mid] < id)
				low = mid + 1;
			    else
				high = mid - 1;
		        	mid = (low + high)/2;
			}
			if(low <= high){
		  		if(c == 'a')
					mike[mid].add(cred);
				else
					mike[mid].drop(cred);
			}
			else{	
				cout << "  *** no student with";
				cout << " id [" << id << "]\n";
		}}
		if(c != 'h' && c != 'a' && c != 'd'){
			cout << "  *** bad command [" << c; 
			cout << "] - ignored\n";
			cin >> cred >> id;	
		}
		// bad command section
		cout << "?> ";
		cin >> c;
	}
	cout << "\nstudentid courses credits -- charge\n";
	for(i=0; i < n; i++){
		cout << mike[i] << " -- ";
		mike[i].charge();
		cout << '\n';
	}
	return 0;
}
