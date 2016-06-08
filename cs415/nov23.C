// victor maloney assignment 14
/* this program takes in money ammount and manipulates them as a cash register
would taking the total and making change.*/
#include <iostream.h>
#include "Money.h"
//------------------------------------------------
int main()
{
    Money total;
    Money paid;
    Money cash;
    int ammount;
    cout << "enter quantity/unit cost pairs, end with quanity of 0" << '\n';
    cout << "?>";
    cin >> ammount;
    while(ammount > 0){
    cash.input();
    cash.times(ammount);
    total.add(cash.times(ammount));
    cout << "   purchase ammount = ";
    (cash.times(ammount)).output();
    cout << '\n' << '\n' << "?> ";
    cin >> ammount;
    }
    cout << '\n' <<"total of purchase is ";
    total.output();
    cout << "\n" << "\n" << "enter ammount paid ?> ";
    paid.input();
    total.lessThan(paid);
    total.minus(paid);
    return 0;
}
