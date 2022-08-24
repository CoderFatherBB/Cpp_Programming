// WAP to add modify delete and view following information(also store data in file and fetch next time)
// 	Computer Details: Type - Desktop/Laptop,processor,RAM, harddisk, usb port count, hdmi port count, battery backup time
// 	Purchase Details: person name, company name, mobile, contact person, email, mobile, Computer Details, date, quantity

#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
class Info
{
    public:
        char comp_type[10], processor_type[10];
        int ram, hard_disk, USB_count, HDMI_count, Battery_time;
};
class Detail : public Info
{
    public:
        char person_name[30], email[50], mobile[10], date[10];
    
}D[100];
int main ()
{
    int i,ch;
    char name[30];
    ofstream file;
    file.open ("codebind.txt");

    for (i = 0; i < 2; i++) // change the for loop accouding the number of entries -> i < n
    {
        cout << "\n\nEnter your name : ";
        cin >> D[i].person_name;
        cout << "Your email ID : ";
        cin >> D[i].email;
        cout << "Enter your mobile : ";
        cin >> D[i].mobile;
        cout << "Enter today's date : ";
        cin >> D[i].date;
        cout << "\nEnter your computer type : ";
        cin >> D[i].comp_type;
        cout << "Enter your processor type : ";
        cin >> D[i].processor_type;
        cout << "Enter your RAM : ";
        cin >> D[i].ram;
        cout << "Enter your Hard disk : ";
        cin >> D[i].hard_disk;
        cout << "Enter your USB port count : ";
        cin >> D[i].USB_count;
        cout << "Enter your HDMI port count : ";
        cin >> D[i].HDMI_count;
        cout << "Enter your Battery life time : ";
        cin >> D[i].Battery_time;
    }
    cout << "What do you want to do : " << "\n1. Print data" << "\n2. Update data" << "\n :";
    cin >> ch;
    switch(ch)
    {
    case 1:
        cout << "\nWho's data u want to print : ";
        cin >> name;
        for (i = 0; i < 2; i++) // change the for loop accouding the number of entries -> i < n
        {
            if (strcmp(name, D[i].person_name) == 0)
            {
                cout << "\n\nYour name : " << D[i].person_name;
                cout << "\nYour email ID : " << D[i].email;
                cout << "\nYour mobile number : " << D[i].mobile;
                cout << "\nToday's date : " << D[i].date;
                cout << "\n\nYour computer type : " << D[i].comp_type;
                cout << "\nYour processor type : " << D[i].processor_type;
                cout << "\nYour RAM : " << D[i].ram;
                cout << "\nYour Hard disk : " << D[i].hard_disk;
                cout << "\nYour USB port count : " << D[i].USB_count;
                cout << "\nYour HDMI port count : " << D[i].HDMI_count;
                cout << "\nYour Battery life time : " << D[i].Battery_time;
            }
        }
    break;
    case 2:
        cout << "\nWho's data u would like to change : "; // only mobile number can be changed for now
        cin >> name;
        for (i = 0; i < 2; i++) // change the for loop accouding the number of entries -> i < n
        {
            if (strcmp(name, D[i].person_name) == 0)
            {
                cout << "Enter new mobile : ";
                cin >> D[i].mobile;
                cout << "\n\nYour name : " << D[i].person_name;
                cout << "\nYour email ID : " << D[i].email;
                cout << "\nYour mobile number : " << D[i].mobile;
                cout << "\nToday's date : " << D[i].date;
                cout << "\n\nYour computer type : " << D[i].comp_type;
                cout << "\nYour processor type : " << D[i].processor_type;
                cout << "\nYour RAM : " << D[i].ram;
                cout << "\nYour Hard disk : " << D[i].hard_disk;
                cout << "\nYour USB port count : " << D[i].USB_count;
                cout << "\nYour HDMI port count : " << D[i].HDMI_count;
                cout << "\nYour Battery life time : " << D[i].Battery_time;
            }
        }
    }
    for (i = 0; i < 2; i++) // change the for loop accouding the number of entries -> i < n
    {
        file << "\n\nYour name : " << D[i].person_name;
        file << "\nYour email ID : " << D[i].email;
        file << "\nYour mobile number : " << D[i].mobile;
        file << "\nToday's date : " << D[i].date;
        file << "\n\nYour computer type : " << D[i].comp_type;
        file << "\nYour processor type : " << D[i].processor_type;
        file << "\nYour RAM : " << D[i].ram;
        file << "\nYour Hard disk : " << D[i].hard_disk;
        file << "\nYour USB port count : " << D[i].USB_count;
        file << "\nYour HDMI port count : " << D[i].HDMI_count;
        file << "\nYour Battery life time : " << D[i].Battery_time;
    }
    file.close ();
}