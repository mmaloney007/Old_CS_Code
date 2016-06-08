//Victor Maloney CS 416 Assignment 8

/*this class is not overly fancy.  it has a constructor, destructor and
the copy and assignment ops are not implemented.  it has an output
operator and the operators to add dvds to both the inventory or a shopping
cart.  it uses readvalue.h in one function.*/

#include <iostream.h>
#include "ShopC.h"
#include "DVD.h"

//constructs an empty shopping cart

ShopC::ShopC()
{
	store = 0;
}

//destructor for shopping cart

ShopC::~ShopC()
{
	Vid *p;

	while(store != 0){
		p = store;
		store = store -> next;
		delete p;
	}
	delete store;
}

//used with readValue operation to store inventory for dvds

void ShopC::addDVD(const DVD &v)
{
	Vid *p;
	
	p = new Vid;
	p -> movie = v;
	p -> next = store;
	store = p;
}

//searches the inventory to make sure that the DVD is in stock and then adds it
//to the selected shopping cart.  If DVD is not in stock then an error
//messsage is printed to tell you what is not in stock

void ShopC::add(ShopC &v, int id)
{
	Vid *p;
	
	p = new Vid;
	p = v.store;
	
	while(p != 0 && (p -> movie) != id)
		p = p -> next;

	if (p != 0){
		(*this).addDVD(p -> movie);
		cout << "   adding " << p -> movie;
	}

	else
		cout << "no DVD with id number [" << id << "]\n";
}

//prints the contents of the shopping cart including the total

void ShopC::print()
{
	Vid *p;
	float total = 0;

	p = store;
	cout << "cart contents\n";

	while(p != 0){
		cout << p -> movie;
		total = total + (p -> movie).getPrice();
		p = p -> next;
	}

	cout << "\ntotal = " << total << '\n';
}
