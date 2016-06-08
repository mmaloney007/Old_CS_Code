//Victor Maloney CS 416 Assignment # 9

/* this program changes an infix expression to a postfix expression.  It has
two classes, a token class, and a stack class.  It uses exception handling. */

#include <iostream.h>
#include "Token.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
	class Unknown{};
	const int maxLine = 50;
	Token token;
	Token tmp;
	Stack symbol;
	Stack eval;
	Queue queue;
	Queue queue2;
	char dum[maxLine];
	float value;

	cout << "enter infix expressions, terminate with ctl D\n\n?> ";
	
	while (cin >> token){
	 
		cout << "   building postfix: ";
	
		while (token.kind() == Token::real || (token.kind() == 
				Token::sym && token.symvalue() != ';')){

			if (token.kind() == Token::real){
				try {
					cout << token << " ";
					queue.enqueue(token);
				}
					catch(Token::NoToken()){
						cerr << "token contains "
							<< "nothing\n";
						exit(1);	
					}
			}
		
			else if (token.kind() == Token::sym && (token.symvalue() == '+' || token.symvalue() == '-' || token.symvalue() == '*' || token.symvalue() == '/' || token.symvalue() == '~')){
				while (!symbol.empty() && symbol>=token){
					try {
						cout <<(symbol.top()).symvalue()
							 << " ";

					queue.enqueue((symbol.top()).symvalue());
						symbol.pop();
					}
						catch(Stack::Empty()){
							cerr << " *** bad "
							<< "expression syntax"
							<< " ***\n";
						}
				}
				symbol.push(token);
			
			}
		
			else if (token.symvalue() == '(')
				symbol.push(token);

			else if (token.symvalue() == ')') {
				
				try {
					while((symbol.top()).symvalue() != '('){
						cout <<(symbol.top()).symvalue()
							 << " ";

					queue.enqueue((symbol.top()).symvalue());
						symbol.pop();
					}	
				
				symbol.pop();
				}
					catch(Stack::Empty){
						cout << " *** bad expression" 
							<< " syntax ***\n?> ";
						cin.getline(dum, maxLine);	
					}
			}
			else {
				cout << " *** unknown operator ***\n\n?> ";
				while (!symbol.empty())
					symbol.pop();
				while (!queue.empty())
					queue.dequeue();
				cin.getline(dum, maxLine);
			}
			cin >> token;
		}
		while (!symbol.empty()){
			try {
				cout << symbol.top() << " ";
				queue.enqueue((symbol.top()).symvalue());	
				symbol.pop();
			}
				catch(Stack::Empty()){
				
				}
		}
		cout << "\n   final postfix:    ";
		
		while(!queue.empty()){
			cout << queue.front() << " ";
			queue2.enqueue(queue.front());
			queue.dequeue();
		}
		
		cout << "\n   expr result:      ";
		
		try {
			while (!queue2.empty()){
			
				if ((queue2.front()).kind() == Token::real)
					eval.push(queue2.front());
			
				else if ((queue2.front()).symvalue() == '+'){
					tmp = eval.top();
					eval.pop();
					Token sum((eval.top()).realvalue() + tmp.realvalue());
					eval.pop();
					eval.push(sum);
				}
	
				else if ((queue2.front()).symvalue() == '-'){
					tmp = eval.top();
					eval.pop();
					Token dif((eval.top()).realvalue() - tmp.realvalue());
					eval.pop();
					eval.push(dif);
				}

				else if ((queue2.front()).symvalue() == '*'){
					tmp = eval.top();
					eval.pop();
					Token prod((eval.top()).realvalue() * tmp.realvalue());
					eval.pop();
					eval.push(prod);
				}

				else if ((queue2.front()).symvalue() == '/'){
					tmp = eval.top();
					eval.pop();
					Token quo((eval.top()).realvalue() / tmp.realvalue());
					eval.pop();
					eval.push(quo);
				}

				else if ((queue2.front()).symvalue() == '~'){
					Token neg(0 - (eval.top()).realvalue());
					eval.pop();
					eval.push(neg);
				}
				
				else
					throw Stack::Empty();

				queue2.dequeue();
			}
			
			value = ((eval.top()).realvalue());
			eval.pop();
			if (!eval.empty())
				throw Stack::Empty();
			else
				cout << value;
		}
			catch (...){
				cout << "*** bad postfix expression syntax ***";
				while(!queue2.empty())
					queue2.dequeue();
				while(!eval.empty())
					eval.pop();
			} 
			
		cout << "\n\n?> ";
	}
	cout << '\n';
	return 0;
}
