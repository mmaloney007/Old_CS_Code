//vic maloney unkown int assignment 10 cs 415 section 1
#include <iostream.h>
#include "UnknownInt.h"
int msd(int num)
{
    if (num >= 10)
    return msd(num / 10);
    else
    return num;
}
int main()
{
    UnknownInt a;
    UnknownInt b;
    UnknownInt c;
    UnknownInt d;
    UnknownInt e(0,9);
    UnknownInt f(0);
    cout<<"first unknown";
    cout<<'\n';
    cout<<"  value = ";
    cout<<a;
    cout<<'\n';
    cout<<"  msd = ";
    cout<<msd(a);
    cout<<'\n';
    cout<<'\n';
    cout<<"second unknown";
    cout<<'\n';
    cout<<"  value = ";
    cout<<b;
    cout<<'\n';
    cout<<"  msd = ";
    cout<<msd(b);
    cout<<'\n';
    cout<<'\n';
    cout<<"third unknown";
    cout<<'\n';
    cout<<"  value = ";
    cout<<c;
    cout<<'\n';
    cout<<"  msd = ";
    cout<<msd(c);
    cout<<'\n';
    cout<<'\n';
    cout<<"fourth unknown";
    cout<<'\n';
    cout<<"  value = ";
    cout<<d;
    cout<<'\n';
    cout<<"  msd = ";
    cout<<msd(d);
    cout<<'\n';
    cout<<'\n';
    cout<<"fifth unknown";
    cout<<'\n';
    cout<<"  value = ";
    cout<<e;
    cout<<'\n';
    cout<<"  msd = ";
    cout<<msd(e);
    cout<<'\n';
    cout<<'\n';
    cout<<"sixth unknown";
    cout<<'\n';
    cout<<"  value = ";
    cout<<f;
    cout<<'\n';
    cout<<"  msd = ";
    cout<< msd(f);
    cout<<'\n';
    return 0;
}
