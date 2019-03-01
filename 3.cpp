/*Create a class Rational Number (fractions) with the following capabilities:
a) Create a constructor that prevents a 0 denominator in a fraction, reduces or simplifies
fractions that are not in reduced form and avoids negative denominators.
b) Overload the addition, subtraction, multiplication and division operators for this class.
c) Overload the relational and equality operators for this class.*/

#include<bits/stdc++.h>
using namespace std;

class fraction
{
   int a,b;
   public:
     fraction(int q, int w);
     fraction();
     friend ostream& operator << (ostream &o, fraction &f);
     void reduce();
     fraction operator + (fraction &q);
     fraction operator * (fraction &q);



};

 fraction fraction::operator + (fraction &q)
 {
    fraction temp;
    temp.b=b*q.b;
    temp.a= a*q.b + q.a*b;
    temp.reduce();
    return temp;
 }

 fraction fraction::operator * (fraction &q)
 {
    fraction temp;
    temp.b=b*q.b;
    temp.a= a*q.a;
    temp.reduce();
    return temp;
 }


void fraction::reduce()
{
   int i=min(a,b);
   int e;
   for(e=i;e>1;e--)
   {
       if(a%e==0 && b%e==0)
       {
          a=a/e;
          b=b/e;
       }
   }
}

ostream& operator << (ostream &o, fraction &f)
{
    if(f.a==0)
    cout<<"0";
    else
    {
    cout<<"\nfractions are: ";
    o<<f.a;
    cout<<"/";
    o<<f.b;
    }
    return o;
}

fraction::fraction(int q,int w)
{

       a=q;
       b=w;
       if(a<0 && b<0)
       {
         a=abs(q);
         b=abs(w);
       }
       while(b==0)
       {
          cout<<"\nDeno cant be zero. enter denominator again.";
          cin>>b;
       }
}

fraction::fraction()
{
  a=0;
  b=0;
}


int main()
{
   float a,b;
   cout<<"\nEnter num and deno of fraction 1: ";
   cin>>a>>b;
   fraction f1(a,b);
    cout<<"\nEnter num and deno of fraction 2: ";
   cin>>a>>b;
   fraction f2(a,b);
   f1.reduce();
   f2.reduce();
   cout<<f1<<f2;
   fraction f3=f1+f2;
   cout<<"\naddition of two fractions are: ";
   cout<<f3;
   cout<<"\nmultiplication of two fractions are: ";
   f3=f1*f2;
   cout<<f3;

   return 0;
}
