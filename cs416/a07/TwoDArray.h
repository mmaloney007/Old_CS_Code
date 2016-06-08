#ifndef TWODARRAY_H
#define TWODARRAY_H

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

class TwoDArray {
	public:

		TwoDArray();
			// constructs a no element array.  This array is only
			// useful on left of assignment or to define an array
			// of 2D arrays.

		TwoDArray(int numrows, int numcols);
			// Constructs a two dimensional array in row major
			// order with the number of rows and columns specified.
			// Negative values for the number of rows and/or columns 
			// will cause the program to abort.  A 0 value for either
			// will cause a no element array to be constructed.  Such
			// an array is valid, but is only useful on the left of an
			// assignment.

		TwoDArray(const TwoDArray &arr);
			//copy constructor

		~TwoDArray();
			//destructor

		TwoDArray& operator =(const TwoDArray &arr);
			//assignment operator

		float& elem(int rownum, int colnum);
			// equivalent of subscripting operator.
			// Returns actual element from array so it may be 
			// modified by application program
			// subscript bounds ARE checked - the program will
			// ABORT on subscript error.

		float elem(int rownum, int colnum) const;
			// equivalent of subscripting operator.
			// Returns contents of element from array.  No modification
			// of the actual element is allowed.
			// subscript bounds ARE checked - the program will
			// ABORT on subscript error.

		int rows() const;
			//returns number of rows in array

		int cols() const;
			//returns number of columns in array

	private:

		int numRows; //number of rows in array
		int numCols; //number of columns in array
		int numElem; //number of elements in array

		float *store; //dynamically allocated one dimensional array
					  //containing numElem elements.

		int subscript(int row, int col) const;
			// converts two dimensional subscript into corresponding
			// one dimensional subscript into the implementation
			// array
		
};

#endif
