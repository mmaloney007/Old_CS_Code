#ifndef INVENTORY_H
#define INVENTORY_H

/* this class describes an inventory for a used book store.
	it allows the inventory to be added to, books removed,
	and the inventory checked - both by author and for a
	specific book
*/

#include <iostream.h>
#include "Book.h"

class Inventory {

	friend ostream& operator <<(ostream &s, const Inventory &v);
		// outputs inventory, books and counts

	public:
		Inventory();
			//constructs empty inventory

		void add(const Book &book);
			//adds specified book to inventory

		void subtract(const Book &book);
			//removes specified book from inventory

		bool find(const Book &book) const;
			//returns true if book found in inventory

	private:
		enum {maxBooks=1000};
		int numBooks;
		Book books[maxBooks];
		int counts[maxBooks];

		bool find(const Book &book, int &index) const;
};

#endif
