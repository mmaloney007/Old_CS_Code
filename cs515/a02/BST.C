//Victor Maloney CS515 Assignment 2

/*
	this is the code files for a binary search tree.  it has insert
	delete, a constructor, destructor, height, average height, and 
	many private helper functions so that it is easy.  All functions
	are written recursively.
*/

#include <iostream.h>
#include <stdlib.h>
#include "BST.h"

//Constructs a null bst tree

BST::BST()
{
	t = NULL;
}

//Inserts a key

bool BST::insert(int key)
{
	return ins(&t, key);
}

//Prints in-order

void BST::preorder()
{
	preo(t);
}	

//Prints in-order

void BST::inorder()
{
	ino(t);
}

//Private insert

bool BST::ins(tnode **t, int key)
{
	if (*t == NULL)
	{
	(*t) = new tnode;
	(*t) -> k = key;
	(*t) -> left = NULL;
	(*t) -> right = NULL;
	}
	else
	{
		if (key < (*t)->k)
		{
		ins(&(*t)->left,key);
		}
		if (key > (*t)->k)
		ins(&(*t)->right,key);
		}
	} 

//deletes a key from the tree

bool BST::deleteit(int key)
{
	bool test;
	test = del(&t, key);
	if(test == TRUE)
	return TRUE;
	else
	return FALSE;
}

bool BST::del(tnode **t, int key)
{
	tnode *tmp;
	int maxkey;
	
	if(t == NULL)
	return FALSE;
	if(key < (*t)->k)
	del(&(*t)->left, key);
	if(key > (*t) -> k)
	del(&(*t)->right, key);
	if(key == (*t) -> k) 
	{
		tmp = (*t);
		if((*t)->left == NULL)
		{
			(*t) = (*t) -> right;
			delete tmp;
			return true;
		}
		else if((*t)->right == NULL)
		{
			(*t) = (*t) -> left;
			delete tmp;
			return true;
		}
		else
		{
		maxkey = findmax(*t);
		(*t) -> k = maxkey;
		del(&(*t) -> left, maxkey);
		return true;
		}
	}
}

//maxkey function

int BST::findmax(tnode *t)
{
	int max;
	tnode *tmp;
	tmp = t -> left;
	max = (tmp -> k);
	while((tmp) -> right)
	{
		max = (tmp) -> k;
		tmp = tmp -> right;
	}
	return max;	
}

//inorder helper

void BST::ino(tnode *t)
{
	if(t != NULL)
	{
	ino(t -> left);
	cout << t -> k << ' ';
	ino(t -> right);
	}
	else
	cout << " * ";
}

//preorder helper

void BST::preo(tnode *t)
{
	if(t != NULL)
	{
	cout << t -> k << ' ';
	preo(t -> left);
	preo(t -> right);
	}
	else
	cout << " * ";
}

//destructor

BST::~BST()
{
	deletenode(t);
}

//destructor helper deletenode

void BST::deletenode(tnode *t)
{
	if(t != NULL)
	{
		deletenode(t -> left);
		deletenode(t -> right);
		delete(t);
	}
}
//height

int BST::height()
{
	return ht(t);
}

//heigt helper

int BST::ht(tnode *t)
{
	if(t == NULL)
	return 0;
	else
	return 1 + max(ht(t -> left), ht(t -> right));
}

//max function

int BST::max(int a, int b)
{
	if(a > b)
	return a;
	else
	return b;
}

//average depth function returns a float that is the average depth

float BST::averagedepth()
{
	int total = 0;
	int deep = 0;
	return (float(depth(t, total, deep)) / totalnodes(t));
}

//average depth helper totalnode adds all the nodes up

int BST::totalnodes(tnode *t)
{
	if(t != NULL)
	return 1 + totalnodes(t -> left) + totalnodes(t -> right);
	else
	return 0;
}

//average depth helper totals all depths

int BST::depth(tnode *t, int ttl, int dp)
{
	dp++;
	if(t)
	{
	ttl = dp + depth(t -> left, ttl, dp) + depth(t -> right, ttl, dp) + ttl;
	}
	return ttl;
}
