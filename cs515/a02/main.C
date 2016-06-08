//Victor Maloney Cs 515 Assignment 2

/*
	This is simply a test harness for a binary search tree class.
	It inserts five hundred nodes and outputs the average depth and 
	the height of the tree.
	It has one for loop and that is it.
*/

#include <iostream.h>
#include <stdlib.h>
#include "BST.h"

int main()
{
	//two ints and a tree
	BST tree;
	int i;
	int time;

	cout << "Order Inserted in: \n";
	//test loop inserts 12 nodes into the tree
	for(time = 0; time < 12; time++)
	{
		i = rand()%10000;
		tree.insert(i);
		cout << i << ' ';
	}

	//This simply tests the outputs for the tree
	cout << '\n';
	cout << "\nPreorder Output \n";
	tree.preorder();
	cout << "\n\n";
	cout << "Inorder Output \n";
	tree.inorder();
	cout << "\n\n";

	//Tests the classes deleteing capabilites
	cout << "Deleting " << i << ": \n";
	tree.deleteit(i);
	cout << "\nPreorder Output \n";
	tree.preorder();
	cout << "\n\n";
	cout << "Inorder Output \n";
	tree.inorder();
	cout << "\n\n";
	
	//finishes inserting 488 more nodes to test average depth and 
	//height
	for(time = 12; time < 500; time++)
	{
		i = (rand()%10000);
		tree.insert(i);
	}

	//outputs the trees height and average depth as asked
	cout << "Height is: \n";
	cout << tree.height();
	cout << '\n';
	cout << "\nAverage Depth is: \n";
	cout << tree.averagedepth();
	cout << "\n\n";

	return 0;
}
