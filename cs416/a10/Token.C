/* this class implements a token type, which may be used to read
	in and access one of several types of objects.

	  items which may be read are unsigned floats and
	  non-digit (and non-white) characters which are called symbols
*/

#include <ctype.h>
#include "Token.h"


//------------------------------------------------------------
// constructors

//.............................................................
/* constructs a token containing nothing */

Token::Token()
{
	tokenKind = nothing;
}

//.............................................................
/* constructs symbol token from character */

Token::Token(char v)
{
	tokenKind = sym;
	symval = v;
}

//.............................................................
/* constructs real token from float */

Token::Token(float v)
{
	tokenKind = real;
	realval = v;
}


//-------------------------------------------------------------
/* this function returns the type of token read */
	/* note: need to scope tokenkind since is used outside 
			member function */

Token::TokenKind Token::kind() const
{
	return tokenKind;
}

//-------------------------------------------------------------
/* this function returns the value of the token if it is a real and
	causes the program to abort if the access is not valid */

float Token::realvalue() const
	throw(Token::NotReal)
{
	if (tokenKind != Token::real)
		throw NotReal();

	return realval;
}

//-------------------------------------------------------------
/* this function returns the value of the token if it is a symbol and
	causes the program to abort if the access is not valid */

char Token::symvalue() const
	throw(Token::NotSymbol)
{
	if (tokenKind != Token::sym)
		throw NotSymbol();

	return symval;

}

//-------------------------------------------------------------
/* inputs a token */

istream& operator >> (istream& s, Token& v)
{
	char ch;
	float num;

	while (s.get(ch) && isspace(ch)); //skip leading white space

	if (s) 
		if (ch >= '0' && ch <= '9') {
			s.putback(ch);  //return character to stream
			s >> v.realval; //then read as number
			v.tokenKind = Token::real;
			}

		else {
			v.symval = ch;
			v.tokenKind = Token::sym;
		}

	return s;
}

//-------------------------------------------------------------
ostream & operator <<(ostream &s, const Token &v)
	throw(Token::NoToken)
{
	switch (v.tokenKind) {
		case Token::real:
			s << v.realval;
			break;

		case Token::sym:
			s << v.symval;
			break;

		case Token::nothing:
			throw Token::NoToken();
			break;
	}

	return s;
}
