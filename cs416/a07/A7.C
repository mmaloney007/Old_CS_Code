/* test harness to test matrix and twodarray classes.
	The first input value is a character, either a or m which
	determines which test (array or matrix) is run.

	The matrix test inputs two matricies - first specifying the 
	number of rows of and columns of the matrix and then its
	values (row by row) and then outputs these matricies and
	their product (in the order input).

	The array test inputs an array - first specifying the
	number of rows and columns, followed by the elements
	row by row, and then a sequence of subscript pairs to
	access (eof terminated) - the contents of the elements
	are printed.  Finally, the entire array is printed twice,
	row by row.
*/

#include <iostream.h>
#include "TwoDArray.h"
#include "Matrix.h"

// constants used

	const char matrix = 'm';
	const char array = 'a';

// functions used

	void array_test();
	void matrix_test();
	Matrix calcproduct(Matrix,Matrix);
	TwoDArray inputarray();
	void outputarray(TwoDArray);
	void elemtest(TwoDArray);

int main()
{
	char test;

	cout << "which test (" << array << " or " << matrix << ") ?> ";
	do {
		cin >> test;

		if (test != array && test != matrix)
			cout << "must enter either " << array << " or " << matrix 
			<< " ?> ";
	} while (test != array && test != matrix);

	switch (test) {
		case array:
			array_test();
			break;

		case matrix:
			matrix_test();
			break;
	}

	cerr << "normal termination\n";
	return 0;
}

//------------------------------------------------------------
/* this procedure performs the array test */

void array_test()
{
	cerr << "arraytest: after entry\n";
	TwoDArray answer(0,0);
	TwoDArray tmp;

	cerr << "arraytest: before empty array assignment\n";
	tmp = answer;
	answer = tmp;
	cerr << "arraytest: after empty array assignment\n";

	cerr << "arraytest: before input\n";
	answer = inputarray();
	cerr << "arraytest: after input input\n";

	cerr << "arraytest: before block entry\n";
	{
	cerr << "arraytest: block entry\n";
	TwoDArray two(5,10);
	cerr << "arraytest: after block vars\n";
	answer = answer;
	two = answer;
	answer = two;
	cerr << "arraytest: before block exit\n";
	}
	cerr << "arraytest: after block exit\n";

	cerr << "arraytest: before output\n";
	outputarray(answer);
	cerr << "arraytest: after output\n";

	
	cerr << "arraytest: before element test\n";
	elemtest(answer);
	cerr << "arraytest: after element test\n";

	{
	TwoDArray three(10,100);
	int i,j;

	for (i=0; i< 10; i++)
		for (j=0; j<100; j++)
			three.elem(i,j) = i*j;
	}

	cerr << "arraytest: before second output\n";
	outputarray(answer);
	cerr << "arraytest: after second output\n";

	cerr << "arraytest: returning\n";
}

//------------------------------------------------------------
/* this procedure performs the matrix test */

void matrix_test()
{
	cerr << "entering matrix test\n";
	Matrix answer;


	int rows1, cols1;
	cerr << "rows and columns for left matrix ?> ";
	cin >> rows1 >> cols1;
	Matrix mat1(rows1, cols1);

	cerr << "enter left matrix with " << rows1 << " rows and " << cols1 <<
		" columns\n";
	cin >> mat1;

	cerr << "\nleft matrix is\n";
	cerr << mat1;


	int rows2, cols2;
	cerr << "rows and columns for right matrix ?> ";
	cin >> rows2 >> cols2;
	Matrix mat2(rows2, cols2);

	cerr << "enter right matrix with " << rows2 << " rows and " << cols2 <<
		" columns\n";
	cin >> mat2;

	cerr << "\nright matrix is\n";
	cerr << mat2;
	
	cerr << "start first assignment tests\n";
	mat1 = mat1;
	mat2 = mat2;
	answer = mat1;
	answer = mat2;
	cerr << "end first assignment tests\n";

	cerr << "start block tests\n";
	{
		Matrix tmp;
		tmp = mat1;
		mat1 = tmp;
		tmp = mat2;
		mat2 = tmp;
		tmp = answer;
		answer = tmp;
	}
	cerr << "end block tests\n";

	cerr << "beginning matrix multiplication\n";

	answer = calcproduct(mat1, mat2);

	cerr << "the result matrix is\n";
	cerr << answer;

	cerr << "before zero element tests\n";
	{
	Matrix x;
	Matrix y;
	Matrix z;
	z = x * y;
	cin >> x;
	cout << z;
	cout << x;
	cout << y;
	}
	cerr << "after zero element tests\n";

	cerr << "product of\n";
	cerr << mat1;
	cerr << "and\n";
	cerr << mat2;
	cerr << "is\n";
	cerr << answer;

	cerr << "returning from matrix test\n";
}

//------------------------------------------------------------
/* calculates produce of two matrices */

Matrix calcproduct(Matrix a, Matrix b)
{
	cerr << "calcproduct: after entry\n";
	Matrix ans;
	
	ans = a * b;

	cerr << "calcproduct: before exit\n";
	return ans;
}

//------------------------------------------------------------
/* inputs two d array */

TwoDArray inputarray()
{
	cerr << "inputarray: after entry\n";
	int i, j;
	int rows, cols;
	TwoDArray ans(2,2);
	cerr << "inputarray: after definitions\n";

	cerr << "enter number of rows and columns ?> ";
	cin >> rows >> cols;

	ans = TwoDArray(rows, cols);
	cerr << "inputarray: after explicit constructor\n";

	cerr << "enter elements for " << ans.rows() << " by " << ans.cols() <<
		" array - row by row\n";

	for (i=0; i<ans.rows(); i++) {
		cerr << "row " << i << " ?> ";
		for (j=0; j<ans.cols(); j++)
			cin >> ans.elem(i,j);
	}

	cerr << "inputarray: returning\n";
	return ans;
}

//------------------------------------------------------------
/* outputs array */

void outputarray(TwoDArray arr)
{
	cerr << "outputarray: after entry\n";
	int i,j;

	cerr << "output of " << arr.rows() << " by " << arr.cols() << " array\n";

	for (i=0; i<arr.rows(); i++) {
		for (j=0; j<arr.cols(); j++)
			cerr << arr.elem(i,j) << '\t';
		cerr << '\n';
	}
	cerr << "outputarray: returning\n";
}

//------------------------------------------------------------
/* element test - enter row col pairs, end with eof */

void elemtest(TwoDArray arr)
{
	int i,j;

	cerr << "enter subscripts for " << arr.rows() << " by " << arr.cols()
		<< " array\n";
	cerr << "terminate with eof\n";

	cerr << "row col ?> ";
	while (cin >> i >> j) {
		cerr << "  value = " << arr.elem(i,j) << '\n';;
		cerr << "row col ?> ";
	}
	cerr << "exiting element test\n";
}
