//Victor Maloney CS 515 Assignment 1

/*
 this class basically counts to simulate a larger or smaller order for the bank
tellers.  other than that is also checks if the processor is free and is also 
able to add tasks to itself.  
*/

#include <iostream.h>
#include "Processor.h"

//creates a processor

Processor::Processor()
{
	size = 0;
	starttime = 0;
}

//returns true if processor is free

bool Processor::isFree()
{
	if(size <= 0)
		return true;
	else
		return false;
}

//adds a task (node) to the processor

void Processor::addTask(Node node)
{
	size = node.size;
	starttime = node.starttime;
}

//processes the task at hand

void Processor::process()
{
	size--;
}
