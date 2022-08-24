// Write a Program to Demonstrate Friend Function and Friend Class.

#include<iostream>
using namespace std;
class num
{
    private:
        int a,b;
    public:
        void input()
        {
            a = 10;
            b = 20;
        }
        friend void sum(num);
};
void sum(num ob)
{
    cout << "Sum = " << (ob.a + ob.b);
}
int main()
{
    num n1;
    n1.input();
    sum(n1);
}