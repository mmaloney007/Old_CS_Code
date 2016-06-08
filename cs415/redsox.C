// vic maloney assingment 5 10-15-99
/*this first function determins if there is a monthly charge of $5.50 on your
checking account given a single real argument*/
float monthlyCharge(float bal)
{
    return bal < 500 ? 5.5 : 0;
}
/*this function returns a employees weekly pay by taking the first argument
as the weekly hours and the second argument as the hourly wage.  if greater
than forty hours the extra hours are given time and a half*/
float weeklyPay(float hour,float pay)
{
    return hour > 40 ? 40 * pay + (hour - 40) * (pay * 1.5) : pay * hour;
}
/*this function determines the final cost of a purchase given it's cost
if the cost is great than $150 10% is taken off, lower than $150 and greater
than $50 5% is taken off and less than $50 none is subtracted*/
float finalCost(float cost)
{
    return cost > 150 ? cost - cost * .1 : cost > 50 ? cost - cost * .05 : cost;}
/*this function returns the combined cost of two items purchased with a second
of equal or lesser value for 50% off*/
float combinedCost(float item1,float item2)
{
    return item1 >= item2 ? item1 + item2 / 2 : item2 + item1 / 2;
}
/*this function returns the difference between two interger arguments given*/
int difference(int one,int two)
{
    return one - two >= 0 ? one - two : (one - two) * -1;
}
