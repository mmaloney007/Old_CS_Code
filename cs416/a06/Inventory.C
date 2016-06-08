//victor m maloney cs 416 assignment 6

/*this class is used to keep track of an array of videos.  most of the
class is stuff almost straight off the board from class.  it uses an array
of dynamically allocated videos with pointers to access videos.  it is the
workhorse of the classes that are in this program.  it also has find
functions and an output operator for id and title that it puts in order.  
note: there are two different arrays in this class one for id and the
other for title */

#include <iostream.h>
#include "Inventory.h"
#include "Video.h"
#include "readValue.h"

//constructs the inventory from the contents of the file videoinfo.dat 

Inventory::Inventory()
{
	Video video;
	int i, j, k,l;
	
	while(readValue(video)){
		for(i = numVideos; i > 0 &&
			video.idLessthan(*idOrder[i-1]); i--);
		for(j = numVideos-1; j >= i && j < numVideos; j--)
			idOrder[j+1] = idOrder[j];	
		
		idOrder[i] = new Video(video);
		
		for(l= numVideos; l>0 &&
			video.titleLessthan(*titleOrder[l-1]);
			l--);
		for(k = numVideos-1; k >= l && k < numVideos; k--)
			titleOrder[k+1] = titleOrder[k];

		titleOrder[l] = idOrder[i];
		numVideos++;
	} 
}

//rents video from in-store stock.  If the video not available, or is not
//carried by the store an error messages are printed to the screen

void Inventory::rentaVideo(const Video &video)
{
	int index;
	
	if (findId(video, index)){
		if((*idOrder[index]).instoreEqual(0))
			cout << "  ** all copies rented **\n";
		else  
			(*idOrder[index]).rent();
	}
	
	else
		cout << "  *** no such video in inventory ***\n";
}

//returns specified video to in-store store stock.  If video is not
//carried by the store, an error message is printed to the screen.

void Inventory::returnVideo(const Video &video)
{
	int index;

	if (findId(video, index)){
		if ((*idOrder[index]).rentedEqual(0))
			cout << "  ** no copies were rented **\n";
		
		else 
			(*idOrder[index]).returns();
	}
	
	else
		cout << "  *** no such video in inventory ***\n";
}

//checks to see if video is carried by the store, and if it is,
//indicates if video is available in the store.

void Inventory::checkVideo(const Video &video) const
{
	int index;

	if (findTitle(video, index)){
	
		if ((*titleOrder[index]).instoreEqual(0))
			cout << "  ** all copies rented **\n";
		else
			cout << "  at least one copy in the store\n";
	}
	
	else
		cout << "  *** no such video in inventory ***\n";
}

//prints inventory to stream in id order.

void Inventory::printId(ostream &s) const
{
	int i;

	for (i=0; i < numVideos; i++)
		cout << *(idOrder[i]);
}

//prints inventory to stream in title order

void Inventory::printTitle(ostream &s) const
{
	int i;
	
	for (i=0; i < numVideos; i++)
		cout << *(titleOrder[i]);
}

//attempts to find item in id order array. If found, passes back index of video

bool Inventory::findId(const Video &v, int &ind) const
{
	int low;
	int mid;
	int high;

	low = 0;
	high = numVideos - 1;
	mid = (low + high)/2;
	while (low <= high && (*idOrder[mid]).idNotEqual(v)){
		if ((*idOrder[mid]).idLessthan(v))
			low = mid + 1;
		else
			high = mid - 1;
		mid = (low + high)/2;
	}

	if (low <= high){
		ind = mid;
		return true;
	}
	
	else	
		return false;
}

//attempts to find item in title order array, if found passes back index

bool Inventory::findTitle(const Video &v, int &ind) const
{
	int low, mid, high;

	low = 0;
	high = numVideos - 1;
	mid = (low + high)/2;

	while (low <= high && (*titleOrder[mid]).titleNotEqual(v)){
		
		if ((*titleOrder[mid]).titleLessthan(v))
			low = mid + 1;
		else
			high = mid - 1;
			
		mid = (low + high)/2;
	}

	if (low <= high){
		ind = mid;
		return true;
	}

	else
		return false;
}
