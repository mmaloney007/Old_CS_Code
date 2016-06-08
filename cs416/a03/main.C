//Victor M. Maloney CS 416 Assignment III

/*This is the main part of the program that makes an array (4 
demensional array).  It also outputs only the part of the array that
has payments due.*/

#include <iostream.h>
#include "Apart.h"

int main()
{
	//the constant identifiers fo the array vic
	const int c = 5;
	const int b = 4;
	const int f = 10;
	const int a = 20;
	
	Apart vic[c][b][f][a];
	
	int complex;
	int build;
	int floor; 
	int apartnum;
	char ch;
	float num;
	int i;
	int j; 
	int k; 
	int l;
	
	//while loop that inputs usage from a information file

	while(cin >> complex >> build >> floor >> apartnum){
		cin >> ch >> num;
		vic[complex-1][build-1][floor-1][apartnum-1].add(ch, num);
	}
	cout << "\n\n";
	
	//embedded for loop that outputs only appartments that used utilities

	for(i=0; i<c; i++)
	
		for(j=0; j<b; j++)
		
			for(k=0; k<f; k++)
			
				for(l=0; l<a; l++) 		
				
					if(vic[i][j][k][l] != 0){
						cout << "apartment " << i+1
							<<"-"<<j+1<<"-"<<k+1
							<<"-"<<l+1<<'\n';
						cout << vic[i][j][k][l];
					}
	return 0;
}
