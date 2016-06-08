//Victor Maloney CS 515 Assignment 3

#ifndef BST_H
#define BST_H

/* this class is for a balanced binary search tree.  It's operations include, a
constructor, insert, delete, height, preOrder, inOreder and aveDepth. */

#include <iostream.h>
#include <stdlib.h>

class Bst {

	public:
		Bst();
			//constructor

		~Bst();
			//destructor

		bool insert(int key);
			//inserts a node into the tree

		bool deleteIt(int key);
			//deletes a node from the tree

		int height();
			//returns the height of the tree

		void preOrder();
			//prints the tree in pre order form

		void inOrder();
			//prints the tree in in order form

		float aveDepth();
			//returns the average depth of the tree

	private:

		struct tnode {
		tnode *left;
		tnode *right;
		int k;
		int w;
		};
		tnode *t;

	//----------------Private Functions-----------------------------
		bool ins(tnode **t, int key);
			//inserts a node into the tree
		bool del(tnode **t, int key);
			//deletes a node from the tree
		int ht(tnode *t);
			//returns the height of the tree
		void pre(tnode *t);
			//prints the tree in pre order
		void in(tnode *t);
			//prints the tree in in-order
		int max(int a, int b);
			//returns the max of the two ints
		int findMax(tnode *t);
			//returns the max key in the tree
		void destruct(tnode *t);
			//destructs the tree
		int depth(tnode *t, int total, int d);
			//returns the depth of the tree
		int total(tnode *t);
			//returns the total number of nodes in the tree 
		void rotateRight(tnode **t);
			//rotates the tree to the right about t
		void doubleRight(tnode **t);
			//double rotates the tree to the right about t
		void doubleLeft(tnode **t);
			//double rotates the tree to the left about t
		void rotateLeft(tnode **t);
			//rotates the tree to the left about t
};
#endif
