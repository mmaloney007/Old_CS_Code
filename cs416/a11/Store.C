//Victor Maloney CS 416 Assignment # 11

/* this class keeps track of the contents of an electronics store.  Each object
has a model number, quantity, price, company and description.  It has 
relational operators, a few unique ones and input and output
operators. it uses strings and intergers as storage devices */

#include <iostream.h>
#include <string.h>
#include "Store.h"
#include "List.h"

//constructs an empty store object

Store::Store()
{
	model[0] = '\0';
	quantity = 0;
	price = 0;
	company[0] = '\0';
	des[0] = '\0';
}

//constructs an object with the model number

Store::Store(char m[])
{
	strcpy(model, m);
	quantity = 0;
	price = 0;
	company[0] = '\0';
	des[0] = '\0';
}

//constructs an object with model # and new quantity

Store::Store(char m[], int q)
{
	strcpy(model, m);
	quantity = q;
	price = 0;
	company[0] = '\0';
	des[0] = '\0';
}

//returns true if the objects model #'s aren't equal

bool Store::operator !=(const Store &v) const
{
	if(strcmp(model, v.model) == 0)
		return false;
	else 
		return true;
}

//returns true if left op is less than right op

bool Store::operator <(const Store &v) const
{
	if(strcmp(model, v.model) < 0)
		return true;
	else
		return false;
}

//returns true if the objects are equal

bool Store::operator ==(const Store &v) const
{
	return strcmp(model, v.model) == 0;
}

//fills in the empty fields of left op with right op, for replace

void Store::combine(const Store &v) 
{
	if (quantity > 0)
		quantity = quantity + v.quantity;

	if(quantity <= 0){
		if (quantity + v.quantity < 0)
			throw List::NoStock();
		else
			quantity = quantity + v.quantity;
	}

	if(price == 0)
		price = v.price;
	if(company[0] == '\0')
		strcpy(company, v.company);
	if(des[0] == '\0')
		strcpy(des, v.des);
	
}

//inputs an object of the store

istream& operator >>(istream &s, Store &v)
{
	char ch;
	int i = 0;

	s >> v.model >> v.quantity >> v.price;
	
	s.get(ch);
	while(ch != ';'){
		v.company[i++] = ch;
		s.get(ch);
	}
	v.company[i++] = ch;
	v.company[i] = '\0';	
	s.get(v.des, Store::maxDes);	
	return s;
}

//outputs an object of the store

ostream& operator <<(ostream &s, const Store &v)
{
	s << v.model << "  " << v.quantity << "  " << v.price << " " << 
v.company << "  " << v.des << '\n';
	return s;
} 
