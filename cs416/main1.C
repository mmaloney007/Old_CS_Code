#include <iostream.h>
#include <matrix.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i;
	int j;
	int n;
	int sum;
	int m = 0;
	int mult = 0;
	int N = .1;

	float A[101][101];
	float X[101];
	float b[101];
	float Xo[101];

	//Make the matrices
	for(i=1;i < 102; i++)
	{
		A[i][i] = -2;
	}
	for(i = 1; i < 100; i++)
	{
		A[i][i+1] = 1;
		A[i+1][i] = 1;
	}
	for(i=1;i < 102; i++)
	{
		b[i] = (sin((i*M_PI/101)) + cos((i*M_PI)/101));
	}
	for(i=0;i < 101;i++)
	{
		X[i] = 0;
	}

	while ( (N > (10^-9)) &	(m<1000) )
	{
		for(i=0;i<102;i++)
		{
			Xo[i] = X[i];
		}
		for(i = 1;i<102;i++)
		{
			sum = b[i];
			for(j=1;j<102;j++)
			{
				if((j!=i) && (Xo[j] != 0) & (A[i][j] != 0))
				{
					sum = sum - (A[i][j] * Xo[j]);	
					mult++;
				}
			}
			X[i] = sum / A[i][i];
			mult++;
		}
		m++;
		N = 1;
	} 
	
	for(i=1; i< 102; i++)
	{
	cout << "This is X[" << i << "]= " << X[i] << "\n";
	}  

	return 0;
}
