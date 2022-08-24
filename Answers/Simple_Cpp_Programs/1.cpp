// C++ Program To Find Area And Circumference Of Circle
#include <iostream>
using namespace std;
#define PI 3.142
int main()
{
    float radius, area, circumference;
    cout << "Enter radius of circle : ";
    cin >> radius;
    // Area of Circle = PI x Radius X Radius
    area = (PI * (radius * radius));
    circumference = (2 * (PI * radius));
    cout << "Area of circle : " << area << endl;
    cout << "Circumference of circle : " << circumference;
}