//Victor Maloney CS 416 assignment 6 

/* this is a video class that constructs videos to be used in keeping
track of videos in a video store.  it uses dynamically allocated memory to
monitor videos so that there will not be to many.  this class has input
output equality operators as well as return and rental ops */

#ifndef VIDEO_H
#define VIDEO_H

class Video {

	friend istream& operator >>(istream &s, Video &v);
		//inputs a video object

	friend ostream& operator <<(ostream &s, const Video &v);
		//outputs a video object
	
	public:
		Video();
			//constructs all video data members to zero

		void operator =(int v);
			//assigns a video with the given id number all
			//other fields are zero

		void operator =(char t[]);
			//assigns a video with the given title all other
			//fields are zero

		bool rentedEqual(int v) const;
			//returns true if rented count is equal to int

		bool instoreEqual(int v) const;
			//returns true if instore count is equal to int

		bool idNotEqual(const Video &v) const;
			//returns true if videos ids are not equal

		bool titleNotEqual(const Video &v) const;
			//returns true if titles are not equal
		
		bool idLessthan(const Video &v) const;
			//returns true if left id is less than right id 
		
		bool titleLessthan(const Video &v) const;
			//returns true if left title is less than right title

		void rent();
			//rents a video

		void returns();
			//returns a video

	private:
		enum {maxTitle = 150};
		
		int _id;
		int _instore;
		int _rented;
		char title[maxTitle];

};

#endif 	


