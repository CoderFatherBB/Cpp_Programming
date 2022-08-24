#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <cstdio>
using namespace std;
class computer
{
    private:
    char type[10], pro[5];
    int ram, hdisk, usb, hdmi, time;

    public:
    void setdata(char *ty, char *p, int r, int hd, int u, int h, int t)
    {
        strcpy(type, ty);
        strcpy(pro, p);
        ram = r;
        hdisk = hd;
        usb = u;
        hdmi = h;
        time = t;
    }
    char *getType()
    {
	    return type;
    }
    char *getProcessor()
    {
	    return pro;
    }
    int getRam()
    {
	    return ram;
    }
    int getHarddisk()
    {
	    return hdisk;
    }
    int getUsb()
    {
	    return usb;
    }
    int getHdmi()
    {
	    return hdmi;
    }
    int getTime()
    {
	    return time;
    }
}obj1[10];

class person : public computer
{
    private:
    char name[30], mobile[15], email[50], date[15];

    public:
    void setdata(char *n, char *m, char *em, char *d)
    {
        strcpy(name,n);
        strcpy(mobile,m);
        strcpy(email,em);
        strcpy(date,d);
    }
    char *getName()
    {
	    return name;
    }
    char *getMobile()
    {
	    return mobile;
    }
    char *getEmail()
    {
	    return email;
    }
    char *getDate()
    {
	    return date;
    }
}obj2[10];

class company : public computer
{
    private:
    char compname[40], pername[30], mobile[15], email[50], date[15];
    int quantity;

    public:
    void setdata(char *cn, char *pn, char *m, char *em, char *d, int q)
    {
        strcpy(compname,cn);
        strcpy(pername, pn);
        strcpy(mobile,m);
        strcpy(email,em);
        strcpy(date,d);
        quantity = q;
    }
    char *getCompname()
    {
	    return compname;
    }
    char *getPername()
    {
	    return pername;
    }
    char *getMobile()
    {
	    return mobile;
    }
    char *getEmail()
    {
	    return email;
    }
    char *getDate()
    {
	    return date;
    }
    int getQuantity()
    {
	    return quantity;
    }
}obj3[10];

int main()
{
    char type[10], pro[5], name[30], mobile[15], email[50], date[15], compname[40], pername[30], change[40];
    int ram, hdisk, usb, hdmi, time, quantity;
    int i,c,a,n,m,x;
    int num,opt,count=0;
    string temp, t1[10];
    
    fstream myFile;
    myFile.open("computer.txt", ios::app);
    if(!myFile.eof())
    {
        cout<<"File opened successfully\n";
        cout<<"Enter the number of entries: ";
        cin>>n;
        for(i=0;i<n;i++)
        {
            cout<<"\nYou are purchasing as an individual or a company?\n";
            cout<<"Enter\n1 for Individual\n2 for Company\n";
            cin>>c;
            if(c==1)
            {
                cout<<"Enter name: ";
                cin>>name;
                cout<<"Enter mobile: ";
                cin>>mobile;
                cout<<"Enter email: ";
                cin>>email;
                cout<<"Enter date: ";
                cin>>date;
            }
            if(c==2)
            {
                cout<<"Enter name of company: ";
                cin>>compname;
                cout<<"Enter name of person: ";
                cin>>pername;
                cout<<"Enter mobile: ";
                cin>>mobile;
                cout<<"Enter email: ";
                cin>>email;
                cout<<"Enter quantity: ";
                cin>>quantity;
                cout<<"Enter date: ";
                cin>>date;
            }
            cout<<"\nEnter type(Laptop or Desktop): ";
            cin>>type;
            cout<<"Enter processor: ";
            cin>>pro;
            cout<<"Enter ram in GB: ";
            cin>>ram;
            cout<<"Enter harddisk in TB: ";
            cin>>hdisk;
            cout<<"Enter no. of usb ports: ";
            cin>>usb;
            cout<<"Enter no. of hdmi ports: ";
            cin>>hdmi;
            if(strcmp(strupr(type),"LAPTOP")==0)
            {
                cout<<"Enter battery backup time(in hours): ";
                cin>>time;
            }
            obj1[i].setdata(type, pro, ram, hdisk, usb, hdmi, time);
            obj2[i].setdata(name, mobile, email, date);
            obj3[i].setdata(compname,pername,mobile,email,date,quantity);
            
            if(c==1 && strcmp(strupr(type),"LAPTOP")==0)
            {
                myFile<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
            }
            else if(c==1 && strcmp(strupr(type),"LAPTOP")!=0)
            {
                myFile<<"B,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";        
            }
            else if(c==2 && strcmp(strupr(type),"LAPTOP")==0)
            {
                myFile<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
            }    
            else if(c==2 && strcmp(strupr(type),"LAPTOP")!=0)
            {
                myFile<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n"; 
            }
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
        cout<<"Enter\n 1 to Add data\n 2 to View data\n 3 to Modify data\n 4 to Delete data\n ";
        cin>>a;

        if(a==1)
        {
            myFile.open("computer.txt", ios::app);
            if(!myFile.eof())
            {
                cout<<"Enter the number of entries you want to add: ";
                cin>>m;
                if(n+m<10)
                {
                    for(i=n;i<n+m;i++)
                    {
                        cout<<"\nYou are purchasing as an individual or a company?\n";
                        cout<<"Enter\n1 for Individual\n2 for Company\n";
                        cin>>c;
                        if(c==1)
                        {
                            cout<<"Enter name: ";
                            cin>>name;
                            cout<<"Enter mobile: ";
                            cin>>mobile;
                            cout<<"Enter email: ";
                            cin>>email;
                            cout<<"Enter date: ";
                            cin>>date;
                        }
                        if(c==2)
                        {
                            cout<<"Enter name of company: ";
                            cin>>compname;
                            cout<<"Enter name of person: ";
                            cin>>pername;
                            cout<<"Enter mobile: ";
                            cin>>mobile;
                            cout<<"Enter email: ";
                            cin>>email;
                            cout<<"Enter quantity: ";
                            cin>>quantity;
                            cout<<"Enter date: ";
                            cin>>date;
                        }
                        cout<<"\nEnter type(Laptop or Desktop): ";
                        cin>>type;
                        cout<<"Enter processor: ";
                        cin>>pro;
                        cout<<"Enter ram in GB: ";
                        cin>>ram;
                        cout<<"Enter harddisk in TB: ";
                        cin>>hdisk;
                        cout<<"Enter no. of usb ports: ";
                        cin>>usb;
                        cout<<"Enter no. of hdmi ports: ";
                        cin>>hdmi;
                        if(strcmp(strupr(type),"LAPTOP")==0)
                        {
                            cout<<"Enter battery backup time(in hours): ";
                            cin>>time;
                        }
                        obj1[i].setdata(type, pro, ram, hdisk, usb, hdmi, time);
                        obj2[i].setdata(name, mobile, email, date);
                        obj3[i].setdata(compname,pername,mobile,email,date,quantity);
                        
                        if(c==1 && strcmp(strupr(type),"LAPTOP")==0)
                        {
                            myFile<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(c==1 && strcmp(strupr(type),"LAPTOP")!=0)
                        {
                            myFile<<"B,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";        
                        }
                        else if(c==2 && strcmp(strupr(type),"LAPTOP")==0)
                        {
                            myFile<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }    
                        else if(c==2 && strcmp(strupr(type),"LAPTOP")!=0)
                        {
                            myFile<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n"; 
                        }
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
            myFile.open("computer.txt", ios::in);
            cout<<"\nThe file contents are:\n";
            i=1;
                while (!myFile.eof() && i<=10)
                {
                    getline(myFile, t1[i], ',');
                    if(strcmp(t1[i].c_str(),"A")==0)
                    {
                        getline(myFile,temp,'\n');
                        cout<<"Personal Laptop"<<","<<temp<<"\n";
                    }
                    else if(strcmp(t1[i].c_str(),"B")==0)
                    {
                        getline(myFile,temp,'\n');
                        cout<<"Personal Desktop"<<","<<temp<<"\n";
                    }
                    else if(strcmp(t1[i].c_str(),"C")==0)
                    {
                        getline(myFile,temp,'\n');
                        cout<<"Company Laptop"<<","<<temp<<"\n";
                    }
                    else if(strcmp(t1[i].c_str(),"D")==0)
                    {
                        getline(myFile,temp,'\n');
                        cout<<"Company Desktop"<<","<<temp<<"\n";
                    }
                    i++;
                }
            
              
            myFile.close();
        }

        else if(a==3)
        {        
            myFile.open("computer.txt", ios::in);
            i = 1;
            count=0;
            while(!myFile.eof() && i <= 10)
            {
                getline(myFile, t1[i], ',');
                if(strcmp(t1[i].c_str(),"A")==0)
                {
                    getline(myFile, temp, ',');
                    strcpy(name, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(mobile, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(email, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(date, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(type, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(pro, temp.c_str());
                    getline(myFile, temp, ',');
                    ram = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    hdisk = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    usb = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    hdmi = atoi(temp.c_str());
                    getline(myFile, temp, '\n');
                    time = atoi(temp.c_str());
                    obj1[i].setdata(type,pro,ram,hdisk,usb,hdmi,time);
                    obj2[i].setdata(name,mobile,email,date);
                }   
                else if(strcmp(t1[i].c_str(),"B")==0)
                {
                    getline(myFile, temp, ',');
                    strcpy(name, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(mobile, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(email, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(date, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(type, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(pro, temp.c_str());
                    getline(myFile, temp, ',');
                    ram = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    hdisk = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    usb = atoi(temp.c_str());
                    getline(myFile, temp, '\n');
                    hdmi = atoi(temp.c_str());
                    obj1[i].setdata(type,pro,ram,hdisk,usb,hdmi,0);
                    obj2[i].setdata(name,mobile,email,date);
                } 
                else if(strcmp(t1[i].c_str(),"C")==0)
                {
                    getline(myFile, temp, ',');
                    strcpy(compname, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(pername, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(mobile, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(email, temp.c_str());
                    getline(myFile, temp, ',');
                    quantity= atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(date, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(type, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(pro, temp.c_str());
                    getline(myFile, temp, ',');
                    ram = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    hdisk = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    usb = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    hdmi = atoi(temp.c_str());
                    getline(myFile, temp, '\n');
                    time = atoi(temp.c_str());
                    obj1[i].setdata(type,pro,ram,hdisk,usb,hdmi,time);
                    obj3[i].setdata(compname,pername,mobile,email,date,quantity);
                }
                else if(strcmp(t1[i].c_str(),"D")==0)
                {
                    getline(myFile, temp, ',');
                    strcpy(compname, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(pername, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(mobile, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(email, temp.c_str());
                    getline(myFile, temp, ',');
                    quantity=atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(date, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(type, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(pro, temp.c_str());
                    getline(myFile, temp, ',');
                    ram = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    hdisk = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    usb = atoi(temp.c_str());
                    getline(myFile, temp, '\n');
                    hdmi = atoi(temp.c_str());
                    obj1[i].setdata(type,pro,ram,hdisk,usb,hdmi,0);
                    obj3[i].setdata(compname,pername,mobile,email,date,quantity);
                }
                i++;
                count++;
            }
            myFile.close();

            fstream file;
            file.open("temp1.txt", ios::app);   
            cout<<"Enter the record no. whose details are to be modified: ";
            cin>>num;     
            i=1;
            while(i<count)
            {
                if(i==num)
                {
                    if(strcmp(t1[i].c_str(),"A")==0)
                    {
                        cout<<"What do you want to modify?\n";
                        cout<<"Enter\n 1 Name\n 2 Mobile\n 3 Email\n 4 Date\n 5 Type\n 6 Processor\n 7 Ram\n 8 Hard disk\n 9 Usb\n 10 Hdmi\n 11 Time\n ";
                        cin>>opt;
                        cout<<"Enter the change: ";
                        cin>>change;
                        if(opt==1)
                        {
                            file<<"A,"<<change<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==2)
                        {
                            file<<"A,"<<obj2[i].getName()<<","<<change<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==3)
                        {
                            file<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<change<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==4)
                        {
                            file<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<change<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==5)
                        {
                            file<<"B,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<change<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==6)
                        {
                            file<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<change<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==7)
                        {
                            file<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<change<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==8)
                        {
                            file<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<change<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==9)
                        {
                            file<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<change<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==10)
                        {
                            file<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<change<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==11)
                        {
                            file<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<change<<"\n";
                        }
                        else
                        {
                            cout<<"Invalid input";
                            file<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                    }
                    else if(strcmp(t1[i].c_str(),"B")==0)
                    {
                        cout<<"What do you want to modify?\n";
                        cout<<"Enter\n 1 Name\n 2 Mobile\n 3 Email\n 4 Date\n 5 Type\n 6 Processor\n 7 Ram\n 8 Hard disk\n 9 Usb\n 10 Hdmi\n  ";
                        cin>>opt;
                        cout<<"Enter the change: ";
                        cin>>change;
                        if(opt==1)
                        {
                            file<<"B,"<<change<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==2)
                        {
                            file<<"B,"<<obj2[i].getName()<<","<<change<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==3)
                        {
                            file<<"B,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<change<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==4)
                        {
                            file<<"B,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<change<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==5)
                        {
                            cout<<"Enter battery backup time(in hours): ";
                            cin>>time;
                            obj1[i].setdata(type,pro,ram,hdisk,usb,hdmi,time);
                            file<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<change<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==6)
                        {
                            file<<"B,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<change<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==7)
                        {
                            file<<"B,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<change<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==8)
                        {
                            file<<"B,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<change<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==9)
                        {
                            file<<"B,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<change<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==10)
                        {
                            file<<"B,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<change<<"\n";
                        }
                        else
                        {
                            cout<<"Invalid input";
                            file<<"B,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                    }
                    else if(strcmp(t1[i].c_str(),"C")==0)
                    {
                        cout<<"What do you want to modify?\n";
                        cout<<"Enter\n 1 Company Name\n 2 Person Name\n 3 Mobile\n 4 Email\n 5 Quantity\n 6 Date\n 7 Type\n 8 Processor\n 9 Ram\n 10 Hard disk\n 11 Usb\n 12 Hdmi\n 13 Time\n ";
                        cin>>opt;
                        cout<<"Enter the change: ";
                        cin>>change;
                        if(opt==1)
                        {
                            file<<"C,"<<change<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==2)
                        {
                            file<<"C,"<<obj3[i].getCompname()<<","<<change<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==3)
                        {
                            file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<change<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==4)
                        {
                            file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<change<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==5)
                        {
                            file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<change<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==6)
                        {
                            file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<change<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==7)
                        {
                            file<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<change<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==8)
                        {
                            file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<change<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==9)
                        {
                            file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<change<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==10)
                        {
                            file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<change<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==11)
                        {
                            file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<change<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==12)
                        {
                            file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<change<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==13)
                        {
                            file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<change<<"\n";
                        }
                        else
                        {
                            cout<<"Invalid input";
                            file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                    }
                    else if(strcmp(t1[i].c_str(),"D")==0)
                    {
                        cout<<"What do you want to modify?\n";
                        cout<<"Enter\n 1 Company Name\n 2 Person Name\n 3 Mobile\n 4 Email\n 5 Quantity\n 6 Date\n 7 Type\n 8 Processor\n 9 Ram\n 10 Hard disk\n 11 Usb\n 12 Hdmi\n  ";
                        cin>>opt;
                        cout<<"Enter the change: ";
                        cin>>change;
                        if(opt==1)
                        {
                            file<<"D,"<<change<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==2)
                        {
                            file<<"D,"<<obj3[i].getCompname()<<","<<change<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==3)
                        {
                            file<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<change<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==4)
                        {
                            file<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<change<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==5)
                        {
                            file<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<change<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==6)
                        {
                            file<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<change<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==7)
                        {
                            cout<<"Enter battery backup time(in hours): ";
                            cin>>time;
                            obj1[i].setdata(type,pro,ram,hdisk,usb,hdmi,time);
                            file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<change<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                        }
                        else if(opt==8)
                        {
                            file<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<change<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==9)
                        {
                            file<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<change<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==10)
                        {
                            file<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<change<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==11)
                        {
                            file<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<change<<","<<obj1[i].getHdmi()<<"\n";
                        }
                        else if(opt==12)
                        {
                            file<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<change<<"\n";
                        }
                        else
                        {
                            cout<<"Invalid input";
                            file<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                        }
                    }   
                    i++;             
                }
                else
                {
                    if(strcmp(t1[i].c_str(),"A")==0)
                    {
                        file<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                    }
                    else if(strcmp(t1[i].c_str(),"B")==0)
                    {
                        file<<"B,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                    }
                    else if(strcmp(t1[i].c_str(),"C")==0)
                    {
                        file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                    }
                    else if(strcmp(t1[i].c_str(),"D")==0)
                    {
                        file<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                    }
                    i++;
                }                       
            }
            file.close();
            remove("computer.txt");
            rename("temp1.txt", "computer.txt");    
        }

        else if(a==4)
        {
            myFile.open("computer.txt", ios::in);
            i = 1;
            count=0;
            while(!myFile.eof() && i <= 10)
            {
                getline(myFile, t1[i], ',');
                if(strcmp(t1[i].c_str(),"A")==0)
                {
                    getline(myFile, temp, ',');
                    strcpy(name, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(mobile, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(email, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(date, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(type, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(pro, temp.c_str());
                    getline(myFile, temp, ',');
                    ram = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    hdisk = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    usb = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    hdmi = atoi(temp.c_str());
                    getline(myFile, temp, '\n');
                    time = atoi(temp.c_str());
                    obj1[i].setdata(type,pro,ram,hdisk,usb,hdmi,time);
                    obj2[i].setdata(name,mobile,email,date);
                }   
                else if(strcmp(t1[i].c_str(),"B")==0)
                {
                    getline(myFile, temp, ',');
                    strcpy(name, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(mobile, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(email, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(date, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(type, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(pro, temp.c_str());
                    getline(myFile, temp, ',');
                    ram = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    hdisk = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    usb = atoi(temp.c_str());
                    getline(myFile, temp, '\n');
                    hdmi = atoi(temp.c_str());
                    obj1[i].setdata(type,pro,ram,hdisk,usb,hdmi,0);
                    obj2[i].setdata(name,mobile,email,date);
                } 
                else if(strcmp(t1[i].c_str(),"C")==0)
                {
                    getline(myFile, temp, ',');
                    strcpy(compname, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(pername, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(mobile, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(email, temp.c_str());
                    getline(myFile, temp, ',');
                    quantity= atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(date, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(type, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(pro, temp.c_str());
                    getline(myFile, temp, ',');
                    ram = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    hdisk = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    usb = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    hdmi = atoi(temp.c_str());
                    getline(myFile, temp, '\n');
                    time = atoi(temp.c_str());
                    obj1[i].setdata(type,pro,ram,hdisk,usb,hdmi,time);
                    obj3[i].setdata(compname,pername,mobile,email,date,quantity);
                }
                else if(strcmp(t1[i].c_str(),"D")==0)
                {
                    getline(myFile, temp, ',');
                    strcpy(compname, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(pername, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(mobile, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(email, temp.c_str());
                    getline(myFile, temp, ',');
                    quantity=atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(date, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(type, temp.c_str());
                    getline(myFile, temp, ',');
                    strcpy(pro, temp.c_str());
                    getline(myFile, temp, ',');
                    ram = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    hdisk = atoi(temp.c_str());
                    getline(myFile, temp, ',');
                    usb = atoi(temp.c_str());
                    getline(myFile, temp, '\n');
                    hdmi = atoi(temp.c_str());
                    obj1[i].setdata(type,pro,ram,hdisk,usb,hdmi,0);
                    obj3[i].setdata(compname,pername,mobile,email,date,quantity);
                }
                i++;
                count++;
            }
            myFile.close();

            fstream file;
            file.open("temp1.txt", ios::app);   
            cout<<"Enter the record no. whose details are to be modified: ";
            cin>>num;     
            i=1;
            while(i<count)
            {
                if(i==num)
                {
                    i++;
                }
                else
                {
                    if(strcmp(t1[i].c_str(),"A")==0)
                    {
                        file<<"A,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                    }
                    else if(strcmp(t1[i].c_str(),"B")==0)
                    {
                        file<<"B,"<<obj2[i].getName()<<","<<obj2[i].getMobile()<<","<<obj2[i].getEmail()<<","<<obj2[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                    }
                    else if(strcmp(t1[i].c_str(),"C")==0)
                    {
                        file<<"C,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<","<<obj1[i].getTime()<<"\n";
                    }
                    else if(strcmp(t1[i].c_str(),"D")==0)
                    {
                        file<<"D,"<<obj3[i].getCompname()<<","<<obj3[i].getPername()<<","<<obj3[i].getMobile()<<","<<obj3[i].getEmail()<<","<<obj3[i].getQuantity()<<","<<obj3[i].getDate()<<","<<obj1[i].getType()<<","<<obj1[i].getProcessor()<<","<<obj1[i].getRam()<<","<<obj1[i].getHarddisk()<<","<<obj1[i].getUsb()<<","<<obj1[i].getHdmi()<<"\n";
                    }
                    i++;
                }
            }
            file.close();
            remove("computer.txt");
            rename("temp1.txt", "computer.txt"); 
        }

        cout<<"\nDo you want to do anything else?\nEnter (1/0): ";
        cin>>x;
    }
    while(x==1);

    return 0;
}