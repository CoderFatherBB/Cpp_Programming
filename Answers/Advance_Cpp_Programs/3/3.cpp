// WAP to Insert the Information from the User and Display the Student Information in the Library using Multiple/ Multi-Level Inheritance Concept of C++ Programming. 
//	Book Information: Book_Name, Author_Name, Publication, Number of Copies 
//	Library Information: Name, Qualification, Experience,
//	Students Information: Student_Name, Department, Class, Division, Book
//	Issue Information: Book_issue, Book_details, Student Information 

#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <cstdio>
using namespace std;
class book
{
    private:
    char name[30], author[30], publi[30];
    int copies;

    public:
    void setdata(char *n, char *a, char *p, int c)
    {
        strcpy(name,n);
        strcpy(author,a);
        strcpy(publi,p);
        copies = c;
    }
    char *getName()
    {
        return name;
    }
    char *getAuthor()
    {
        return author;
    }
    char *getPublication()
    {
        return publi;
    }
    int getCopies()
    {
        return copies;
    }
}obj1[10];

class librarian 
{
    private:
    char quali[15],lname[30];
    int exper;

    public:
    void setdata(char *ln, char *q, int ex)
    {
        strcpy(lname,ln);
        strcpy(quali,q);
        exper = ex;
    }
    char *getName()
    {
        return lname;
    }
    char *getQualification()
    {
        return quali;
    }
    int getExperience()
    {
        return exper;
    }
}obj2;

class student 
{
    private:
    char sname[30], depar[20], std[5], div[3];

    public:
    void setdata(char *sn, char *d, char *s, char *di)
    {
        strcpy(sname,sn);
        strcpy(depar,d);
        strcpy(std,s);
        strcpy(div,di);
    }
    char *getName()
    {
        return sname;
    }
    char *getDepartment()
    {
        return depar;
    }
    char *getClass()
    {
        return std;
    }
    char *getDivision()
    {
        return div;
    }
}obj3;

class library : public book, public librarian
{
    private:
    char taken[15], returned[15];

    public:
    void setdata(char *t, char *r)
    {
        strcpy(taken,t);
        strcpy(returned,r);
    }
    char *getTake()
    {
        return taken;
    }
    char *getReturn()
    {
        return returned;
    }
}obj4;

int main()
{
    char name[30], author[30], lname[30], publi[30], quali[15], sname[30], depar[20], std[5], div[3], taken[15], returned[15];
    int copies, exper;
    int i,ch,x,num,a;
    string temp;

    fstream file;
    fstream myFile;
    // myFile.open("book.txt",ios::out);
    // if(!myFile.eof())
    // {
    //     cout<<"File opened successfully";
    //     for(i=0;i<10;i++)
    //     {
    //         cout<<"\nBook "<<i+1;
    //         cout<<"\nEnter name of book: ";
    //         cin>>name;
    //         cout<<"Enter name of author: ";
    //         cin>>author;
    //         cout<<"Enter name of publication: ";
    //         cin>>publi;
    //         cout<<"Enter no. of copies available: ";
    //         cin>>copies;
    //         obj1[i].setdata(name,author,publi,copies);
    //     }
    //     for(i=0;i<10;i++)
    //     {
    //         myFile<<obj1[i].getName()<<","<<obj1[i].getAuthor()<<","<<obj1[i].getPublication()<<","<<obj1[i].getCopies()<<"\n";
    //     }   
    //     myFile.close(); 
    // }
    // else
    // {
    //     exit(0);
    // }
 
    do
    {
        cout<<"\nDo you want to add the name of librarian(1/0): ";
        cin>>a;
        if(a==1)
        {
            file.open("libdetails.txt",ios::app);
            cout<<"\nEnter name of librarian: ";
            cin>>lname;
            cout<<"Enter qualification: ";
            cin>>quali;
            cout<<"Enter experience(in years): ";
            cin>>exper;
            obj2.setdata(lname,quali,exper);
            file<<obj2.getName()<<","<<obj2.getQualification()<<","<<obj2.getExperience()<<"\n";
            file.close();
        }
        
        cout<<"\nWho is taking or returning the book?\nIs it the same student(1/0): ";
        cin>>a;
        if(a==0)
        {
            file.open("libdetails.txt",ios::app);
            cout<<"\nEnter name of student: ";
            cin>>sname;
            cout<<"Enter department: ";
            cin>>depar;
            cout<<"Enter class: ";
            cin>>std;
            cout<<"Enter division: ";
            cin>>div;
            obj3.setdata(sname,depar,std,div);
            file<<obj3.getName()<<","<<obj3.getDepartment()<<","<<obj3.getClass()<<","<<obj3.getDivision()<<"\n";
            file.close();
        }

        cout<<"\nWhat do you want to do?\n";
        cout<<"Enter\n 1 to Take Book\n 2 to Return Book\n ";
        cin>>ch;

        if(ch==1)
        {      
            myFile.open("book.txt", ios::in);             
            i=1;  
            cout<<"\nThe books available are:\n";     
            while (!myFile.eof() && i<=10)
            {
                getline(myFile, temp, ',');
                strcpy(name, temp.c_str());        
                getline(myFile, temp, ',');
                strcpy(author, temp.c_str());
                getline(myFile, temp, ',');
                strcpy(publi, temp.c_str());
                getline(myFile, temp, '\n');
                copies=atoi(temp.c_str());
                obj1[i].setdata(name,author,publi,copies);
                cout<<i<<" "<<obj1[i].getName()<<"\n";
                i++;
            }
            myFile.close();
            
            cout<<"\nWhich book do you want to take?\n";
            cout<<"Enter the number of book which you want to take: ";
            cin>>num; 
            cout<<"Enter date on which book is taken: ";
            cin>>taken;
            obj4.setdata(taken,returned);

            file.open("libdetails.txt",ios::app);          
            myFile.open("temp3.txt",ios::app);
            i=1;
            while(i<=10)
            {
                if(i==num)
                {
                    if(obj1[i].getCopies()==0)
                    {
                        cout<<"\n!!Book is not available!!\nPlease take another book\n";
                        myFile<<obj1[i].getName()<<","<<obj1[i].getAuthor()<<","<<obj1[i].getPublication()<<","<<obj1[i].getCopies()<<"\n";
                    }
                    else
                    {
                        file<<"T"<<","<<obj1[i].getName()<<","<<obj1[i].getAuthor()<<","<<obj1[i].getPublication()<<","<<obj4.getTake()<<"\n";
                        myFile<<obj1[i].getName()<<","<<obj1[i].getAuthor()<<","<<obj1[i].getPublication()<<","<<obj1[i].getCopies()-1<<"\n";
                    }    
                }
                else
                {
                    myFile<<obj1[i].getName()<<","<<obj1[i].getAuthor()<<","<<obj1[i].getPublication()<<","<<obj1[i].getCopies()<<"\n";
                }
                i++;
            }
            myFile.close();
            file.close();
            remove("book.txt");
            rename("temp3.txt", "book.txt");
        }

        else if(ch==2)
        {
            myFile.open("book.txt", ios::in);             
            i=1;
            cout<<"\nThe books are:\n";       
            while (!myFile.eof() && i<=10)
            {
                getline(myFile, temp, ',');
                strcpy(name, temp.c_str());        
                getline(myFile, temp, ',');
                strcpy(author, temp.c_str());
                getline(myFile, temp, ',');
                strcpy(publi, temp.c_str());
                getline(myFile, temp, '\n');
                copies=atoi(temp.c_str());
                obj1[i].setdata(name,author,publi,copies);
                cout<<i<<" "<<obj1[i].getName()<<"\n";
                i++;
            }
            myFile.close();
            
            cout<<"\nWhich book do you want to take?\n";
            cout<<"Enter the number of book which you want to return: ";
            cin>>num; 
            cout<<"Enter date on which book is returned: ";
            cin>>returned;
            obj4.setdata(taken,returned);

            file.open("libdetails.txt",ios::app);
            myFile.open("temp3.txt",ios::app);
            i=1;
            while(i<=10)
            {
                if(i==num)
                {
                    file<<"R"<<","<<obj1[i].getName()<<","<<obj1[i].getAuthor()<<","<<obj1[i].getPublication()<<","<<obj4.getReturn()<<"\n";
                    myFile<<obj1[i].getName()<<","<<obj1[i].getAuthor()<<","<<obj1[i].getPublication()<<","<<obj1[i].getCopies()+1<<"\n";
                }
                else
                {
                    myFile<<obj1[i].getName()<<","<<obj1[i].getAuthor()<<","<<obj1[i].getPublication()<<","<<obj1[i].getCopies()<<"\n";
                }
                i++;
            }
            myFile.close();
            file.close();
            remove("book.txt");
            rename("temp3.txt", "book.txt");
        }

        cout<<"\nDo you want to do anything else?\nEnter (1/0): ";
        cin>>x;
    }
    while(x==1);

    return 0;
}
