//VictorMaloney cs515 Assignment 1

/*
 this program will simulate a bank.  the first out will be for two queues 
with two bank tellers working.  The second will be for one queue and two bank 
tellers.  This program uses two classes (a circular queue & processor class).  
It also uses a container which is implemented in Node.h to make it easy to move
stuff. 
*/

#include <iostream.h>
#include <stdlib.h>
#include "Queue.h"
#include "Processor.h"
#include "Node.h"

int main()
{
	//------------------- ints, floats, and others -----------------
	Processor p1;
	Processor p2;
	Processor p3; 
	Processor p4;
	Queue line1;
	Queue line2;
	Queue line3;
	Node node;
	Node tmp;
	float wait25 = 0;
	float wait50 = 0;
	float wait75 = 0;
	float wait100 = 0; 
	float total = 0;
	float wait252q = 0;
	float wait502q = 0;
	float wait752q = 0;
	float wait1002q = 0; 
	float total2q = 0;
	int lwait=0;
	int lwait2q=0;
	int time = 0;
	int totalprocesstime = 0;
	int totalprocesstime2 = 0;

	//----------------------main program-----------------------------

	//----------------for loop with two queues ----------------------

	for(time=0; time < 1000000; time++){
		if((rand()%5) < 1){
			total++;
			node.size = rand()%15 + 1;
			node.starttime = time;
			totalprocesstime = totalprocesstime + node.size;

			if(rand()%2 < 1)
				line1.enqueue(node);
			else
				line2.enqueue(node);
		}
		p1.process();
		p2.process();
		if(p1.isFree())
			if(!(line1.empty())){
				tmp = line1.dequeue();
				if(time - tmp.starttime > lwait)
					lwait = time - tmp.starttime;
				if(time - tmp.starttime > 100)
					wait100 = wait100+1;
				if(time - tmp.starttime > 75)
					wait75 = wait75 + 1;
				if(time - tmp.starttime > 50)
					wait50 = wait50 + 1;
				if(time - tmp.starttime > 25)
					wait25 = wait25+1;
				p1.addTask(tmp);
			}
		if(p2.isFree())
			if(!(line2.empty())){
				tmp = line2.dequeue();
				if(time - tmp.starttime > lwait)
					lwait = time - tmp.starttime;
				if(time - tmp.starttime > 100)
					wait100 = wait100 + 1;
				if(time - tmp.starttime > 75)
					wait75 = wait75 + 1;
				if(time - tmp.starttime > 50)
					wait50 = wait50 + 1;
				if(time - tmp.starttime > 25)
					wait25 = wait25 + 1;
				p2.addTask(tmp);
			}
	}
	
	//--------------for loop with one queue--------------------------

	for(time=0; time < 1000000; time++){
		if((rand()%5) < 1){

			++total2q;
			node.size = rand()%15 + 1;
			node.starttime =time;
			totalprocesstime2 = totalprocesstime2 + node.size;
			line3.enqueue(node);

		}

		p3.process();
		p4.process();

		if(p3.isFree())
			if(line3.empty() == 0){
				tmp = line3.dequeue();
				if(time - tmp.starttime > lwait2q)
					lwait2q = time - tmp.starttime;
				if(time - tmp.starttime > 100)
					wait1002q = wait1002q + 1;
				if(time - tmp.starttime > 75)
					wait752q = wait752q + 1;
				if(time - tmp.starttime > 50)
					wait502q = wait502q + 1;
				if(time - tmp.starttime > 25)
					wait252q = wait252q + 1;
				p3.addTask(tmp);
			}
		if(p4.isFree())
			if(!(line3.empty())){
				tmp = line3.dequeue();
				if(time - tmp.starttime > lwait2q)
					lwait2q = time - tmp.starttime;
				if(time - tmp.starttime > 100)
					wait1002q = wait1002q + 1;
				if(time - tmp.starttime > 75)
					wait752q = wait752q + 1;
				if(time - tmp.starttime > 50)
					wait502q = wait502q + 1;
				if(time - tmp.starttime > 25)
					wait252q = wait252q + 1;
				p4.addTask(tmp);
			}
	}

	//----------------Program output-------------------------

cout << "\nTwo Queues & Two Processors \n";
cout << "\nTotal Processes = " << total; 
cout << "\nLongest wait for a Process= " << lwait << '\n'; 
cout << "Average Procces time = " << totalprocesstime/total << '\n';
cout <<"Percentage of Processes that wait longer than 25 : " ;
cout << wait25/total*100 << " %\n"; 
cout <<"Percentage of Processes that wait longer than 50 : " ; 
cout << wait50/total*100 << " %\n"; 
cout <<"Percentage of Processes that wait longer than 75 : " ;
cout << wait75/total*100 << " %\n"; 
cout <<"Percentage of Processes that wait longer than 100 : " ;
cout << wait100/total*100 << " %\n";
cout << "\nSingle Queue & Two Processors \n";
cout << "\nTotal Processes = " << total2q << "\n";
cout << "Longest wait for a Process = " << lwait2q << '\n';
cout << "Average Process time = " << totalprocesstime2/total2q << '\n';
cout <<"Percentage of Processes that wait longer than 25 : " ;
cout << wait252q/total2q*100 << " %\n"; 
cout <<"Percentage of Processes that wait longer than 50 : " ;
cout << wait502q/total2q*100 << " %\n"; 
cout <<"Percentage of Processes that wait longer than 75 : " ;
cout << wait752q/total2q*100 << " %\n"; 
cout <<"Percentage of Processes that wait longer than 100 :  " ;
cout << wait1002q/total2q*100 << " %\n";

	return 0;
} 
