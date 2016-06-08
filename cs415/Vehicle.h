#ifndef VEHICLE_H
#define VEHICLE_H

/* this class defines a vehicle which keeps track of its
	current speed, distance traveled, and travel time. */

class Vehicle {
	public:
		Vehicle();
			//constructs vehicle with speed, distance traveled,
			//and travel time zero'ed.

		void setSpeed(int speed);
			//sets vehicle's speed to amount specified

		void accelerate(int increment);
			//accelerates vehicle's speed by adding increment

		void decelerate(int decrement);
			//decelerates vehicle's speed by subtracting decrement

		void addTravelTime(int time);
			//causes vehicle to travel amount of time specified at
			//current speed

		int getSpeed() const;
			//returns vehicle's speed in miles per hour

		void printInfo() const;
			//prints total distance traveled, total time of trip,
			//and average miles per hour for trip

	private:
		int currentSpeed;
		int totalTime;
		float totalMiles;
};

#endif
