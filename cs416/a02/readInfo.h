#include <iostream.h>
#include <fstream.h>

// --------------------------------------------------------
/* this procedure reads in information from a file and places
	it in the array passed, passing back the number of items
	placed in the array.  It is assumed that the array is 
	large enough to contain the items read.

	By default, the file name is information.dat.  If that
	file is not available, a file name will be prompted for
	repeatedly until an available file is specified. 
*/

template<typename InfoType>
void readInfo(InfoType arr[], int &n)
{
	char filename[200] = "information.dat";
	ifstream f(filename);
	InfoType value;
	int i = 0;

	while (!f) {
		cerr << "cannot read from file [" << filename << "]\n";
		cerr << "input another file name ?> ";
		cin >> filename;
		f.open(filename);
	}

	while (f >> value)
		arr[i++] = value;

	n = i;
	f.close();
}
