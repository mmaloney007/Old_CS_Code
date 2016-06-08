//Victor Maloney assignment II 

#include <iostream.h>
#include "Class.h"

/* this class defines objects with id number, number of courses and 
number of credits. it also contains a charge function*/

//initalizes a class with three things
Class::Class()
{
	_studentid = 0;
	_courses = 0;
	_cred = 0;
}

//adds credits to a students record
void Class::add(int c)
{
	_cred += c;
	_courses++;
}

//drops credits from a students records
void Class::drop(int c)
{
	_cred -= c;
	_courses--;
}

//a procedure to keep track of charges
void Class::charge()
{
	if(_cred < 12)
		cout << (150 * _cred) + (15 * _courses);
	if(_cred >= 12 && _cred <= 18)
		cout << 2200 + (15 * _courses);
	if(_cred > 18)
		cout << 2200 + (15 * _courses) + (100 * (_cred - 18));
}

//boolean operator
bool Class::operator !=(int d) const
{
	return _studentid != d;
}

//another boolean operator
bool Class::operator <(const Class &v) const
{
	return _studentid < v._studentid;
}

//and another one
bool Class::operator <(int d) const
{
	return _studentid < d;
}

//input operator
istream& operator >>(istream &s, Class &v)
{
	s >> v._studentid >> v._courses >> v._cred;
	return s;
}

//output operator
ostream& operator <<(ostream &s, const Class &v)
{
	s << v._studentid << "  " << v._courses << "  " << v._cred;
	return s;
}
