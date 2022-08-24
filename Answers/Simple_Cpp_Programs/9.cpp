// C++ Program For Converting Temperature Celsius Into Fahrenheit
#include<iostream>
using namespace std;
int main()
{
    float celsius, fahrenheit;
    cout << "Enter the Temperature in Celsius : ";
    cin >> celsius;
    fahrenheit = (celsius*1.8)+32;
    cout << "\nEquivalent Temperature in Fahrenheit : " << fahrenheit;
}