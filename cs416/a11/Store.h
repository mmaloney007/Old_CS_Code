//Victor Maloney CS 416 Assignment # 11

#ifndef STORE_H
#define STORE_H

/* this class keeps track of the contents of an electronics store.  Each object
has a model number, quantity, price, company and description.  It has 
relational operators, a few unique ones and input and output
operators. the data members are an int, a couple of c-strings, and a
float for good measure.*/

#include <iostream.h>

class Store {

	friend istream& operator >>(istream &s, Store &v);
		//inputs an object of the store

	friend ostream& operator <<(ostream &s, const Store &v);
		//outputs an object of the store

	public:
		Store();
			//constructs an empty store object

		Store(char m[]);
			//constructs an object with the model number

		Store(char m[], int q);
			//constructs an object with model and new quantity

		bool operator !=(const Store &v) const;
			//returns true if the objects model #'s aren't equal

		bool operator <(const Store &v) const;
			//returns true if left op is less than right op

		bool operator ==(const Store &v) const;
			//returns true if both objects are equal

		void combine(const Store &v);
			//fills in empty fields of left op with right op

	private:
	
		enum{maxModel = 20, maxCo = 100, maxDes = 200};
		char model[maxModel];
		int quantity;
		float price;
		char company[maxCo];	
		char des[maxDes];
};

#endif
