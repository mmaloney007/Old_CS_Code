//victor maloney modified header assignment 6

#ifndef INVENTORY_H
#define INVENTORY_H

/* this class defines a video store inventory.  The inventory
	is initially filled from the file "videoinfo.dat" on 
	construction.  Each different video has a title and a id,
	as well as the count of rented and instore copies.
	
	The inventory provides both title and id ordering.

	NOTE: objects of this class should NEVER be assigned,
	NOR should they ever be passed by value.
*/

#include "Video.h"

class Inventory {

	public:
		Inventory();
			//constructs the inventory from the contents of
			//the file videoinfo.dat

		void rentaVideo(const Video &video);
			//rents video from in-store stock.  If video not
			//available, or is not carried, error messages are
			//printed

		void returnVideo(const Video &video);
			//returns video to in-store stock.  If video is
			//not carried, an error message is printed.

		void checkVideo(const Video &video) const;
			//checks to see if video is carried, and if it is,
			//indicates if video is available in the store.

		void printId(ostream &s) const;
			//prints inventory to stream in id order

		void printTitle(ostream &s) const;
			//prints inventory to stream in title order
		
	private:
		enum {maxVideos = 5000};

		int numVideos;
		Video *idOrder[maxVideos];
		Video *titleOrder[maxVideos];

		bool findId(const Video &v, int &ind) const;
			//attempts to find item in id order array.  If
			//found, passes back index of video

		bool findTitle(const Video &v, int &ind) const;
			//attempts to find item in title order array.  If
			//found, passes back index of video

		Inventory& operator =(const Inventory &);
			//assignment operator - not implemented
		Inventory(const Inventory &);
			//copy constructor - not implemented
};

#endif
