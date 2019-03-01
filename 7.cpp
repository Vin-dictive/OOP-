/*Crete User defined exception to check the following conditions and throw the exception if the
criterion does not met.
a. User has age between 18 and 55
b. User stays has income between Rs. 50,000 – Rs. 1,00,000 per month
c. User stays in Pune/ Mumbai/ Bangalore / Chennai
d. User has 4-wheeler
Accept age, Income, City, Vehicle from the user and check for the conditions mentioned
above. If any of the condition not met then throw the exception.*/
#include<bits/stdc++.h>
using namespace std;

class emp
{
    int age;
    double salary;
    string city;
public:

    void input();
    void display();



};

void emp::input()
{
    try
    {
        cout<<"\nEnter age of employee: ";
        cin>>age;
        if(age<18 || age>55)
            throw 1;
        cout<<"\nEnter salary of employee: ";
        cin>>salary;
        if(salary<50000 || salary>100000)
            throw 2;
        cout<<"\nEnter city of employee: ";
        cin>>city;
        if(city!="pune")
            throw 3;
    }
    catch(int a)
{
    throw a;
}

}


void emp::display()
{
    cout<<"\nEmployee details are: ";
    cout<<"\nAGE: "<<age;
    cout<<"\nSALry: "<<salary;
    cout<<"\nCITY: "<<city;
}

int main()
{
    char ch;
    emp e;
    do
    {


    try
    {
        e.input();
        e.display();
    }
    catch(int b)
    {
        if(b==1)
            cout<<"\nAGE IS INVALID";
        else if(b==2)
            cout<<"\nSALARY IS INVALID";
        else if(b==3)
            cout<<"\nCITY MUST BE PUNE ONLY";

    }
    cout<<"\nDo you want to continue?(y/n)";
    cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;

}
