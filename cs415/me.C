/*victor maloney 003-64-7871 cs 415 sect. 1 assignment 4*/
/*this function tests to see that a given number is within the range of the 
second and third number given*/
bool inRange(float n1,float n2,float n3)
{
    return (n2 <= n1) && (n1 <= n3);
}
/*this tells you if two numbers are in assending order*/
bool inOrder(float c1, float c2)
{
    return c1 <= c2;
}
/*this function tells you if both numbers are positive*/
bool bothPositive(float x1, float x2)
{
    return x1 > 0 && x2 > 0;
}
/*this function will return true if either one or both of it's arguments given
are negative*/
bool oneNegative(int z1,int z2)
{
    return z1 < 0 || z2 < 0;
}
/*this function tells you if the number you enter is a two digit number*/
bool twoDigitNumber(int p1)
{
    return (10 <= p1) && (p1 < 100);
}
