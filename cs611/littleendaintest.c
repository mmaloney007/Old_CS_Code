//Little Endian test

int main()
{
	int i = 0x00000001;
	
	char p;

	p = *((char*)&i);

	if((p) == 0x01)
	{
		printf("\nMachine is little endian\n");
	}
	else
	{
		printf("\nMachine is big endian\n");
	}
	return 0;
}
