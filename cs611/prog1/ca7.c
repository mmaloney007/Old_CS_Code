//Victor Maloney CS 611 Assignment #1

/*
	This program should compress a stream of ascii character by simply
removing the 8th bit from any ascii character.  It will then output the bits 
8 at a time therefore compressing the file.
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
			test = (c & 0x80);
			if(test == 0x80)
			{
				fprintf(stderr,"Byte error at %d", byteoffset);
			}

			for(x = 0; x < 7; x++)
			{
				tmp = ((c >> x) & 0x01);
				tmp = (tmp << y);
				cot = (tmp | cot); 
				y++;
				tmp = 0x00;

				if(y >= 8)
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
		putchar(cot);
	}
	
	return 0;
}
