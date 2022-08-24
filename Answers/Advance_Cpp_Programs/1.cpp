#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<cstdio>
using namespace std;
class vehicle
{
    private:
    char name[20], type[10], comname[20];
    int capacity, milage; 

    public:
    void setdata(char *n, char *t, char *cn, int c, int m)
    {
        strcpy(name,n);
        strcpy(type,t);
        strcpy(comname,cn);
        capacity=c;
        milage=m;
    }
    char *getName()
    {
        return name;
    }
    char *getType()
    {
        return type;
    }
    char *getCompany()
    {
        return comname;
    }
    int getCapacity()
    {
        return capacity;
    }
    int getMilage()
    {
        return milage;
    }
}obj[10];

int main()
{
    char name[20], type[10], comname[20], change[25];
    int capacity, milage;
    int i,n,m,a,x=1;
    int num,opt,count=0;
    string temp;

    fstream myFile;
    myFile.open("vehicle.txt", ios::app);
    if(!myFile.eof())
    {
        cout<<"File opened successfully\n";
        cout<<"\nEnter the number of vehicles: ";
        cin>>n; 
        for(i=0;i<n;i++)
        {
            cout<<"\nEnter name: ";
            cin>>name;
            cout<<"Enter type of vehicle(Two or Four): ";
            cin>>type;
            cout<<"Enter name of company: ";
            cin>>comname;
            cout<<"Enter capacity in cc: ";
            cin>>capacity;
            cout<<"Enter milage: ";
            cin>>milage;
            obj[i].setdata(name,type,comname,capacity,milage);
        }
        for(i=0;i<n;i++)
        {
            myFile<<obj[i].getName()<<","<<obj[i].getType()<<","<<obj[i].getCompany()<<","<<obj[i].getCapacity()<<","<<obj[i].getMilage()<<"\n";
        }
    }

    else
    {
        exit(0);
    }    
    myFile.close();

    do
    {    
        cout<<"\nWhat do you want to do?\n";
        cout<<"\nEnter\n 1 to Add data\n 2 to View data\n 3 to Modify data\n 4 to Delete data\n ";
        cin>>a;

        if(a==1)
        {
            myFile.open("vehicle.txt", ios::app);
            if(!myFile.eof())
            {
                cout<<"\nHow many vehicles do you want to add: ";
                cin>>m;
                if(n+m<10)
                {
                    for(i=n;i<n+m;i++)
                    {
                        cout<<"\nEnter name: ";
                        cin>>name;
                        cout<<"Enter type of vehicle(Two or Four): ";
                        cin>>type;
                        cout<<"Enter name of company: ";
                        cin>>comname;
                        cout<<"Enter capacity in cc: ";
                        cin>>capacity;
                        cout<<"Enter milage: ";
                        cin>>milage;
                        obj[i].setdata(name,type,comname,capacity,milage);
                    }
                    for(i=n;i<n+m;i++)
                    {
                        myFile<<obj[i].getName()<<","<<obj[i].getType()<<","<<obj[i].getCompany()<<","<<obj[i].getCapacity()<<","<<obj[i].getMilage()<<"\n";
                    }
                }
            }
            else
            {
                exit(0);
            }        
            myFile.close();
        }    

        else if(a==2)
        {
            myFile.open("vehicle.txt", ios::in);
            if(!myFile.eof())
            {
                cout<<"\nThe file contents are:\n";
                while (!myFile.eof())
                {
                    getline(myFile,temp);
                    cout<< temp <<"\n";
                }
            }
            else
            {
                exit(0);
            }   
            myFile.close();
        }

        else if(a==3)
        {
            cout<<"Enter the record no. whose details are to be modified: ";
            cin>>num;
            count=0;
            myFile.open("vehicle.txt", ios::in);
            i = 1;
            while (!myFile.eof() && i <= 10)
            {
                getline(myFile, temp, ',');
                strcpy(name, temp.c_str());
                getline(myFile, temp, ',');
                strcpy(type, temp.c_str());
                getline(myFile, temp, ',');
                strcpy(comname, temp.c_str());
                getline(myFile, temp, ',');
                capacity = atoi(temp.c_str());
                getline(myFile, temp, '\n');
                milage = atoi(temp.c_str());
                obj[i].setdata(name, type, comname, capacity, milage);
                i++;
                count++;
            }
            myFile.close();

            fstream file;
            file.open("temp.txt", ios::app);
            i=1;
            while(i<count)
            {
                if(i==num)
                {
                    cout<<"What do you want to modify?\nEnter\n 1 Name\n 2 Type\n 3 Company\n 4 Capacity\n 5 Milage\n ";
                    cin>>opt;
                    cout<<"Enter the change: ";
                    cin>>change;
                    if(opt==1)
                    {
                        file<<change<<","<<obj[i].getType()<<","<<obj[i].getCompany()<<","<<obj[i].getCapacity()<<","<<obj[i].getMilage()<<"\n";
                    }
                    else if(opt==2)
                    {
                        file<<obj[i].getName()<<","<<change<<","<<obj[i].getCompany()<<","<<obj[i].getCapacity()<<","<<obj[i].getMilage()<<"\n";
                    }
                    else if(opt==3)
                    {
                        file<<obj[i].getName()<<","<<obj[i].getType()<<","<<change<<","<<obj[i].getCapacity()<<","<<obj[i].getMilage()<<"\n";
                    }
                    else if(opt==4)
                    {
                        file<<obj[i].getName()<<","<<obj[i].getType()<<","<<obj[i].getCompany()<<","<<change<<","<<obj[i].getMilage()<<"\n";
                    }
                    else if(opt==5)
                    {
                        file<<obj[i].getName()<<","<<obj[i].getType()<<","<<obj[i].getCompany()<<","<<obj[i].getCapacity()<<","<<change<<"\n";
                    }
                    else 
                    {
                        cout<<"Invalid Input";
                        file<<obj[i].getName()<<","<<obj[i].getType()<<","<<obj[i].getCompany()<<","<<obj[i].getCapacity()<<","<<obj[i].getMilage()<<"\n";
                    }
                } 
                else
                {
                    file<<obj[i].getName()<<","<<obj[i].getType()<<","<<obj[i].getCompany()<<","<<obj[i].getCapacity()<<","<<obj[i].getMilage()<<"\n";
                }
                i++;   
            }
            file.close();
            remove("vehicle.txt");
            rename("temp.txt", "vehicle.txt");
        }

        else if(a==4)
        {
            cout<<"Enter the record number whose details you want to delete: ";
            cin>>num;
            myFile.open("vehicle.txt", ios::in);
            i = 1;
            count=0;
            while (!myFile.eof() && i <= 10)
            {
                getline(myFile, temp, ',');
                strcpy(name, temp.c_str());
                getline(myFile, temp, ',');
                strcpy(type, temp.c_str());
                getline(myFile, temp, ',');
                strcpy(comname, temp.c_str());
                getline(myFile, temp, ',');
                capacity = atoi(temp.c_str());
                getline(myFile, temp, '\n');
                milage = atoi(temp.c_str());
                obj[i].setdata(name, type, comname, capacity, milage);                
                i++;
                count++;
            }
            myFile.close();
            
            fstream file;
            file.open("temp.txt", ios::app);
            i=1;
            while(i<count)
            {
                if(i==num)
                {
                    i++;
                }
                else
                {
                    file<<obj[i].getName()<<","<<obj[i].getType()<<","<<obj[i].getCompany()<<","<<obj[i].getCapacity()<<","<<obj[i].getMilage()<<"\n";
                    i++;
                }
            }
            file.close();
            remove("vehicle.txt");
            rename("temp.txt", "vehicle.txt");
        }

        cout<<"\nDo you want to do anything else?\nEnter (1/0): ";
        cin>>x;
    }
    while(x==1);
    return 0;
}