/*Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). The
program should take two operands from user and performs the operation on those two
operands depending upon the operator entered by user. Use a switch statement to select the
operation. Finally, display the result.
Some sample interaction with the program might look like this:
Enter first number, operator, second number: 10 / 3
Answer = 3.333333
Do another (y/n)? y
Enter first number, operator, second number: 12 + 100
Answer = 112
Do another (y/n)? n*/

#include<iostream>
#include<stdio.h>
using namespace std;

class calc
{

  public:

  void op(float a,char c,float b)
     {
        float ans;
        switch(c)
        {
          case '+':ans=a+b;
                  break;
          case '-':ans=a-b;
                  break;
          case '*':ans=a*b;
                  break;
          case '/': ans=a/b;
                   break;
          defaulf: cout<<"\nENTER VALID OPERATION";

        }
        cout<<"\nCHOICE: "<<ans;
     }
};

int main()
{
  int a,b;
  char c,d;

  do
  {
    cout<<"\nENTER TWO OPERANDS ";
    cin>>a>>b;
    cout<<"\nENTER OPERATIONS LIKE +,-,*,/ ";
    cin>>c;
    calc x;
    x.op(a,c,b);
    cout<<"\nYOU WANT TO CONTINUE(y/n) ";
    cin>>d;
  }while(d=='y');
  return 0;

}
