//Vic M. Maloney CS 416 Assignment 3

/*This header file defines a class that keeps track utility usage in 
complexes*/

#ifndef APART_H
#define APART_H

#include <iostream.h>


class Apart {
	friend ostream& operator <<(ostream &s, const Apart &v);
		
	public:
		Apart();		
			
		bool operator !=(int c) const;
		
		bool operator <(int c) const;

		bool operator >(int c) const;
	
		void add(char apart, float num);
	
	private:
		float _natgas;
		float _elc;
		float _cmp;
		float _h20;
};

#endif
