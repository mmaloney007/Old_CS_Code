#ifndef COURSE_H
#define COURSE_H

/* this class defines a course for the registration of
	classes.  Each course has a coures number, the maximum
	seating capacity, and the current enrollment. */

#include <iostream.h>

class Course {
	friend istream& operator >>(istream &s, Course &v);
		//inputs course as course number, max enrollment
		//and current enrollment

	friend ostream& operator <<(ostream &s, const Course &v);
		//outputs course - number, max enrollment, current

	public:
		Course();
			//inits all fields to 0

		Course(int courseNumber);
			//inits course to have given course number, other
			//members 0

		void addStudent();
			//adds student to course.  The capacity is NOT
			//checked - so it is possible to over-enroll
			//a course

		bool hasSeat() const;
			//returns true if course has a seat available

		bool operator == (const Course &v) const;
			//returns true if course numbers are the same

		bool operator != (const Course &v) const;
			//returns true if course numbers are NOT the same


	private:
		int number;
		int maxEnrollment;
		int currentEnrollment;
};

		
#endif
