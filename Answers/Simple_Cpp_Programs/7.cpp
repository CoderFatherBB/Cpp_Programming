// C++ Program To Find The Gross Salary Of An Employee
#include<iostream>
using namespace std;
int main()
{
    float GrossPayment ,basic ,da ,hra, da1, hra1;
    cout << "Enter basic salary : ";
    cin >> basic;
    cout << "Enter DA : ";
    cin >> da1;
    cout << "Enter HRA : ";
    cin >> hra1;
    da = (da1 * basic) / 100;
    hra = (hra1 * basic) / 100;
    GrossPayment = basic + da + hra;
    cout << "\nGross Salary : " << GrossPayment << endl;
}