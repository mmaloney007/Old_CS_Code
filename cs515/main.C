//Victor Maloney CS 515 Assignment 5

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
	int to;
	int i;
	Stack s;

	for(to = 0; to < 10; to++)
	{
		i = rand();
		cout << i << ' ';
		s.push(i);
	}

	cout << '\n';
	while(!(s.empty()))
	{
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
	
	return 0;
}
