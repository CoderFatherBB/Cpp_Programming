// C++ Program To Find The Address Of Variable
#include<iostream>
using namespace std;
int main()
{
    int first,sec;
    cout << "Enter The Value Of First and Second Variable : ";
    cin >> first >> sec;
    cout << "Address Of First Variable :";
    cout << &first <<"\n";
    cout << "Address Of Second Variable : ";
    cout << &sec << endl;
}