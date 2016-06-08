/* Brian Johnson
    permission is granted to use and modify this class as long as
    you do not claim credit either explicitly or implicitly for the
    original code */

/* this defines a string class which includes a count
    as well as a variable length array to hold the characters. */

/* modification history

    4/20/00 - blj - changed toupper & tolower to toUpper & toLower
    2/24/98 - blj - changed data members to protected for easier derivation
    2/4/98 - blj - added toupper, tolower, and truncate operations
    12/17/97 - blj - fixed eof error in get operation
    10/15/97 - blj - removed "no return" situation from []
    10/7/97 - blj - changed constructor argument from char* -> const char *
    10/27/96 - blj - added private constructor, elminated memory leaks
    10/9/96 - blj - fixed memory leak in substring
    9/17/96 - blj - added get operation for input
    1/95 - rdb - renamed class from "string" to "Bstring"
                 Note: ideal name "String" is too overused
*/


#include <stdlib.h>
#include <string.h>

#include "Bstring.h"

//  protected:
//      int count;
//      char *str;

/* ----------------------------------------------------------- */
/* constructors */

// empty string
Bstring::Bstring()
{
    count = 0;
    str = new char[1]; //array for consistency
    str[0] = '\0'; //null string
}

//init from array of char
Bstring::Bstring(const char* s)
{
    count = strlen(s);
    str = new char[count+1];   //extra char for null
    strcpy(str,s);
}

//copy constructor - used when init with obj of same class
// either by direct initialization or pass by value
// without this, you would just get a member copy, which would
// cause a disaster when the destructor was called for one of
// the copies.

Bstring::Bstring(const Bstring& s)
{
    count = s.count;
    str = new char[count+1];
    strcpy(str,s.str);
}

// allocates space for specified size string, but does not fill it
// in.  Second parameter is a dummy, to still allow for conversion op from
// int someday.  intended for internal usage only, as char are not filled in

// note: size parameter should not include space for terminator - that is
//  taken care of within the constructor

Bstring::Bstring(int stringsize, int dummy)
{
    dummy = 1;
    count = stringsize;
    str = new char[stringsize + 1];
}

/* ----------------------------------------------------------- */
/* destructor */

Bstring::~Bstring()
{
    delete []str;    //created as array, delete as array
}

/* --------------------------------------------------------- */
/* assignment operator */
// note: the variable "this" is a pointer to the object receiving
//       the message

Bstring& Bstring::operator =(const Bstring& s)
{
    if (this != &s) {    // addresses different so different actual object
            count = s.count;
            delete []str;  // get rid of storage for original string

            str = new char[count+1]; // and allocate new
            strcpy(str,s.str);
    }

    return *this;  // return string
}

/* --------------------------------------------------------- */
/* string length */

int Bstring::length() const
{
    return count;
}

/* --------------------------------------------------------- */
/* string relations */

int Bstring::operator == (const Bstring& s) const
{
    if (count != s.count)
        return 0;

    else
        return strcmp(str,s.str) == 0;
    // s goes out of scope, destructor called
}

int Bstring::operator != (const Bstring& s) const
{
    if (count != s.count)
        return 1;
    else
        return strcmp(str,s.str);
}

int Bstring::operator <= (const Bstring& s) const
{
    return strcmp(str,s.str) <= 0;
}

int Bstring::operator >= (const Bstring& s) const
{
    return strcmp(str,s.str) >= 0;
}

int Bstring::operator > (const Bstring& s) const
{
    return strcmp(str,s.str) > 0;
}

int Bstring::operator < (const Bstring& s) const
{
    return strcmp(str,s.str) < 0;
}

/* ----------------------------------------------------------- */
//return reference to ith char from string

char& Bstring::operator [](int i)
{
    if (i < 0 || i >= count) {
        cerr << "Bstring::invalid subscript [" << i << "]\n";
        exit(1);
        }
    
    return str[i];
}

// this version works for const objects, the other for non-const objects
char Bstring::operator [](int i) const
{
    if (i < 0 || i >= count) {
        cerr << "Bstring::invalid subscript [" << i << "]\n";
        exit(1);
        }
    
    return str[i];
}

/* ----------------------------------------------------------- */
//append to original, ret ref to orig

Bstring& Bstring::operator +=(const Bstring& s)
{
    char *tmp = str;
    char *tmp2 = s.str;  //in case s += s
    int tmpcount = count;

    count = tmpcount + s.count;
    str = new char[count+1];
    strcpy(str,tmp);
    strcat(str,tmp2);
    
    delete []tmp;

    if (this == &s) //if modifying same string, delete old storage
        delete []tmp2;

    return *this;
}

/* ----------------------------------------------------------- */
//add char to end, ret ref to orig

Bstring& Bstring::operator +=(char c)
{
    char *tmp = str;
    str = new char[count + 2];
    strcpy(str,tmp);
    str[count] = c;
    str[count+1] = '\0';
    count++;
    delete []tmp;
    return *this;
}

/* ----------------------------------------------------------- */
//append - return new string

Bstring Bstring::operator +(const Bstring& s) const
{
    Bstring tmpstring(count+s.count, 0); //allocate space but dont fill

    strcpy(tmpstring.str,str);
    strcat(tmpstring.str,s.str);

    return tmpstring;
}

/* ----------------------------------------------------------- */
//add char to end - return new string

Bstring Bstring::operator +(char c) const
{
    Bstring tmpstring(count+1, 0); //allocate space but don't fill
    strcpy(tmpstring.str,str);
    tmpstring.str[count] = c;
    tmpstring.str[count+1] = '\0';

    return tmpstring;
}

/* ----------------------------------------------------------- */
//return string between positions

Bstring Bstring::substr(int i,int j) const
{
    int k = 0;

    if (j < i)
        return Bstring("");

    else {
        if (i<0)
            i = 0;
        
        if (j >= count)
            j = count-1;


        Bstring tmpstring(j-i+1, 0); //allocates space, but doesn't fill

        for(k=0;i<=j;i++,k++)
            tmpstring.str[k] = str[i];

        tmpstring.str[k] = '\0';

        return tmpstring;
    }
}

/* ----------------------------------------------------------- */
/* this function returns a new string with the lower case letters
    converted to upper case */

Bstring Bstring::toUpper() const
{
    Bstring s1(*this);
    int i;

    for (i=0; i<s1.count; i++)
        if (s1.str[i] >= 'a' && s1.str[i] <= 'z')
            s1.str[i] = s1.str[i] - 'a' + 'A';

    return s1;
}

/* ----------------------------------------------------------- */
/* this function returns a new string with the upper case letters
    converted to lower case */

Bstring Bstring::toLower() const
{
    Bstring s1(*this);
    int i;

    for (i=0; i<s1.count; i++)
        if (s1.str[i] >= 'A' && s1.str[i] <= 'Z')
            s1.str[i] = s1.str[i] - 'A' + 'a';

    return s1;
}



/* ----------------------------------------------------------- */
/* this function returns a new string formed by truncating 
    the original string at the first occurance of the character
    passed.  The character is also eliminated.  If the character
    does not appear, no truncation takes place and the entire string
    is returned. */

Bstring Bstring::truncate(char ch) const
{
    int i;

    for (i=0; i<count && str[i] != ch; i++);

    if (i >= count)
        return *this;

    else {
        Bstring tmp(i,0);
        int j;

        for (j=0; j<i; j++)
            tmp.str[j] = str[j];

        tmp.str[j] = '\0';
        return tmp;
    }
}
        
/* ----------------------------------------------------------- */
istream& operator >>(istream& i, Bstring& s)
{
    char tmp[512];

    i >> tmp;

    if (i) {
        s.count = strlen(tmp);
        delete []s.str;
        s.str = new char[s.count+1];
        strcpy(s.str,tmp);
    }

    return i;
}

/* ----------------------------------------------------------- */

ostream& operator <<(ostream& o, const Bstring& s)
{
    o << s.str;
    return o;
}

/* ----------------------------------------------------------- */
/* gets string from stream until delimiter is encountered.
    this function is limited to 511 characters, which it does not
    protect against.  If end of file is encountered, the passed 
    string is not modified */

istream& get(istream& in, Bstring& s, char delim)
{
    char tmp[512];
    int i = 0;
    char ch;

    if (in >> ch) {
        while (in && ch != delim) {
            tmp[i++] = ch;
            in.get(ch);
        }
        tmp[i] = '\0';
    }



    if (in) {
        s.count = strlen(tmp);
        delete []s.str;
        s.str = new char[s.count+1];
        strcpy(s.str,tmp);
    }

    return in;
}

