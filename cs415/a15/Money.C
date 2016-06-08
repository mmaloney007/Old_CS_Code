//vic maloney assignment 14
/*this file creates a class to deal with the money problem*/
#include "Money.h"
#include <iostream.h>
//-----------------------------------------
//constructs a money value with dollars and cents
Money::Money()
{
    dollars = 0;
    cents = 00;
}
//takes in a dollar ammount for the money
void Money::input()
{
    char sign;
    char dot;
    cin >> sign >> dollars >> dot >> cents; 
}
//adds money to the total ammount helping to keep track of the money total
void Money::add(Money cash)
{
    dollars += cash.dollars;
    cents += cash.cents;
    if (cents >= 100){
    dollars++;
    cents = cents - 100;
    } 
}
//multiplies the money ammount entered by the quantity and makes a new money
//ammount
Money Money::times(int ammount) const
{
    Money total;
    while(ammount > 0){
        if(total.cents >= 100){
        total.dollars = total.dollars + 1;
        total.cents = total.cents - 100;
        }
    total.dollars = total.dollars + dollars;
    total.cents = total.cents + cents;
    ammount = ammount - 1;
    }
    if(total.cents >= 100){
    total.dollars = total.dollars + 1;
    total.cents = total.cents - 100;
    } 
    return total;
}
//this returns a money value by taking the total and subtracting the ammount
//passed
Money Money::minus(Money paid) const
{
    Money total;
    if (dollars < paid.dollars && cents <= paid.cents || dollars == 
paid.dollars && cents < paid.cents){
    total.cents = paid.cents - cents;
    total.dollars = paid.dollars - dollars;
    cout << "change is ";
    total.output();
    cout << '\n';
    }
        else if (dollars < paid.dollars && cents > paid.cents){
        paid.cents = paid.cents + 100;
        paid.dollars = paid.dollars - 1;
        total.dollars = paid.dollars - dollars;
        total.cents = paid.cents - cents;
        cout << "change is ";
        total.output();
        cout << '\n';
        }
            else if (dollars == paid.dollars && cents == paid.cents)
            cout << "change is " << "$0.00" << '\n';
                else {
                total.dollars = dollars - paid.dollars;
                total.cents = cents - paid.cents;
                cout << "not enough - please pay ";
                total.output();
                cout << " more" << '\n';
                } 
}
//figures out if you paid enough money or not then gives you your change
//or asks for more money
bool Money::lessThan(Money paid) const
{
    if (paid.dollars >= dollars || paid.dollars == dollars && paid.cents >=
 cents){
    return paid.dollars - dollars;
    return paid.cents - cents;
    }
    else {
    return dollars - paid.dollars;
    return cents - paid.cents;
    }
}
//outputs a figure of money that you ask
void Money::output() const 
{
    if (cents < 10)
    cout << "$" << dollars << "." << "0" << cents;
    else
    cout << '$' << dollars << '.' << cents;
}
