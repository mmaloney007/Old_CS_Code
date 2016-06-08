//Victor Maloney 416 Assignment # 9

#ifndef TSTACK_H
#define TSTACK_H

/* this is a basic stack class. It holds Token objects. It has all the basic 
operations, empty, pop, push, top and length. it now also has a boolean operator >=
that can make precedence comparsion easy and does a lot of grunt work in a class*/

#include <iostream.h>
#include "Token.h"

class TStack {

	public:

		class Empty{};
		class EmptyStack{};

		TStack();
			//constructs an empty stack

		~TStack();
			//destructor	

		bool empty() const;
			//returns true if stack is empty

		void push(Token v);
			//adds value to top of stack

		Token top() const;
			//returns the top element of the stack

		int length() const;
			//returns the number of elements in the stack

		void pop();
			//removes top element from stack
		
		bool operator >=(Token v0);
			// returns true if the right is greater or
			// equal to left

	private:

		struct Elem {
			Token token;
			Elem *next;
		};
		
		Elem *store;
};

#endif
