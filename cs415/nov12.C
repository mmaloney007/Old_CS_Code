//vic maloney assignment 12
/*This program takes input of a test type and a number then returns the answer  if the test was succesfully in the boundry of the numbers.  The normal range fortest A is 100.3 to 124.5, while B is below 75.0, and any value about 103.6 is   normal for C.  The program will take a test type and number then tell you if theresults are normal or not.*/

#include <iostream.h>

void doTests();

void printResults(char, float);

int main()
{
    int patient;
    cin >> patient;
    while (patient > 0){
    cout << "patient " << patient << '\n';
    doTests();
    cin >> patient;
    }
    return 0;    
}
void doTests()
{
    int patient;
    char ch;
    float num;
    cin >> ch;
    while (ch >= 'A' && ch <= 'C'){
        cin >> num;
        printResults(ch, num);
        cin >> ch;
   }
}
void printResults(char ch,float num)
{
    cout << "  test " << ch << '\n';
    cout << "     value = " << num << '\n';
    if (ch == 'A'){
        if (num >= 100.3 && num <= 124.5)
        cout << "     within normal range" << '\n' << '\n';
        else 
        cout << "     NOT normal" << '\n' << '\n';
        }
    else if (ch == 'B'){
        if (num < 75.0)
        cout << "     within normal range"  << '\n' << '\n';
        else
        cout << "     NOT normal" << '\n' << '\n';
        }
    else {
        if (num > 103.6)
        cout << "     within normal range" << '\n' << '\n';
        else
        cout << "     NOT normal" << '\n' << '\n';
        }
}
