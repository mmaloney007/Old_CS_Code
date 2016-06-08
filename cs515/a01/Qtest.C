// Victor M. Maloney CS 515 Assignment 1

/* This assigment simulates a bank teller's line and two bank tellers lines by using circular queues ( a gueue class) and a processor ( a seperate class) to do the work in a simulated situation. */

#include <stdlib.h>
#include <iostream.h>
#include "Node.h"
#include "Queue.h"
#include "Processor.h"

int main()
{
	int time;
	Node tmp2, tmp3;
	Node tmp, tmp4;
	Queue line1;
	
	tmp.size = 1;
	tmp.starttime = 4;
	tmp2.size = 2;
	tmp2.starttime = 5;
	tmp3.size = 3;
	tmp3.starttime = 6;
	tmp4.size = 7;
	tmp4.starttime = 8;

	line1.enqueue(tmp);
	line1.enqueue(tmp2);
	line1.enqueue(tmp3);
	line1.enqueue(tmp4);

	line1.print();

	cout << "Dequeue one item\n";
	line1.dequeue();

	line1.print();
	
	line1.dequeue();
	line1.dequeue();
	line1.dequeue();

	line1.print();

	return 0;
}
