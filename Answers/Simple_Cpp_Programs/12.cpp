// C++ Program To Find Character Is Vowel Or Not
#include<iostream>
using namespace std;
int main()
{
    char c;
    cout << "Enter a character : ";
    cin >> c;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        cout << "The entered character is a vowel\n";
    }
    else
    {
        cout << "The entered character is not vowel\n";
    }
}