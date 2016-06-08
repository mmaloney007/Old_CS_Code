//Victor Maloney cs 515 Assignment 1

/*
 this is the Processor header.  it contains the private information and public
declarations of the functions.  the processor class is just an decrementing
class that is also able to addtasks and check to see if it is itself free to 
get another task. 
*/

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <iostream.h>
#include "Node.h"

class Processor {
	
	public:

		Processor();
			//constructor	

		bool isFree();
			//returns true if processor is free

		void addTask(Node time);
			//adds a task to the processor

		void process();
			//processes the task at hand

	private:

		int size;
		int starttime;

};
#endif
		
