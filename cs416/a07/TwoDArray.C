//Victor M. Maloney CS 416 assignment 7

/* this class defines a dynamically allocated two dimensional array of
	floats.  The memory for the array is allocated at construction time,
	based on the size specified.  The array is stored in row major order.

	Once allocated, it is possible to determine the number of rows and
	the number of columns using the "rows" and "cols" operations.  

	Elements are accessed in a similar way to normal subscripting, using
	the "elem" operation. If "arr" were a TwoDArray, then the syntax
	"arr.elem(i,j)" would be equivalent to the notation "a[i][j]" for a
	normal two dimensional C++ array, and can be used in the same 
	contexts.  Subscript bounds are checked, and bounds violations will
	cause the program to abort. 

	Unlike standard C++ arrays, these arrays act like normal values.
	They may be passed using any of the C++ argument passing mechanisms,
	and may be returned as function values.  One TwoDArray may be assigned
	the contents of another.  The arrays do not have to be the same size
	for assignment - the left hand operand will take on the size of the
	right hand operand.
*/

#include <iostream.h>
#include <stdlib.h>
#include "TwoDArray.h"

// constructs a no element array.  This array is only
// useful on left of assignment or to define an array
// of 2D arrays.

TwoDArray::TwoDArray()
{
	numRows = 0;
	numCols = 0;
	numElem = 0;
	store = new float[numElem];
}

// Constructs a two dimensional array in row major 
// order with the number of rows and columns specified.
// Negative values for the number of rows and/or columns 
// will cause the program to abort.  A 0 value for either
// will cause a no element array to be constructed.  Such
// an array is valid, but is only useful on the left of an
// assignment.

TwoDArray::TwoDArray(int numrows, int numcols)
{
	int i;
	numRows = numrows;
	numCols = numcols;
	numElem = numrows * numcols;
	store = new float[numElem];
	for(i = 0; i < numElem; i++)
		store[i] = 0; 
}

//copy constructor

TwoDArray::TwoDArray(const TwoDArray &arr):
	numRows(arr.numRows),
	numCols(arr.numCols),
	numElem(arr.numElem)
{
	int i;
	
	store = new float[numElem];
	
	for(i=0; i < numElem; i++)
		store = arr.store;
}

//destructor

TwoDArray::~TwoDArray()
{
	delete []store;
}

//assignment operator

TwoDArray& TwoDArray::operator =(const TwoDArray &arr)
{
int i;

	if(this != &arr){
		delete []store;
		
		numRows = arr.numRows;
		numCols = arr.numCols;
		numElem = arr.numElem;
		
		store = new float[numElem];
		
		for(i=0; i<numElem; i++)
			store = arr.store;
	}
	
	return *this;
}

// equivalent of subscripting operator.
// Returns actual element from array so it may be 
// modified by application program
// subscript bounds ARE checked - the program will
// ABORT on subscript error.

float& TwoDArray::elem(int rownum, int colnum)
{
	if (numRows-1 < rownum || numCols-1 < colnum){
		cerr << "incorrect row or column\n";
		exit(1);
	}

	else
		return store[subscript(rownum, colnum)];
}

// equivalent of subscripting operator.
// Returns contents of element from array.  No modification
// of the actual element is allowed.
// subscript bounds ARE checked - the program will
// ABORT on subscript error.

float TwoDArray::elem(int rownum, int colnum) const
{
	if (numRows-1 < rownum || numCols-1 < colnum){
		cerr << "incorrect row or column\n";
		exit(1);
	}

	else
		return store[subscript(rownum, colnum)];
}

//returns the number of rows in an array

int TwoDArray::rows() const
{
	return numRows;
}

//returns the number of columns in an array

int TwoDArray::cols() const
{
	return numCols;
}

// converts two dimensional subscript into corresponding
// one dimensional subscript into the implementation
// array

int TwoDArray::subscript(int row, int col) const
{
	return (row - 1) * numCols + (col - 1);
}
