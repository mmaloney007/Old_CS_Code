//Victor Maloney CS 416 Assignment 9

/* this is a program that takes infixed expressions and moves them into a postfix
expresssion.  it uses a stack class of tokens written by me and a token class written
by blj.  i am glad it is now done */

#include <iostream.h>
#include "Token.h"
#include "TStack.h"

int main()
{
	const int maxLine = 50;
	Token token;
	TStack stack;
	char dum[maxLine];
	
	cout << "enter infix expressions, terminate with ctl D\n\n?> ";
	
	while (cin >> token){ 
			
			while (token.kind() == Token::real || (token.kind() ==
			 Token::sym && token.symvalue() != ';')){
				
				if(token.kind() == Token::real){
				try {
					cout << token << ' ';
				}
					catch(Token::NoToken()){
						cerr << "token contains "
							<< "nothing\n";
						exit(1);	
					}
			}
		
			else if (token.kind() == Token::sym &&
(token.symvalue() == '+' || token.symvalue() == '-' ||
token.symvalue() == '*' || token.symvalue() == '/' || token.symvalue() ==
'~')){
				while (!stack.empty() && stack >= token){
					try {
						cout <<(stack.top()).symvalue()
						 << ' ';
						stack.pop();
					}
						catch(TStack::Empty()){
							cerr << " ***bad "
							<< "expression syntax ***\n";
						}
			}
			stack.push(token);
			
			}
		
			else if (token.symvalue() == '(')
				stack.push(token);

			else if (token.symvalue() == ')') {
				
				try {
					while ((stack.top()).symvalue() != '('){
					cout << stack.top() << ' ';
					stack.pop();
				}
			stack.pop();
			}
				catch(TStack::Empty){
					cout << "*** bad expression"
					<< " syntax ***\n?> ";
					cin.getline(dum, maxLine);
				}
			}
			else {
				cout << " *** unknown operator ***\n\n?>";
				while (!stack.empty())
					stack.pop();
				cin.getline(dum, maxLine);
			}
			cin >> token;
		}	 

		while (!stack.empty()){
		    try{
			cout << stack.top() << ' ';
			stack.pop();
		    }
		    catch(TStack::Empty()){
		
			}
		}
		
		cout << "\n\n?> ";
		}
	cout << "\n";
	return 0;
}
