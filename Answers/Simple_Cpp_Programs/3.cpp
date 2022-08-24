// C++ Program To Find Area Of Triangle
#include<iostream>
using namespace std;
int main()
{
    float length, breath, area;
    cout << "Enter lenght and breath of triangle : ";
    cin >> length >> breath;
    // Area of Triangle = 1/2 x Lenght x Breath
    area = (0.5 * (length * breath));
    cout << "Area of triangle : " << area << endl;
}