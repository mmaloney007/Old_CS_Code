//Victor Maloney CS 416 assignment 14

#ifndef WORD_H
#define WORD_H

/* this class is amazing as it contains a state machine that can determine
what are words and what aren't words.  the input operator has a state
machine and in will make all words entire lower case */

#include <iostream.h>
#include "Bstring.h"

class Word{

	friend istream& operator >>(istream &s, Word &v);

	friend ostream& operator <<(ostream &s, Word &v);

	public:

		Word();
		//constructs a word

		Word(const char *v);
		//constructs a word from a string
		
		bool operator < (const Word &v) const;
		//boolean operator less than

		bool operator == (const Word &v) const;
		//boolean operator equal too
		
		Bstring toLower();
		//makes entire word lower case

		char sub(int v);
		//subscripting operator		
	protected:

		Bstring word;

};

#endif
