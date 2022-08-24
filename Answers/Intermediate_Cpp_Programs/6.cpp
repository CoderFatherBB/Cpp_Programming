// Write a C++ program to calculate the area of triangle, rectangle and circle using function overloading. 
// The program should be menu driven.

#include <iostream>
using namespace std;

int area (int a, int b)
{
    int area = a*b; 
    return area;
}
float area (float a, float b)
{
    float area = 0.5*a*b;
    return area;
}
float area (int r)
{
    float area = 3.14*r*r;
    return area;
}
int main()
{
    int ch;
    cout << "Enter : \n1. Rectangle \n2. Triangle \n3. Circle \n : ";
    cin >> ch;
    switch(ch)
    {
        case 1:
            int lenght, breath, a;
            cout << "Enter lenght and breath : ";
            cin >> lenght >> breath;
            a = area(lenght,breath);
            cout << "Area : " << a;
        break;
        
        case 2:
            float base, height, b;
            cout << "Enter base and height : ";
            cin >> base>> height;
            b = area(base, height);
            cout << "Area : " << b;
        break;
        
        case 3:
            int radius;
            float c;
            cout << "Enter radius : ";
            cin >> radius;
            c = area(radius);
            cout << "Area : " << c;
        break;
        
        default :
            cout << "Wrong intput : ";
        break;
    }
}