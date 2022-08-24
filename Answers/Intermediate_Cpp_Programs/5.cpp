// WAP to Insert the Information from the User and Display the Student Information in the Library using Multiple/ Multi-Level Inheritance Concept of C++ Programming. 
// 	Book Information: Book_Name, Author_Name, Publication, Number of Copies 
// 	Library Information: Name, Qualification, Experience,
// 	Students Information: Student_Name, Department, Class, Division, Book
// 	Issue Information: Book_issue, Book_details, Student Information

#include<iostream>
#include<fstream>
using namespace std;
class librarian_info
{
    public:
        char name[20];
        char qualification[10];
        unsigned int experience;
};
class student_info
{
    public:
        char student_name[20];
        char department[30];
        char std[10];
        char division;
};
class book_info
{
    public:
        char book_name[20];
        char author[20];
        char publication[20];
        unsigned int copies;
}B[10];
class student_book_info : public student_info, public book_info
{
    public:
        char date_taken[15], date_givenBack[15];
        char damage[30];
    student_book_info()
    {
        char damage[30] = {"N0"};
    }
};
class library_info : public student_book_info, public librarian_info
{ }AL[100];
int main()
{
    int i,j;
    for (i = 0; i < 1; i++) // change the for loop accouding the number of entries -> i < n
    {
        cout << "\n----------------Librarian Info----------------" << endl;
        cout << "Enter name of librarian : ";
        cin >> AL[i].name;
        cout << "Enter qualification of librarian : ";
        cin >> AL[i].qualification;
        cout << "Enter experience of librarian : ";
        cin >> AL[i].experience;
        cout << "\n----------------Student Info----------------" << endl;
        cout << "Enter name of student : ";
        cin >> AL[i].student_name;
        cout << "Enter department of student : ";
        cin >> AL[i].department;
        cout << "Enter class of student : ";
        cin >> AL[i].std;
        cout << "Enter division of student : ";
        cin >> AL[i].division;
        for (j = 0; j < 2; j++) // change the for loop accouding the number of entries -> i < n
        {
            cout << "\n----------------Book Info " << j + 1 <<"----------------" << endl;
            cout << "Enter name of book : ";
            cin >> B[j].book_name;
            cout << "Enter author of book : ";
            cin >> B[j].author;
            cout << "Enter publication of book : ";
            cin >> B[j].publication;
            cout << "Enter numner of copies : ";
            cin >> B[j].copies;
        }
        cout << "\n----------------Student Book Info----------------" << endl;
        cout << "Enter date of book take : ";
        cin >> AL[i].date_taken;
        cout << "Enter date of book given back : ";
        cin >> AL[i].date_givenBack;
        cout << "Enter YES for damage book or NO : ";
        cin >> AL[i].damage;
    }
    for (i = 0; i < 1; i++) // change the for loop accouding the number of entries -> i < n
    {
        cout << "\n\n----------------Librarian Info----------------" << endl;
        cout << "\nName of librarian : " << AL[i].name;
        cout << "\nQualification of librarian : " << AL[i].qualification;
        cout << "\nExperience of librarian : " << AL[i].experience;
        cout << "\n\n----------------Student Info----------------" << endl;
        cout << "\nName of student : " << AL[i].student_name;
        cout << "\nDepartment of student : " << AL[i].department;
        cout << "\nClass of student : " << AL[i].std;
        cout << "\nDivision of student : " << AL[i].division;
        for (j = 0; j < 2; j++) // change the for loop accouding the number of entries -> i < n
        {
            cout << "\n----------------Book Info----------------" << endl;
            cout << "\nName of book : " << B[j].book_name;
            cout << "\nAuthor of book : " << B[j].author;
            cout << "\nPublication of book : " << B[j].publication;
            cout << "\nNumner of copies : " << B[j].copies;
        }
        cout << "\n\n----------------Student Book Info----------------" << endl;
        cout << "\nDate of book take : " << AL[i].date_taken;
        cout << "\nDate of book given back : " << AL[i].date_givenBack;;
        cout << "\nDamaged book : " << AL[i].damage;
    }
}