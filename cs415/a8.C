//victor maloney assignment 8 cs415 section 1
/*this number accepts a character argument and returns a number if the characteris between a or f either lower or upper case*/
int ad2num(char ch)
{
    if (('a' <= ch) && (ch <= 'f'))
    return ch - 'a' + 10;
    if (('A' <= ch) && (ch <= 'F'))
    return ch - 'A' + 10;
    else
    return -1;
}
/*this function builds a number with the first number being the hundreds digit  the last digit being the hundreds digit*/
float buildNum(char ch1,char ch2,char ch3,char ch4)
{
    return ((ch1 - '0') * 100) + ((ch2 - '0') * 10) + (ch3 - '0') + ((ch4 - '0') / 10.0);
}
/*this function raises the number 2 to a power of N with N being the number you give to it*/
float twoN(int num)
{
    if (num > 0)
    return 2 * twoN(num - 1);
    else if (num < 0)
    return twoN(num + 1) / 2;
    else
    return 1;
}
/*this function returns the average of the two integer arguments given in non
descending order*/
float ave(int a,int b)
{
    if (a == b)
    return a;
    else if ( (a + 1) == b)
    return a + 0.5;
    else
    return ave(a + 1,b - 1);
}
/*the function returns the greatest common denominator of two numbers when you  enter two integers that are non-negative*/
int gcd(int a,int b)
{
    if (a > b)
    return gcd(a - b, b);
    else if (b > a)
    return gcd(a, b - a);
    else
    return a;
}
 
