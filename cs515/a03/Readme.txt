				External Documentation 
			Victor Maloney Cs 515 Assignment 3

	This assignemt was to create a weight balanced tree. The defintion of
weight balancing is that a grandchild should not weight more than a child.  We
were supposed to impliment the following operations:

Insert(key) - Should insert a key into the tree and return false if it is 
already there.  Then rebalance on the way out.
Delete(key) - Should delete a key in the tree and aslo return false if the key
is not there.  Then rebalance after that.
Height() - Should give the largest height of the tree.
PreOrder() - Print the keys in pre-order.
InOrder() - Print the keys in order.

All of these were to be written recursively.  The private of the class should
also look like this:

	struct tnode{
	int k; //the key
	int w; //stores the weight of the node
	tnode *left;
	tnode *right;
	};
	tnode *t;

This weight balanced tree should be more efficent than a regular unbalanced
tree as it will never become a straight linked list as a unbalanced tree
would become in the cases of inserting the nodes 1 through 500 would in my
test harness.  The balanced tree will always be close to the optimal height
that a tree should be for speed. If you inserted the nodes one through five
hundred into a unbalanced tree it could take 500 accesses to find the node
with the key of 500.  In a balanced tree it would take up to 10 accesses at
the most.  This is why a balanced tree is better.

I also constructed this test harness which should addaquately test all the 
cases that could come up to rotate the tree.


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

This is the output from my test harness:

Height of random tree:
10
Average Height Random Tree: 
8.11134

Height is: 
9
Average Depth: 
7.99197

As you can see on the case of the random nodes my tree comes very close to the 
optimal height even after deleting the root node and some random node in the 
middle of the tree.
In the cases of inserting the nodes 1 through 500 the tree actually is the 
optimal height.  Therefore I conclude that the class works.
