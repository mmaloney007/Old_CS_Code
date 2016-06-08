//assignment 7 vic maloney cs 415 section 1
/*this fuction tells you if what you entered is a lower case or not*/
bool isLowerCaseLetter(char ch)
{
    return ('a' <= ch && ch <= 'z');
}
/*this fuction tells you what kind of character you have entered returning
U for uppercase, l for lowercase, d for digit, and s for everything else*/
char charKind(char ch)
{
    if ('a' <= ch && ch <= 'z')
    return 'l';
        if ('A' <= ch && ch <= 'Z')
        return 'U';
            if ('0' <= ch && ch <= '9')
            return 'd';
            else
            return 's';
}
/*this fucntion gives one the oppostite case of the one entered unless it
is not a letter*/
char flipCase(char ch)
{
    if ('a' <= ch && ch <= 'z')
    return ch - 'a' + 'A';
        if ('A' <= ch && ch <= 'Z')
        return ch - 'A' + 'a';
        else
        return ch;
}
/*this fucntion turns a character to its conresponding number in the form
of an integer*/
int ch2num(char ch)
{
    return ch - 'a' + 1;
}
/*this function encodes an uppercase character using a 'roman cypher'*/
char encode(char ch)
{
    return ((ch - 'A' + 5) % 26) + 'A';
} 
