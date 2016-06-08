//Victor Maloney CS 416 Assignment # 14

/* this is a great little program that tells you all the words you used in a file.  it outputs the number of words that starts with any
given letter, then also the words that start with a given letter.  it skips letters that you don't have any words that they start
with.  it uses many things such as a word class and a list class.  it also takes in from a file instead of cin.  */

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include "List.h"
#include "Word.h"

class NotOpen{};

int main(int argc, const char *argv[])
{
	int count = 0;
	char ch;
	char letter;
	fstream in;
	Word word;
	List list;
	int i(1);

		in.open(argv[i], ios::in);
			
		while(in >> word){
			list.insert(word);
		}
		
	letter = 'a';
	list.reset();
	while(list.yield(word)){
		ch = word.sub(0);
		if(ch == letter)
		count++;
		else if(ch == letter + 1){
			cout << letter++ << "  " << count << '\n';
			count = 1;
	}
	else {
		while(ch != letter){
			cout << letter++ << "  " << count << '\n';
			count = 0;
		}
		count = 1;
		}
	}
	cout << letter << "  " << count << '\n';
	while(letter < 'z'){
		cout << ++letter;
		cout << "  " << '0' << '\n';
	}

	letter = '~';
	list.reset();
	while(list.yield(word)){
		ch = word.sub(0);
		if(ch == letter)
			cout << word << '\n';
		else{
			cout << "----" << ch << "----\n";
			cout << word << '\n';
			letter = ch;
		}
	}
	cout << "----- end of list -----\n";
	cout << "normal termination\n";
	return 0;
}
