/* Brian Johnson
        permission is granted to use and modify this class as long as
        you do not claim credit either explicitly or implicitly for the
        original code */

/* this defines a string class which includes a count
    as well as a variable length array to hold the characters. */

/* modification history
    
    4/20/00 - blj - changed toupper & tolower to toUpper & toLower
    2/24/98 - blj - changed data members to protected for easier derivation
    2/4/98 - blj - added toupper, tolower and truncate operations
    10/7/97 - blj - changed constructor argument from char* -> const char *
    10/28/96 - blj - added private constructor, fixed memory leaks
    10/9/96 - blj - fixed memory leak in substr operation
    9/17/96 - blj - added get input operation
    1/95 - rdb - renamed class from "string" to "Bstring"
                 Note: ideal name "String" is too overused
*/

#ifndef BSTRING_H
#define BSTRING_H
#include <iostream.h>

class Bstring {
        friend istream& operator >>(istream&, Bstring&);
        friend ostream& operator <<(ostream&, const Bstring&);
        friend istream& get(istream&, Bstring&, char delim);
    public:
        Bstring();      //empty string
        Bstring(const char*); //init from array of char
        Bstring(const Bstring&); //for initializing with another class obj
        ~Bstring();     //DESTRUCTOR - no type, no args
        Bstring& operator =(const Bstring&); //assignment operator

        int length() const;      //string length

        int operator == (const Bstring&) const; 
        int operator != (const Bstring&) const; 
        int operator <= (const Bstring&) const; 
        int operator >= (const Bstring&) const; 
        int operator > (const Bstring&) const; 
        int operator < (const Bstring&) const; 

        char& operator [](int); //return reference to ith char of string
        char operator [](int) const; //return ith char (used with const obj)
        Bstring& operator +=(const Bstring&); //append to orig, ret ref to orig
        Bstring& operator +=(char); //append to orig, ret ref to orig
        Bstring operator +(const Bstring&) const; //append - return new string
        Bstring operator +(char) const; //append - return new string
        Bstring substr(int,int) const; //return from first to last inclusive

        Bstring toUpper() const; //converts letters to upper case
        Bstring toLower() const; //converts letters to lower case
        Bstring truncate(char) const; //truncates string at first occurance of
                                    // specified character, char is eliminated

    protected:
        Bstring(int size,int dummy); //allocates space string of specified size,
                //dummy parameter to prevent from being conversion op
                //internal usage only

        int count;
        char *str;
};

#endif
