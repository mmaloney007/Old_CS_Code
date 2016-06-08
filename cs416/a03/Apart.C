//Victor M. Maloney Assignment III CS 416
/*This part of the program is the class that will keep track of 
the natural gas, h20, electric, and computer usage.  This also has
an output operator that puts the said object in proper out form.*/

#include <iostream.h>
#include "Apart.h"

//object intiallizer
Apart::Apart()
{
	_natgas = 0;
	_h20 = 0;
	_elc = 0;
	_cmp = 0;
}

//output operator for the object (built in operations for payment)
ostream& operator <<(ostream &s, const Apart &v)
{
	s << "  usage -- gas = " << v._natgas << " / water = " << v._h20;
	s << " / electricity = " << v._elc << " / computer = ";
	s << v._cmp << "\n  charge -- "; 
	s << v._natgas * 2 + v._h20 * 5 + v._elc * 3 + v._cmp / 5.0 << "\n\n";
	return s;
} 

//boolean operator so that i can output only objects with stuff in them
bool Apart::operator !=(int c) const
{
	return _natgas != c || _h20 != c || _elc != c || _cmp != c;
}

//boolean operator
bool Apart::operator >(int c) const
{
	return _natgas > c || _h20 > c || _elc > c || _cmp > c;
}

//boolean operator
bool Apart::operator <(int c) const
{
	return _natgas < c || _h20 < c || _elc < c || _cmp < c;
}

//function that adds the approrate num to the right object
void Apart::add(char Apart, float num)
{
	if(Apart == 'g')
		_natgas += num;
	if(Apart == 'w')
		_h20 += num;
	if(Apart == 'e')
		_elc += num;
	if(Apart == 'c')
		_cmp += num;
}
