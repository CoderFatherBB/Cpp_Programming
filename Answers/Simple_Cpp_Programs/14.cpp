// C++ Program To Read Integer (N) And Print First Three Powers (N^1, N^2, N^3)
#include<iostream>
using namespace std;
int main()
{
    int num;
    cout << "\nEnter The Number : ";
    cin >> num;
    cout << "\nOutpout is :\n";
    cout << num << " ," << num*num << " ," << num*num*num <<endl;
}