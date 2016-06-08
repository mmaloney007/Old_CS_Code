//vic maloney assignment 9 cs 415 section 1
/*this funtion gives the qountient of the first argument divided by the second
argument*/
int quotient(int a,int b)
{
    if (a - b >= b)
    return 1 + quotient(a - b, b);
    else if (b > a) 
    return 0;
    else
    return 1;
}
/*this funtion returns the remainder of the first number divided by the second
number*/
int remainder(int a,int b)
{
    if (a - b >= 0)
    return remainder((a - b),b);
    else if (b > a) 
    return a;
    else 
    return 0;
}
/*this funtion tells you how many digits are in the number you have entered*/
int numDigits(int a)
{
    if (a >= 10)
    return 1 + numDigits(a / 10);
    else
    return 1;
}
/*this function returns the sum of the digits of a given integer argument*/
int sumDigits(int num)
{
    if (num >= 10)
    return (num % 10) + sumDigits(num / 10);
    else 
    return num;
}
/*nthDigit returns the digit from a number which is entered with zero being 
the least signifigant digit. first enter the number of the digit you wish to
know and then enter the number to find it in*/
int nthDigit(int a,int b)
{
    if (a > 0)
    return nthDigit(a - 1,b / 10);
    else 
    return b % 10;
}

