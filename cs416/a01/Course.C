//victor maloney cs 416 assignment 1

//---------------------------------------------------------

//this program helps someone in administration keep track
//of which courses are filled which have been registered
//by people and which students have regestered for a course

//---------------------------------------------------------

#include "Course.h"

	istream& operator >>(istream &s, Course &v)
		{
		s >> v.number >> v.maxEnrollment >> v.currentEnrollment;
		return s;
		}

	ostream& operator <<(ostream &s, const Course &v)
		{
		s << v.number << '\t' << v.maxEnrollment << '\t';
		s << v.currentEnrollment << '\n';
		return s;
		}

	Course::Course()
	{
		number = 0;
		maxEnrollment = 0;
		currentEnrollment = 0;
	}

	Course::Course(int courseNumber)
	{
		number = courseNumber;
		maxEnrollment = 0;
		currentEnrollment = 0;
	}
	
	void Course::addStudent()
	{
		currentEnrollment++;
	}
	
	bool Course::hasSeat() const
	{
	return currentEnrollment < maxEnrollment;
	}
	
	bool Course::operator == (const Course &v) const
	{
	return number == v.number;
	}

	bool Course::operator != (const Course &v) const
	{
	return number != v.number;
	}
