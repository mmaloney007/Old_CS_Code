#ifndef MONEY_H
#define MONEY_H

/* this class defines a type which provides money values.  Money
	values are input and output in the form
	   $ddddd.dd
	where there may be any number of digits prior to the period,
	and there are two digits after the period.  Unlike real numbers,
	the point must be there, and there must be at least one digit on
	each side of the point.  Likewise, the $ must be present.

	It is assumed that input values are correct.
*/

class Money {
	public:
		Money();
			//constructs a money value of $0.00

		void input();
			//inputs a money value in the form shown above.  The
			//program assumes the money value is in the correct
			//form

		void add(Money amount);
			//adds the amount to the object, modifying the object

		Money times(int number) const;
			//returns a money value formed by multiplying the 
			//object by the integer number.

		Money minus(Money amount) const;
			//returns a money value formed by subtracting the
			//amount passed from the object.

		bool lessThan(Money amount) const;
			//relational operation, returning true if the object
			//is strictly less than the amount passed

		void output() const;
			//prints out a money value in the form given above

	private:
		int dollars;   //number of dollars
		int cents;     //number of cents
};
	
#endif
