//Victor Maloney CS 416 Assignment # 13

/* this is a student class that takes the id of a student (an int), a name
that can be 100 letters long and a number of grades and then stores them
in an array of Bstrings.  it is relatively simlpe and to end a name use a
':' or it will keep taking in the names. */

#include <iostream.h>
#include "Student.h"
#include <string.h>
#include "Bstring.h"

//makes an empty student

Student::Student()
{
	id = 0;
	name[0] = '\0';
	numGrades = 0;
}

//makes a name with the char put into it

Student::Student(char v)
{
	id = 0;
	name[0] = v;
	name[1] = '\0';
	numGrades = 0;
}

//return true if student are the sme

bool Student::operator ==(const Student &v) const
{
	if(strcmp(name, v.name) == 0 && id == v.id)
	return true;
	else
	return false;
}

//returns true if the two are not equal

bool Student::operator !=(const Student &v) const
{
	if(strcmp(name, v.name) == 0 && v.id)
	return false;
	else
	return true;
}

//return true if lerft operand is less than right

bool Student::operator <(const Student &v) const
{
	if(strcmp(name, v.name) < 0)
	return true;
	else if(strcmp(name, v.name) == 0 && id < v.id)
	return true;
	else 
	return false;
}

//inputs a student

istream& operator>>(istream &s, Student &v)
{
	Bstring grade;
	int i = 0;
	int j = 0;
	char ch;

	if (s>>v.id){

	s.get(ch);
	while(ch != ':'){
		v.name[i++] = ch;
		s.get(ch);
		}
	v.name[i++] = ch;
	v.name[i] = '\0';

	s >> v.numGrades;

	v.grades = new Bstring[v.numGrades + 1];
	while(j < v.numGrades){
		s >> grade;
		v.grades[j++] = grade;
		}
	}
	return s;
}

//puts a student out

ostream& operator<<(ostream &s, const Student &v)
{
	int i = 0;
	s << v.id << " " << v.name << " " << v.numGrades << " ";
	while(i < v.numGrades){
	s << v.grades[i] << " ";
	i++;
	}
	s << '\n';
	return s;
}
