//Victor Maloney CS 416 assignment 6

/*this is the program class for video.h.  it uses memory for means and is
basically a counter class with a string for the title.  it has input
output boolean ops.  it also has ops for rental and returning
videos.  this is a small class that will be pair with inventory class */

#include <iostream.h>
#include <string.h>
#include "Video.h"

//constructs a video

Video::Video()
{
	_id = 0;
	_instore = 0;
	_rented = 0;
	title[0] = '\0';
}

//constructs a video with the given id

void Video::operator =(int v)
{
	_id = v;
	_instore = 0;
	_rented = 0;
	title[0] = '\0'; 
}

//constructs a video with the given title

void Video::operator =(char t[])
{
	_id = 0;
	_instore = 0;
	_rented = 0;
	strcpy(title, t);
}

//returns true if rented count is equal to int

bool Video::rentedEqual(int v) const
{
	return _rented == v;
}

//returns true if instore count is equal to int

bool Video::instoreEqual(int v) const
{
	return _instore == v;
}

//returns true if the videos ids are not equal

bool Video::idNotEqual(const Video &v) const
{
	return _id != v._id;
}

//returns true if videos titles are not equal

bool Video::titleNotEqual(const Video &v) const
{
	if(strcmp(title, v.title) == 0)
		return false;
	
	else 
		return true;
}

//returns true if left id is less than right id

bool Video::idLessthan(const Video &v) const
{
	return _id < v._id;
}

//returns true if left title is less than right title

bool Video::titleLessthan(const Video &v) const
{
	return strcmp(title, v.title) < 0;
}

//rents a video

void Video::rent()
{
	_instore--;
	_rented++;
}

//returns a video

void Video::returns()
{
	_instore++;
	_rented--;
}

istream& operator >>(istream &s, Video &v)
{
	char ch;
	
	s >> v._id >> v._instore >> v._rented;
	s.get(ch);
	s.get(v.title, 200);
	return s;
}

ostream& operator <<(ostream &s, const Video &v) 
{
	s << v._id <<'\t'<< v._instore <<'\t'<< v._rented <<'\t'; 
	s << v.title << '\n';
	return s;
}

