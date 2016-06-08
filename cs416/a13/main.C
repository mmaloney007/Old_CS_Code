//Victor Maloney CS 416 Assignment # 13

/* this is a program that can take in a number of files and put them into
a list that is used to look at what student have done and what grades they
have gotten over the years.  it will take as many files as you want and
weeds out duplicate grades.  it is simple and will now work without the
right files or usage at the command line. */

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include "List.h"
#include "Student.h"

class NotOpen{};

int main(int argc, const char *argv[])
{
	fstream in;
	Student student;
	List <Student> list('~');
	int i(1);

	if (argc == 1){
		cerr << "usage: a.out file file ...\n";
		exit(1);
	}

	while (i < argc){
		try{
			in.open(argv[i], ios::in);
			
			if (!in)
				throw NotOpen();
			
			cout << "processing ["<< argv[i] << "]\n";
			in >> student;	
			while(in){
				list.insert(student);
				in >> student;
			}
		}
			catch(...){
				cerr << "the file [" << argv[i];
				cerr << "] cannot be opened - ignored\n";
			}
		in.close();
		i++;
	}
	list.output(cout);
	cout << "normal termination\n";
	return 0;
}
