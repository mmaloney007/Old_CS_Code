#ifndef TOKEN_H
#define TOKEN_H

/* this class implements a token type, which may be used to read
	in and access one of several types of objects.

	  items which may be read are unsigned floats and
	  non-digit (and non-white) characters which are called symbols
*/

#include <iostream.h>

class Token {

	public:

		class NotSymbol{};
		class NotReal{};
		class NoToken{};
			//exceptions thrown

		enum TokenKind {real, sym, nothing};
			//indication of kind of token
			//access as Token::real, Token::sym

		Token();
			//constructs a token containing nothing

		Token(char);
			//constructs symbol token from character

		Token(float);
			//constructs real token from float

		TokenKind kind() const;
			//returns kind (Token::real, Token::sym) of token read

		float realvalue() const throw(NotReal);
			//returns the value of token if real

		char symvalue() const throw(NotSymbol);
			//returns the value of token if symbol

	friend istream& operator >> (istream&, Token&);
		//inputs token

	friend ostream& operator << (ostream&, const Token&)
			throw(NoToken);
		//outputs token, exception if token contains nothing

	private:
		TokenKind tokenKind;  //which kind is it

		float realval;   //value for appropriate kind, other empty
		char symval;
};

#endif
