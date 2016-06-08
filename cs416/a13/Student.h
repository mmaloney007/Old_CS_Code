//Victor Maloney CS 416 Assignment # 13

#ifndef STUDENT_H
#define STUDENT_H

/* this is a student class that has an id number, a name that can be a 100
characters long, an int with a number of grades and an array of bstring
grades.  it has input and output ops along with some boolean
operators. */

#include <iostream.h>
#include "Bstring.h"

class Student {

	friend istream & operator >>(istream &s, Student &v);
		//inputs a student

	friend ostream & operator <<(ostream &s, const Student &v);
		//outputs a student
 
	public:
		
		Student();
			//constructs an empty student
		
		Student(char v);
			//constructs a name using the character passed int 

		bool operator ==(const Student &v) const;
			//returns true if students are equal
		
		bool operator <(const Student &v) const;
			//returns true if left op is less than right op
		
		bool operator !=(const Student &v) const;
			//returns true if they aren't equal

	private:

		enum {maxName = 100};
		int id;
		char name[maxName];
		int numGrades;
		Bstring *grades;	
};

#endif
