#include <iostream.h>
string myname(char);
string myname(string a)
{
    if (a == "sarah")
    return cout<<"Hello Sarah";
    else
    return cout<<"It does not matter what your name is!";
}
int main()
{
    string a;
    const string b("sarah");
    char b;
    char c;
    char d;
    char e;
    cout<<"Hello.  What is your name?"<<'\n'<<'?';
    cin>>a;
    cout<<name (a) << '\n' << '?';
    return 0;
}
