//Victor Maloney Cs 515 Assignment 3

/*
	This is simply a test harness for a weight balanced 
	binary search tree class.
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
	Bst tree1;
	Bst tree;
	int i;
	int time;
	int del;
	int del2;

	//test loop inserts 500 random nodes into the tree
	for(time = 1; time < 500; time++)
	{
		i = rand();
		tree.insert(i);
		if(time == 1)
		{
			del2 = i;
		}
		if(time == 250)
		{
			del = i;
		}
	}

	//Numbers geting delted
	tree.deleteIt(del2);
	tree.deleteIt(del);

	//outputs the random tree's average depth and height

	cout << '\n';
	cout << "Height of random tree:\n";
	cout << tree.height();
	cout << "\nAverage Height Random Tree: \n";
	cout << tree.aveDepth();
	cout << "\n\n";
	
	//inserts 1 - 500 in order
	for(time = 1; time < 501; time++)
	{
		i = time;
		tree1.insert(i);
		if(time == 251)
		{
			del = i;
		}	
	}
	
	//Numbers to get deleted and test delete
	tree1.deleteIt(1);
	tree1.deleteIt(del);
	
	//outputs the trees height and average depth as asked
	cout << "Height is: \n";
	cout << tree1.height();
	cout << '\n';
	cout << "Average Depth: \n";
	cout << tree1.aveDepth();
	cout << "\n";

	return 0;
}
