/*This function given a yearly intrest rate will return a monthly intrest
rate that is in decimal form so it is easy to calulate with*/
float monthlyRate(float annual)
{
    return annual / 12 / 100;
}
/*This function given the principal left and the intrest rate in calculable
monthly form will give you the ammount of intrest due that month*/
float interest(float balance, float monthly)
{
    return balance * monthly;
}
/*This function give the arguments in order of payment, balance of loan, and 
intrest rate will give you the ammount of money that will come off of the
principal that month*/
float principle(float pay, float balance, float intr)
{
    return pay - (balance * intr / 12 / 100);
}
/*This function returns a new balance of the principal given a monthly
payment, balance of the loan, and a intrest rate given as a percent*/
float newBalance(float pay, float balance, float intr)
{
    return balance - principle(pay, balance, intr);
}
/*This function given a aregument that is a non-negative intrerger will return
the thousands digit*/
int thousandsDigit(int num)
{
    return num / 1000 % 10;
}

