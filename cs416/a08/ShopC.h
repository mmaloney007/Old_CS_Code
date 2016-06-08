//Victor Maloney CS 416 Assignment 8

/*this class is what makes the program look fancy.  it adds dvds to the
inventory or to the shopping cart.  it checks to make sure the dvd is in
the inventory and also has a print function that outputs what is in your
shopping cart and a total of how much you have spent.  the copy
constructor and assignment operator are not implemented.*/

#ifndef SHOPC_H
#define SHOPC_H

#include <iostream.h>
#include "DVD.h"

class ShopC {

	public:

		ShopC();
			//constructs an empty cart

		~ShopC();
			//destructor

		void addDVD(const DVD &v);
			//used with readValue operation to store inventory

		void add(ShopC &v, int id);
			//searches the inventory to make sure that the DVD is
			//in stock and then adds it to cart.  If DVD is not
			//in stock then an error message is printed

		void print();
			//prints the contents of the cart

	private:

		struct Vid {
			DVD movie;
			Vid *next;
		};
		
		Vid *store;

		ShopC& operator =(const ShopC &);
			//assignment operator - not implemented
		ShopC(const ShopC &);
			//copy constructor - not implemented
};

#endif
