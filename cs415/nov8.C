//vic maloney assignment 11 cs415 section 1 nov 4 1999
#include <iostream.h>
int main()
{
    char num;
    int num1 = 0;
    int num2 = 0;
    cout<<"enter characters of two integers, end with ;"<<'\n'<<"?> ";
    cin>>num;
    while(num >= '0' && num <= '9'){
    num = num - '0';
    num1 = num1 * 10 + num;
    cin>>num;
    }
    cout<<"?> ";
    cin>>num;
    while(num >= '0' && num <= '9'){
    num = num - '0';
    num2 = num2 * 10 + num;
    cin>>num;
    }
    cout<<"the numbers are "<<num1<<" and "<<num2<<'\n';
    cout<<"  "<<num1<<" + "<<num2<<" = "<<num1 + num2<<'\n';
    cout<<"  "<<num1<<" - "<<num2<<" = "<<num1 - num2<<'\n';
    cout<<"  "<<num1<<" * "<<num2<<" = "<<num1 * num2<<'\n';
    cout<<"  "<<num1<<" / "<<num2<<" = "<<num1 / num2<<'\n';
    cout<<"  "<<num1<<" % "<<num2<<" = "<<num1 % num2<<'\n';
    return 0;
}  
