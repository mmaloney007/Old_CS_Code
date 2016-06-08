//Victor Maloney CS 515 Assignment 3

/*
This is the source code for a weight balanced binary search tree.  It
should basically work about the same as a binary serach tree but it should
more efficent.  
*/

#include <iostream.h>
#include <stdlib.h>
#include "BST.h"

//constructor

Bst::Bst()
{
	t = NULL;
}

//destructor

Bst::~Bst()
{
	destruct(t);
}

//inserts a node into the tree

bool Bst::insert(int key)
{
	return ins(&t, key);
}

//deletes a node from the tree

bool Bst::deleteIt(int key)
{
	return del(&t, key);
}

//returns the height of the tree

int Bst::height()
{
	return ht(t);
}

//prints the tree in pre order

void Bst::preOrder()
{
	pre(t);
}

//prints the tree in in order

void Bst::inOrder()
{
	in(t);
}

//returns the average depth of the tree

float Bst::aveDepth()
{
	int tot = 0;
	int dep = 0;
	return float(depth(t, tot, dep)) / float(total(t));
} 

//inserts a node into the tree

bool Bst::ins(tnode **t, int key)
{
	bool success;
	success = TRUE;
	if((*t) == NULL)
	{
		(*t) = new tnode;
		(*t) -> k = key;
		(*t) -> left = NULL;
		(*t) -> right = NULL;
		(*t) -> w = 1;
		success = TRUE;
	}

	else { 
		if(key < (*t) -> k)
			ins(&(*t) -> left, key);
		if(key > (*t) -> k)
			ins(&(*t) -> right, key);
		if(key == (*t) -> k) 
			return FALSE;
	(*t) -> w = ((*t) -> w) + 1;
	}

	if(success == TRUE)
	{
	if((*t) -> left && (*t) -> left -> left)
	{ 
		if((*t) -> left -> left -> w && (*t) -> right == NULL) 
			rotateRight(t);
		else if(((*t) -> left -> left -> w) > ((*t) -> right -> w))
			rotateRight(t);
	}

	if((*t) -> left && (*t) -> left -> right)
	{
		if((*t) -> left -> right -> w && (*t) -> right == NULL)
			doubleRight(t);
		else if(((*t) -> left -> right -> w) > ((*t) -> right -> w))
			doubleRight(t);
	}

	if((*t) -> right && (*t) -> right -> left)
	{
		if((*t) -> right -> left -> w && (*t) -> left == NULL)
			doubleLeft(t);
		else if(((*t) -> right -> left -> w) > ((*t) -> left -> w))
			doubleLeft(t);
	}

	if((*t) -> right && (*t) -> right -> right)
	{
		if((*t) -> right -> right -> w && (*t) -> left == NULL)
			rotateLeft(t);
		else if(((*t) -> right -> right -> w) > ((*t) -> left -> w))
			rotateLeft(t);
	}
	}
	return success;
}

//deletes a node from the tree

bool Bst::del(tnode **t, int key)
{
	int maxkey;
	tnode *tmp;
	if (t == NULL)
		return false;

	if (key < (*t) -> k)
		del(&(*t) -> left, key); 
	if (key > (*t) -> k) 
		del(&(*t) -> right, key);
	if (key == (*t) -> k){
		tmp = *t;
	if((*t) -> left == NULL){
		(*t) = (*t) -> right;
		delete tmp;
		return true;
		}
	if((*t) -> right == NULL){
		(*t) = (*t) -> left;
		delete tmp;
		return true;
		}
	else {
		maxkey = findMax((*t) -> left);
		(*t) -> k = maxkey;
		del(&(*t) -> left, maxkey);
	     }
	}
	
		if((*t) -> left && (*t) -> left -> left)
		{ 
			if((*t) -> left -> left -> w && (*t) -> right == NULL) 
			rotateRight(t);
		else if(((*t) -> left -> left -> w) > ((*t) -> right -> w))
			rotateRight(t);
		}

		if((*t) -> left && (*t) -> left -> right)
		{
		if((*t) -> left -> right -> w && (*t) -> right == NULL)
			doubleRight(t);
		else if(((*t) -> left -> right -> w) > ((*t) -> right -> w))
			doubleRight(t);
		}

		if((*t) -> right && (*t) -> right -> left)
		{
		if((*t) -> right -> left -> w && (*t) -> left == NULL)
			doubleLeft(t);
		else if(((*t) -> right -> left -> w) > ((*t) -> left -> w))
			doubleLeft(t);
		}

		if((*t) -> right && (*t) -> right -> right)
		{
		if((*t) -> right -> right -> w && (*t) -> left == NULL)
			rotateLeft(t);
		else if(((*t) -> right -> right -> w) > ((*t) -> left -> w))
			rotateLeft(t);
		}
}

//returns the height of the tree

int Bst::ht(tnode *t)
{
	if(t == NULL)
		return 0;
	else 
		return 1 + max(ht(t -> left), ht(t -> right));
}

//prints the tree in pre-order

void Bst::pre(tnode *t)
{
	if(t != NULL){
		cout << t -> k << " ";
		pre(t -> left);
		pre(t -> right);
	}
}

//prints the tree in-order

void Bst::in(tnode *t)
{
	if(t != NULL){
		in(t -> left);
		cout << t -> k << " ";
		in(t -> right);
	}
}

//returns the max of two ints

int Bst::max(int a, int b)
{
	if(a >= b)
		return a;
	else 
		return b;
}

//returns the max key in the tree

int Bst::findMax(tnode *t)
{
	tnode *tmp;
		tmp = t;
		int max; 
	while(tmp -> right != 0)
		tmp = tmp -> right;
	max = tmp -> k;

	return max;
}

//destructs the tree

void Bst::destruct(tnode *t)
{
	if(t == NULL)
		{}
	else {
		destruct(t -> left);
		destruct(t -> right);
		delete(t);
	}
}

//returns the depth of the tree

int Bst::depth(tnode *t, int tot, int dep)
{
	dep++;

	if(t)
		tot = dep + tot + depth(t -> left, tot, dep) + depth(t -> right, tot, dep);

	return tot;
}

//returns the total number of nodes in the tree

int Bst::total(tnode *t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + total(t -> left) + total(t -> right);
}

//rotates the tree to the right about t

void Bst::rotateRight(tnode **t)
{
	tnode *tmp1;
	tnode *tmp2;
	tnode *tmp3;

	tmp1 = (*t);
	tmp2 = (*t) -> left;
	tmp3 = (*t) -> left -> right;

	(*t) = tmp2;
	tmp1 -> left = tmp3;
	(*t) -> right = tmp1;

	if((*t) -> right -> left == NULL){
		if((*t) -> right -> right == NULL)
		(*t) -> right -> w = 1;
	else
		(*t) -> right -> w = 1 + (*t) -> right -> right -> w;
	}

	else if((*t) -> right -> right == NULL){
		if((*t) -> right -> left == NULL)
		(*t) -> right -> w = 1;
	else
		(*t) -> right -> w = 1 + (*t) -> right -> left -> w;
	}

	else {
		((*t) -> right -> w) = 1 + ((*t) -> right -> left -> w) + 
		((*t) -> right -> right -> w);
	}

	((*t) -> w) = 1 + ((*t) -> left -> w) + ((*t) -> right -> w);
}

//rotates the tree to the left about t

void Bst::rotateLeft(tnode **t)
{
	tnode *tmp1;
	tnode *tmp2;
	tnode *tmp3;

	tmp1 = (*t);
	tmp2 = (*t) -> right;
	tmp3 = (*t) -> right -> left;

	(*t) = tmp2;
	tmp1 -> right = tmp3;
	(*t) -> left = tmp1;

	if((*t) -> left -> right == NULL){
		if((*t) -> left -> left == NULL)
			(*t) -> left -> w = 1;
		else
			(*t) -> left -> w = 1 + (*t) -> left -> left -> w;
	}

	else if((*t) -> left -> left == NULL){
		if((*t) -> left -> right == NULL)
			(*t) -> left -> w = 1;
		else
			(*t) -> left -> w = 1 + (*t) -> left -> right -> w;
	}

	else {
		((*t) -> left -> w) = 1 + ((*t) -> left -> right -> w) + 
		((*t) -> left -> left -> w);
	}

	((*t) -> w) = 1 + ((*t) -> right -> w) + ((*t) -> left -> w);
}

//double rotates the tree about t

void Bst::doubleRight(tnode **t)
{
	tnode *tmp;
	tnode *tmp1;
	tnode *tmp2;
	tnode *tmp3;

	tmp = (*t) -> left;
	tmp1 = tmp;
	tmp2 = tmp -> right;
	tmp3 = tmp -> right -> left;

	tmp = tmp2;
	tmp -> left = tmp1;
	tmp -> left -> right = tmp3;
	(*t) -> left = tmp;

	if(tmp -> left -> left == NULL){
		if(tmp -> left -> right == NULL)
		tmp -> left -> w = 1;
		else
		tmp -> left -> w = 1 + tmp -> left -> right -> w;
	}

	else if(tmp -> left -> right == NULL){
		if(tmp -> left -> left == NULL)
			tmp -> left -> w = 1;
		else
			tmp -> left -> w = 1 + tmp -> left -> left -> w; 
	}

	if(tmp -> right == NULL)
		tmp -> w = 1 + tmp -> left -> w;
	else
		(tmp -> w) = 1 + (tmp -> right -> w) + (tmp -> left -> w);

	rotateRight(t);
}

//double rotates the tree about t

void Bst::doubleLeft(tnode **t)
{
	tnode *tmp;
	tnode *tmp1;
	tnode *tmp2;
	tnode *tmp3;

	tmp = (*t) -> right;
	tmp1 = tmp;
	tmp2 = tmp -> left;
	tmp3 = tmp -> left -> right;

	tmp = tmp2;
	tmp -> right = tmp1;
	tmp -> right -> left = tmp3;
	(*t) -> right = tmp;

	if(tmp -> right -> left == NULL){
	if(tmp -> right -> right == NULL)
	tmp -> right -> w = 1;
	else
	tmp -> right -> w = 1 + tmp -> right -> right -> w;
	}

	if(tmp -> left == NULL)
	tmp -> w = 1 + tmp -> right -> w;
	else
	(tmp -> w) = 1 + (tmp -> right  -> w) + (tmp -> left -> w);

	rotateLeft(t);
}
