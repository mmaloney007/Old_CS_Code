/* this class defines a vehicle which keeps track of its
	current speed, distance traveled, and travel time. */

#include <iostream.h>
#include "Vehicle.h"

// ----------------------------------------------------
//constructs vehicle with speed, distance traveled,
//and travel time zero'ed.

Vehicle::Vehicle()
{
	currentSpeed = 0;
	totalTime = 0;
	totalMiles = 0;
}

// ----------------------------------------------------
//sets vehicle's speed to amount specified

void Vehicle::setSpeed(int speed)
{
	currentSpeed = speed;
}

// ----------------------------------------------------
//accelerates vehicle's speed by adding increment

void Vehicle::accelerate(int increment)
{
	currentSpeed = currentSpeed + increment;
}

// ----------------------------------------------------
//decelerates vehicle's speed by subtracting decrement

void Vehicle::decelerate(int decrement)
{
	currentSpeed = currentSpeed - decrement;
}

// ----------------------------------------------------
//causes vehicle to travel amount of time specified at
//current speed

void Vehicle::addTravelTime(int time)
{
	totalTime = totalTime + time;
	totalMiles = totalMiles + currentSpeed*time/60.0;
}

// ----------------------------------------------------
//returns vehicle's speed in miles per hour

int Vehicle::getSpeed() const
{
	return currentSpeed;
}

// ----------------------------------------------------
//prints total distance traveled, total time of trip,
//and average miles per hour for trip

void Vehicle::printInfo() const
{
	cout << "total miles traveled = " << totalMiles 
		<< " miles\n";
	cout << "total time           = " << totalTime/60.0 
		<< " hours\n";
	cout << "average speed        = " << totalMiles/(totalTime/60.0)
		<< " miles/hour\n";
}
