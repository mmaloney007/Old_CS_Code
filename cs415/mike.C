// assignment 6 vic maloney cs 415 section 1
#include <math.h>
/*this function tells you how many roots you will have given the coefficents
of a quadratic function*/
int howManyRoots(float a,float b,float c)
{
    const float quad = ((b * b) - (4 * a * c));
    if (quad < 0)
    return 0;
    else 
       if (quad == 0)
       return 1;
       else 
       return 2;
}
/*this function will give you the root of the quadratic expression of either a
subtracted root or a added root (enter 1 for additon and 2 for subraction)*/
float root(int posorneg,float a,float b,float c)
{
    if (posorneg == 1)
    return (-b + sqrt((b * b) - 4 * a * c)) / (2 * a);
    else
    return (-b - sqrt((b * b) - 4 * a * c)) / (2 * a);
} 
/*this tells you if the quadratic equation has real roots or not given the tree real coefficents*/
bool hasRoots(float a,float b,float c)
{
    const float quad = (b * b) - (4 * a * c);
    if (quad >= 0)
    return 1;
    else 
    return 0;
}
/*this function rounds any real number to the integer of the next biggest
magnitude on the case it is .5 or bigger*/
int round(float num)
{
    if (num >= 0)
    return int(num + 0.5);
    else
    return int(num - 0.5);
}
/*this function will return you the least signifigant digit (an integer)
of the whole number*/
int lswd(float digit)
{
    const int numb = (int(digit) % 10);
    if (numb >= 0)
    return numb;
    else
    return numb * -1;
}
