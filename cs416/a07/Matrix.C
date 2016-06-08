//Victor M. Maloney CS 416 Assignment 7

/* this class defines a matrix, which is a two dimensional array
	with special properties.  Matrices can be read and output
	and multiplied.
*/

#include <iostream.h>
#include "Matrix.h"
#include "TwoDArray.h"

//constructs no element matrix - only useful on
//left of assignment operator, although input and
//output operators and multiplication operator
//will operate correctly (essentially doing nothing)
//with them.

Matrix::Matrix()
{
	matrix;
}

//constructs maxtrix with specified number of rows
//and columns.  number of rows and columns must be
//non-negative or program will abort.  A no element
//matrix is not very useful, although input, output,
//and multiplication operators will work correctly
//with such a matrix.

Matrix::Matrix(int rows, int cols)
{
	int i;
	int j;
	TwoDArray tmp(rows, cols);
	matrix = tmp;
	for(i=0; i < rows; i++)
		for(j=0; j < cols; j++)
			matrix.elem(i,j) = 0;
}

//multiplies two matrices.  if matricies are not
//compatible program will abort.
//multiplying matrices with 0 elements, when compatible
//will return an array with 0 elements.


Matrix Matrix::operator *(const Matrix &mat)
{
	int i;
	int j;
	int k;
	Matrix ans(matrix.rows(), mat.matrix.cols());

	if (matrix.cols() == mat.matrix.rows()){
		for (i=0; i<matrix.rows(); i++)
			
	for (j=0; j<(mat.matrix.cols()); j++){
				for (k=0; k<matrix.cols(); k++)
					(ans.matrix.elem(i,j)) =
ans.matrix.elem(i,j) + (matrix.elem(i,k)* mat.matrix.elem(k,j));
	}
	return ans;
	}
	
	else {
		cerr << "not able to multiply matrices";
		exit(1);
	}
}

//inputs maxtix row by row - number of values
//input is based on size of matrix
//does nothing if 0 element matrix.

istream& operator >>(istream &s, Matrix &obj)
{
	int i,j;
	for (i=0; i<obj.matrix.rows(); i++)
		for (j=0; j<obj.matrix.cols(); j++)
			s >> obj.matrix.elem(i,j);
	return s;
}

//outputs matrix row by row, one row per line
//individual elements output are tab separated
//does nothing if 0 element matrix.

ostream& operator <<(ostream &s, const Matrix &obj)
{
	int i, j;

	for (i=0; i<obj.matrix.rows(); i++){
		for (j=0; j<obj.matrix.cols(); j++)
			cout << obj.matrix.elem(i,j) << '\t';
		cout << '\n';
	}
	
	return s;
}
