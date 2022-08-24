// WAP to add modify delete and view following information(also store data in file and fetch next time) 
// vehicle information ,name,type,company name,capacity in cc, milage (CPP + File Handling)

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Vehicle
{
    private:
        char person_name[50], company_name[10];
        int capacity, milage, type;

    public:
        void set_person_name(char* p)
        {
            strcpy(person_name, p);
        }
        void set_company_name(char* n)
        {
            strcpy(company_name, n);
        }
        void set_capcity(int c)
        {
            capacity = c;
        }
        void set_milage(int m)
        {
            milage = m;
        }
        void set_type(int t)
        {
            type = t;
        }
        
        char* get_person_name()
        {
            return person_name;
        }
        char* get_company_name()
        {
            return company_name;
        }
        int get_capacity()
        {
            return capacity;
        }
        int get_milage()
        {
            return milage;
        }
        int get_type()
        {
            return type;
        }
}V[100];
int main()
{
    int i, ch, ch1;
    char person_name[50][4], company_name[10], str[50];
    int capacity, milage, type;
    ofstream file;
    file.open ("Info_cpp.txt");
    for (i = 0; i < 2; i++) // change the for loop accouding the number of entries -> i < n
    {
        cout << "\nEnter your name : ";
        cin >> person_name[i];
        V[i].set_person_name(person_name[i]);
        cout << "\nEnter your Vehicle's name : ";
        cin >> company_name;
        V[i].set_company_name(company_name);
        cout << "Enter your Vehicle's type (2 , 4) : ";
        cin >> type;
        V[i].set_type(type);
        cout << "Enter your Vehicle's capacity in cc : ";
        cin >> capacity;
        V[i].set_capcity(capacity);
        cout << "Enter your Vehicle's milage : ";
        cin >> milage;
        V[i].set_milage(milage);
    }
while (1)
{
    cout << "\nWhat do you want to do : " << "\n1. Update data" << "\n2. Print data in file" << "\n :";
    cin >> ch;
    switch(ch)
    {
        case 1:
            cout << "\nWho's data u would like to Update : ";
            cin >> str;
            for (i = 0; i < 2; i++) // change the for loop accouding the number of entries -> i < n
            {
                if (strcmp(str, person_name[i]) == 0)
                {
                    cout << "What would you like to update : \n1. Person Name \n2. Company Name \n3. Vehicle Type \n4. Capacity \n5. Milage \n :";
                    cin >> ch1;
                    if (ch1 == 1)
                    {
                        cout << "\nEnter your name : ";
                        cin >> person_name[i];
                        V[i].set_person_name(person_name[i]);
                    }
                    else if (ch1 == 2)
                    {
                        cout << "\nEnter your Vehicle's name : ";
                        cin >> company_name;
                        V[i].set_company_name(company_name);
                    }
                    else if (ch1 == 3)
                    {
                        cout << "Enter your Vehicle's type (2 , 4) : ";
                        cin >> type;
                        V[i].set_type(type);
                    }
                    else if (ch1 == 4)
                    {
                        cout << "Enter your Vehicle's capacity in cc : ";
                        cin >> capacity;
                        V[i].set_capcity(capacity);
                    }
                    else if (ch1 == 5)
                    {
                        cout << "Enter your Vehicle's milage : ";
                        cin >> milage;
                        V[i].set_milage(milage);
                    }
                    else
                        cout << "Wrong Input";
                }
            }
        break;

        case 2:
            for (i = 0; i < 2; i++) // change the for loop accouding the number of entries -> i < n
            {
                file << "\n\nYour name : " << V[i].get_person_name();
                file << "\n\nYour Vehicle's name : " << V[i].get_company_name();
                file << "\nYour Vehicle's type : " << V[i].get_type();
                file << "\nYour Vehicle's capacity in cc : " << V[i].get_capacity();
                file << "\nYour Vehicle's milage : " << V[i].get_milage();
            }
            file.close();
        break;
    }
}
}