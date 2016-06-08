#ifndef CLASS_H
#define CLASS_H

#include <iostream.h>

/*this class names Class keeps track of studentid, courses, and 
credits for people that are inputed and outputed :: a note that 
it has a charge function added */

class Class {
	friend istream& operator >>(istream &s, Class &v);

	
	friend ostream& operator <<(ostream &s, const Class &v);


	public:
		Class();
		
		void add(int c);
	
		void drop(int c);
		
		void charge();
	
		bool operator !=(int d) const;
			 
		bool operator <(const Class &v) const;
			
		bool operator <(int d) const;
			
		
	private:
		int _studentid;
		int _courses;
		int _cred;
};
#endif
