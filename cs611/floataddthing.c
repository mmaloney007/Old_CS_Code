#include <stdio.h>

int main()
{
	int d = 0x000000;
	float a = 0x457fc000;
	float b = 0x407fffff;
	float c = 0;
	c = b + a;
	
	d = *((int*)&c);

	printf("\n");
	printf("%x",d);
	printf("\n");

	return 0;
}
