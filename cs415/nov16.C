//Victor Maloney Assignment 13
#include <iostream.h>
#include "Vehicle.h"
int main()
{
    char ch;
    int am;
    Vehicle car;
/*--------------------------------*/
    cout << "enter actions, end with 'q'" << '\n' << "?>";
    cin >> ch ;
    while(ch != 'q'){
    cin >> am;
    if(ch == 's'){
    car.setSpeed(am);
    car.getSpeed();
    cout << "  speed is " << car.getSpeed() << '\n';
    }
    else if(ch == 'a'){
    car.accelerate(am);
    car.getSpeed();
    cout << "  speed is " << car.getSpeed() << '\n';
    } 
    else if(ch == 'd'){
    car.decelerate(am);
    car.getSpeed();
    cout << "  speed is " << car.getSpeed() << '\n';
    }
    else
    car.addTravelTime(am);
    cout << "?>";
    cin >> ch;
    }
    car.printInfo();
    return 0;
}
