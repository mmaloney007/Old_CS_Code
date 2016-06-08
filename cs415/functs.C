/*A function that will return the intrest given a average monthly balance
and a certain annual rate*/
float interest(float balance, float annualRate)
{
    return balance * annualRate/12/100.0; 
}
/*A function that will return the volume of a box given the three
side measurements*/
float volume(float v1,float v2,float v3)
{
    return v1*v2*v3;
}
/*A function that will return the least significant digit of a non
negative integer argument*/
int lsd(int v1)
{
    return v1%10;
}
/*A function that return only the fraction part of it's non-negative argument*/
float fractionalPart(float v1)
{
    return v1-int(v1);
}
/* A function that returns the of volume of a sphere by taking the argument, 
namely the radius, cubing it and multiplying it by four thirds and then by
pie*/
float volume(float radius)
{
    return (4.0/3.0) * 3.14159 * (radius * radius * radius); 
}
