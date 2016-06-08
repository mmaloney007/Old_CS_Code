#ifndef UNKNOWN_H
#define UNKNOWN_H
/* this class provides a type whose values are "unknown".  The variables are
 * initialized with integers which are generated randomly when the variable is
 * defined.  Unknown integers will automatically convert to integers, and
 * integers will automatically convert to unknown integers, and thus the two
 * types may be used interchangeably after the UnknownInt has been defined.
 *
 * Because of this automatic conversion, unknown integers may be manipulated
 * arithmetically and may be output.  They may not, however, be input or used
 * in the place of an integer variable (where a variable rather than a value is
 * required). That is, the values are interchangeable, but the actual variables
 * are not. */

class UnknownInt {

	public:
		UnknownInt();
			//constructs unknown integer;

		UnknownInt(int v);
			//type conversion from integer to unknown;

		UnknownInt(int low,int high);
			//constructs an unknown integer value in range given

		operator int() const;
			//type conversion from unknown to integer;

	private:

		static bool firstTime;
			//randomizes each run - to have same sequence of random values 
			// each time, change initialization at top of code file to false.

		int dummy1; 
		int value; // contains the actual value 
		int dummy2;
};

#endif
