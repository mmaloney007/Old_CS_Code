//Victor Maloney CS 611 Assignment 2

/*
this function will emulate IEEE floating point addition.  It will take in
two operands and add the two together.  it does this by first extrating the 
right amount of bits for the signifigand, the exponet, and the sign bit.
it then puts in the hidden one.  adds the two numbers (or subtracts them if
sign bits do not agree) and normalizes it.  it rounds the final number then
checks to normalize again.  it does this all for 64 bit numbers.  and only
uses integer operations.
*/

long DoubleAdd(long op1, long op2)
{
	//initalize variables
	long difference = 0x0000000000000000; //this is the difference between exponents
	long exponent1 = 0x0000000000000000; //exponent for op1
	long exponent2 = 0x0000000000000000; //exponent for op2
	long signif1 = 0x00000000000000000; //mantesa for op1
	long signif2 = 0x00000000000000000; //mantesa for op2
	long sign1 = 0x0000000000000000; //sign of op1
	long sign2 = 0x0000000000000000; //sign of op2
	long counter = 0x0000000000000000; //helps for normalizing
	long plusorminus = 0x0000000000000000; //helps in sign of final 
	long greater = 0x0000000000000000; //helps in normalizing
	long i = 0x0000000000000000; //helps in adding or subtracting for op1
	long j = 0x0000000000000000; //helps in adding or subtracting for op2
	long k = 0x0000000000000000; //ends up being final mantesa
	long answer = 0x0000000000000000; //the answer
	long guardbits = 0x0000000000000000; //helps the guardbits keeps track of them
	long sbits = 0x0000000000000000; //helps the stickybit
	long tempholder = 0x0000000000000000; //just a simple temporary holder

//extractions for exponents and signs

	signif1 = (op1 & 0x000FFFFFFFFFFFFF) | 0x0010000000000000;
	signif2 = (op2 & 0x000FFFFFFFFFFFFF) | 0x0010000000000000;
	exponent1 = (op1 >> 52) & 0x00000000000007FF;
	exponent2 = (op2 >> 52) & 0x00000000000007FF;
	sign1 = (op1 >> 63) & 0x0000000000000001;
	sign2 = (op2 >> 63) & 0x0000000000000001;

//The actual heart of the program.  This tests to see how gets
//subtracted or added to who and does some rounding.

	if(exponent1 > exponent2)
	{
		difference = exponent1 - exponent2;
		i = signif1;
		j = signif2 >> difference;
		tempholder = signif2;
		if(difference > 1)
		{
			guardbits = ((signif2 >> (difference - 2)) & 0x0000000000000003);
		}
		else
		{
			guardbits = ((signif2 << difference) & 0x0000000000000003);
		}

		if((tempholder & ((0xfffffffffffff) >> (54-difference))) == 0x0000000000000000)
		{
			sbits = 0;
		}
		else
		{
			sbits = 1;
		}	
		greater = exponent1;
		plusorminus = sign1;
		if(sign1 == sign2)
		{
			k = i + j;
		}
		else 
		{
			k = i - j;
		}
	}

	else if(exponent2 > exponent1)
	{
		difference = exponent2 - exponent1;
		i = signif1 >> difference;
		j = signif2;
		tempholder = signif1;
		if(difference > 1)
		{
			guardbits = ((signif1 >> (difference - 2)) & 0x0000000000000003);
		}
		else
		{
			guardbits = ((signif2 << difference) &0x3);
		}
		if(((tempholder & ((0xfffffffffffff) >> (54-difference))) > 0))
		{
			sbits = 1;
		}
		else
		{
			sbits = 0;
		}
		greater = exponent2;
		plusorminus = sign2;
		if(sign1 == sign2)
		{
			k = i + j;
		}
		else 
		{
			k = j - i;
		}
	}

	else if(exponent1 == exponent2)
	{
		i = signif1;
		j = signif2;
		greater = exponent1;
		if(sign1 == sign2)
		{
			k = i + j;
			plusorminus = sign1;
		}
		else 
		{
			if(signif1 > signif2)
			{
				k = i - j;
				plusorminus = sign1;
			}
			else if(signif2 > signif1)
			{
				k = j - i;
				plusorminus = sign2;
			}
			else if(signif1 == signif2)
			{
				return 0x0000000000000000;
			}
		}
	}

//Should take care of rounding...

	if(guardbits == 0x0000000000000002)
	{
		if(sbits == 0x0000000000000001)
		{
			k = k + 1;
		}
		else
		{
			if((k & 0x0000000000000001) == 0x0000000000000001)
			{
				k = k + 1;
			}
		}
	}
	else 
	{
		if(guardbits == 0x3)
		{
			k = k + 1;
		}
	}

//checks the number to make sure it is okay...

	if((k & 0x0020000000000000) == 0x0020000000000000)
	{
		greater++;
		k = k >> 1;
	} 
	else
	{
		while(counter != 52 && ((k & (0x0010000000000000)) != (0x0010000000000000)))
		{
		k = k << 1;
		greater--;
		counter++;
		} 
	}

		k = (k & 0x000fffffffffffff);

//Puts the number back together...

	plusorminus = (plusorminus << 63);
	greater = (greater << 52);
	answer = (greater | (k | plusorminus));

//test special cases

	if(op1 == 0x7ff0000000000000)
	{
		if(op2 == 0xfff0000000000000)
		{
			return 0xfff8000000000000;
		}
		else if(signif2 != 0x0010000000000000) 
		{
			return answer;
		}
		else
		{
			return 0x7ff0000000000000;
		}
	}	

	if(op1 == 0xfff0000000000000)
	{
		if(op2 == 0x7ff0000000000000)
		{
			return 0xfff8000000000000;
		}
		else if(signif1 != 0x0010000000000000)
		{
			return op1;
		}
		else
		{
			return 0xfff0000000000000;
		}
	}

	if(op2 == 0x7ff0000000000000)
	{
		if(op1 == 0xfff0000000000000)
		{
			return 0xfff8000000000000;
		}
		else if(signif2 != 0)
		{
			return op2;
		}
		else
		{
			return 0x7ff0000000000000;
		}
	}

	if(op2 == 0xfff0000000000000)
	{
		if(op1 == 0x7ff0000000000000)
		{
			return 0xfff8000000000000;
		}
		else if(signif2 != 0)
		{
			return answer;
		}
		else
		{
			return 0xfff0000000000000;
		}
	}

//if it is not a special case and does not prompt early exit

	return answer;
}
