// WAP to Implement the Operator Overloading Concept of C++ Programming to take the Information from the User and Display Er. First_Name and Last_Name


#include <iostream>
#include <string.h>
using namespace std;

class AddString 
{
    public:
        char s1[25], s2[25], s3[25];

    AddString(char str1[], char str2[], char str3[])
    {
        strcpy(this->s1, str1);
        strcpy(this->s2, str2);
        strcpy(this->s3, str3);
    }

    void operator+()
    {
        strcat(s3, s1);
        cout << "\nConcatenation: " << strcat(s3, s2);
    }
};

int main()
{
	char str1[20], str2[20], str3[] = "Er.";

    cout << "Enter your first and last name : ";
    cin >> str1 >> str2;

	AddString a1(str1, str2, str3);
	+a1;
}
