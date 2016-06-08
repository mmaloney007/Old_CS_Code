//Victor Maloney

#ifndef STACK_H
#define STACK_H


#include <iostream.h>

class Stack {

	public:

		class Empty{};
		class EmptyStack{};

		Stack();
			//constructs an empty stack

		~Stack();
			//destructor	

		bool empty() const;
			//returns true if stack is empty

		void push(int v);
			//adds value to top of stack

		int top() const;
			//returns the top element of the stack

		int length() const;
			//returns the number of elements in the stack

		void pop();
			//removes top element from stack
		

	private:

		struct Elem {
			int val;
			Elem *next;
		};
		
		Elem *store;
};

#endif
