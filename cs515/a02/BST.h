//Victor Maloney CS515 Assignment 2

/*
	this is the header file for the binary search tree.  it has a
	constructor destructor insert delete average depth, height, 
	and many private helper functions.  all are written recusursively
	as requested.
	it's data members are a struct named tnode with a left and right
	pointer and a key named k to identify the node.  it also has 
	a tnode pointer which is the root of the tree.
*/

#ifndef BST_H
#define BST_H

#include <iostream.h>
#include <stdlib.h>

class BST {

	public:

		BST();
		//creates a tree

		~BST();
		//destroys a tree

		bool insert(int key);
		//adds a key to the tree

		bool deleteit(int key);
		//deletes a key from the tree

		int height();
		//returns the height of the tree

		void preorder();
		//prints the tree in pre-order

		void inorder();
		//prints the tree in-order

		float averagedepth();
		//returns the average depth of the tree

		int max(int a, int b);
		//a simple max function for two ints


	private:

	//Private data members

		struct tnode{
			int k;
			tnode *left;
			tnode *right;
		};
		tnode *t;

	//Private functions

	bool ins(tnode **t, int key);
		//Private insert
	bool del(tnode **t, int key);
		//private delete function
	int findmax(tnode *t);
		//private findmax function
	void preo(tnode *t);
		//preorder helper
	void ino(tnode *t);
		//inorder helper
	int ht(tnode *t);
		//height helper
	void deletenode(tnode *t);
		//destructor helper
	int depth(tnode *t, int ttl, int dp);
		//average depth helper adds all depths together
	int totalnodes(tnode *t);
		//adds all the total nodes
};

#endif  
