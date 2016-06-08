//victor maloney cs 416 assignment 1

//---------------------------------------------------------

//this program helps someone in administration keep track
//of which courses are filled which have been registered
//by people and which students have regestered for a course

//---------------------------------------------------------

#include <iostream.h>
#include "Course.h"

int main()
{
	Course c;
	int studentid;
	const int max = 300;
	int i=0;
	int n;
	int num;
	Course name[max];
	cin >> num;
	while(i < num && cin >> c)
			{
			name[i] = c;
			i++;
			}
	
	cout << "\ninitial course information for " << num;
	
	cout << " courses" << '\n';
	
	cout << "course\tcap\tused\n";
	
	for (i = 0; i < num; i++)
		cout << name[i];
	
	cout << "\nstudent registrations\nid\tcourse\n";
	
	while(cin >> studentid >> n){

	for (i = 0; i < num && name[i] != n; i++);
	
	if(i < num)
		{
		if(name[i].hasSeat())
			{
			name[i].addStudent();
			cout << studentid << "\t" << n << "\tregistered\n";			}
		else
			cout << studentid << '\t' << n << '\t'
			<< "no seat aviable - not registered\n";
		}
	else 
		cout << studentid << '\t' << n << '\t'
		<< "*** no such course ***\n";
	}
	cout << "\nfinal course enrollments\ncourse\tcap\tused\n";
	for (i=0; i < num; i++)
		cout << name[i];
	return 0;
}
