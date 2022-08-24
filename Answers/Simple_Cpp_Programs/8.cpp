// C++ Program For Calculate Percentage Of 5 Subjects
#include<iostream>
using namespace std;
int main()
{
    int marks[5], i;
    float sum = 0;
    float avg ;
    float perc;
    cout << "Enter marks obtained in five subjects : \n";
    for(i=0; i<5; i++)
    {
        cout << "Enter marks" << i+1 << " : ";
        cin >> marks[i];
        sum = sum + marks[i];
    }
    avg = sum/5;
    perc = (sum/500)*100;
    cout << "\nAverage Marks of 5 Subjects = " << avg;
    cout << "\nPercentage in 5 Subjects = " << perc;
}