// Write a C++ program to calculate the area of triangle, rectangle and circle using Constructor overloading. 
// The program should be menu driven.

#include <iostream>
#include <math.h>
using namespace std;

class AreaShape
{
    float area;
    public:
        AreaShape(int length, int breadth)
        {
            area = length * breadth;
        }
        AreaShape(float base, float height)
        {
            area = 0.5 * (base * height);
        }
        void display()
        {
            cout << "Area : " << area << endl;
        }
        AreaShape(float radius)
        {
            area = 3.14 * radius * radius;
        }
};
int main()
{
    int ch;
    
    cout << "Enter : \n1. Rectangle \n2. Triangle \n3. Circle \n : ";
    cin >> ch;

    switch (ch)
    {
        case 1:
        {
            int length, breadth;
            cout << "Enter Length and Breadth of the Rectangle : ";
            cin >> length >> breadth;
            AreaShape area(length, breadth);
            area.display();
        }
        break;

        case 2:
        {
            float  height, base;
            cout << "Enter Base and Height of the Triangle : ";
            cin >> base >> height;
            AreaShape area(base, height);
            area.display();
        }
        break;

        case 3:
        {
            float radius;
            cout << "Enter Radius of the Circle : ";
            cin >> radius;
            AreaShape area(radius);
            area.display();
        }
        break;

        default:
            cout << "Invalid Choice";
        break;
    }
}