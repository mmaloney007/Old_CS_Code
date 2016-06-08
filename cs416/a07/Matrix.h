#ifndef MATRIX_H
#define MATRIX_H

/* this class defines a matrix, which is a two dimensional array
	with special properties.  Matrices can be read and output
	and multiplied.
*/

#include <iostream.h>
#include "TwoDArray.h"

class Matrix {
	friend istream& operator >>(istream &s, Matrix &obj);	
		//inputs maxtix row by row - number of values
		//input is based on size of matrix
		//does nothing if 0 element matrix.

	friend ostream& operator <<(ostream &s, const Matrix &obj);	
		//outputs matrix row by row, one row per line
		//individual elements output are tab separated
		//does nothing if 0 element matrix.

	public:
		Matrix();
			//constructs no element matrix - only useful on
			//left of assignment operator, although input and
			//output operators and multiplication operator
			//will operate correctly (essentially doing nothing)
			//with them.

		Matrix(int rows, int cols);
			//constructs maxtrix with specified number of rows
			//and columns.  number of rows and columns must be
			//non-negative or program will abort.  A no element
			//matrix is not very useful, although input, output,
			//and multiplication operators will work correctly
			//with such a matrix.

		Matrix operator *(const Matrix &mat);
			//multiplies two matrices.  if matricies are not
			//compatible program will abort.
			//multiplying matrices with 0 elements, when compatible
			//will return an array with 0 elements.
		
	private:
		
		TwoDArray matrix;
};

#endif
