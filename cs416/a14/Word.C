//Victor Maloney CS 416 Assignment 14

/* this class is great it take a word from a bunch of stuff around it and
inputs it.  how does it do this you may ask?  a state machine gods gift to
the earth and the main reason this one is late.  god bless america i am
done i am done god almighty i am done */

#include <ctype.h>
#include <iostream.h>
#include <string.h>
#include "Word.h"
#include "Bstring.h"

//Constructs an empty word
Word::Word()
{
}

//upper to lower case
Bstring Word::toLower()
{
	word = word.toLower();
	return word;
}
//init from a char array

Word::Word(const char *v)
{
	Bstring word1(v);
	word = word1;
}

//subscript operator

char Word::sub(int v)
{
	return word[v];
}

//compares two words

bool Word::operator < (const Word &v) const
{
	return word < v.word;
}
//checks if two words are eqaul

bool Word::operator == (const Word &v) const
{
	return word == v.word;
}

//input operator

istream& operator >>(istream &s, Word &v)
{
	int count = 0;
	char ch;
	char store[100];
	enum State {start, final, nonword, A, letter, hyphen, number,
other, prefinal};

	State state = start;

	while(state != final) {
		switch (state) {
			case start:
				count = 0;
				state = A;
				break;

			case A:
				s >> ch;
				if(!s){
					state = final;			
				}	
				else if(ch >= 'a' && ch <= 'z' || ch >=
'A' &&	ch <= 'Z'){
					store[count++] = ch;
					state = letter;
				}
				else if(ch >= '0' && ch <= '9'){
				 	count = 0;
					state = number;
				}
				else 
					state = other;
				break;
	
			case nonword:
				count = 0;
				state = start;
				break;

			case letter:
				s.get(ch);
				if(ch >= 'a' && ch <= 'z' || ch >= 'A' &&
ch <= 'Z'){
				store[count++] = ch;
				state = letter;
				}
				else if(ch>= '0' && ch <= '9'){
					state = number;
				}
				else if(ch == '-')
					state = hyphen;
				else
					state = prefinal;
				break;

			case hyphen:
				s.get(ch);
				if(ch >= 'a' && ch <= 'z' || ch >= 'A' &&
				ch <= 'Z'){
					store[count++] = '-';
					store[count++] = ch;
					state = letter;
				}
				else if(ch == '-' || (ch >= '0' && ch <=
'9'))
					state = prefinal;
				else
					state = other;
				break;

			case other:
				if(isspace(ch)){
				state = prefinal;
				}
				else if((ch >= 'a' && ch <= 'z') || (ch >=
'A' && ch <= 'Z')){
				store[count++] = ch;
				state = letter;
				}
				else 
					state = start;
				break;

			case number:
				s.get(ch);
				if(ch >= 'a' && ch <= 'z' || ch>= 'A' &&
ch <= 'Z' || ch >= '0' && ch <= '9'){
				count = 0;
				store[count] = '\0';
				state = number;
				}
				else 
				state = nonword;
				break;
 
			case prefinal:
				store[count] = '\0';
				v = store;
				v.toLower();
				state = final;
				break;
	}			
}
	//cerr << "one input\n";
	return s;
}

//outputs a word

ostream& operator << (ostream &s, Word &v)
{
	s << v.word;
	return s;
}
