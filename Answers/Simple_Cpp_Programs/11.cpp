// C++ Program To Check Number Is Positive Or Negative
#include<iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter any number : ";
    cin >> num;
    //Conditions to check if the number is negative or positive
    if (num > 0)
    cout << "The number is positive";
    else if (num < 0)
    cout << "The number is negative";
    else
    cout << "Zero";
}