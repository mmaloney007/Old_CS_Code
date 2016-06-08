//Victor Maloney CS 611 Assignment #1

/*
	This program should uncompress a stream of ascii character by simply
adding a zero in for the 8th bit.  It is the counter part to the program ca7
which removes the 8th bit.
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int x = 0;
	int y = 0;
	int byteoffset = 0;
	char c;
	char cot = 0x00;
	char tmp = 0x00;
	char test = 0x00;

	c = getc(stdin);
	
		while(c != EOF)
		{
			for(x = 0; x < 8; x++)
			{
				tmp = ((c >> x) & 0x01);
				tmp = (tmp << y);
				cot = (tmp | cot); 
				y++;
				if(y >= 7)
				{
					putchar(cot);
					cot = 0x00;
					y = 0;
				}	
			}
		c = getc(stdin);
		byteoffset++;
		}

	if(y != 0)
	{
		if(c & test != 0x00)
		{
			fprintf(stderr,"Byte error at %d",byteoffset);
		}
	}
	
	return 0;
}
