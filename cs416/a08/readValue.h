#include <iostream.h>
#include <fstream.h>

// --------------------------------------------------------
/* this success/fail procedure attempts to read in one item of
	information from a file.  If successful, the value is passed 
	back in the parameter (variable) passed and the return value
	for the procedure will be true.  If there was no information
	left to read, the procedure will "fail", and will return false.
	In the case of failure, the contents of the passed variable 
	is unknown.

	By default, the file name is videoinfo.dat.  If that
	file is not available, a file name will be prompted for
	repeatedly until an available file is specified. 
*/

template<typename InfoType>
bool readValue(InfoType &value)
{
	static bool firstTime = true;
	static char filename[200] = "dvdinfo.dat";
	static ifstream f;

	if (firstTime) {
		f.open(filename);

		while (!f) {
			cerr << "cannot read from file [" << filename << "]\n";
			
			cerr << "input another file name ?> ";
			cin >> filename;
			f.open(filename);
		}

		firstTime = false;
	}

	if (f >> value)
		return true;

	else {
		f.close();
		return false;
	}
}
