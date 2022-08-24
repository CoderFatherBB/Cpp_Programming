// WAP to Display Shopping Information in the which the contents are Person_Name,Cloth_Type,
// Cloth_Size, Cloth _Color, using Class and Object Concept of C++ Programming

#include <iostream>
#include <string.h>
using namespace std;
class Cloth
{
    public:
        char name[20];
        char size[5];
        char type[15];
        char color[10];
}obj[5];
int main()
{
    int i;
    for(i = 0; i < 2; i++)
    {
        cout << "\nEnter your name: ";
        cin >> obj[i].name;
        cout << "Enter size of cloth: ";
        cin >> obj[i].size;
        cout << "Enter type of cloth: ";
        cin >> obj[i].type;
        cout << "Enter color of cloth: ";
        cin >> obj[i].color;
    }
    for(i = 0; i < 2; i++)
    {
        cout << "\n\nName  : " << obj[i].name;
        cout << "\nSize  : " << obj[i].size;
        cout << "\nType  : " << obj[i].type;
        cout << "\nColor : " << obj[i].color;
    }
}