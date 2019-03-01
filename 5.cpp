/*Create a class template to represent a generic vector. Include following member functions:
 To create the vector.
 To modify the value of a given element
 To multiply by a scalar value
 To display the vector in the form (10,20,30,...)*/
#include<iostream>
using namespace std;

template<class X> class vector
{
   X *v;
 public:
    void create(int);
    void display(int);
    void multiply(X,int);
    void modify(int,X, int);

};

template<class X> void vector<X>::create(int size)
{
   v = new X(size);
   int i;
   cout<<"\nEnter values: ";
   for(i=0;i<size;i++)
   {
      cin>>v[i];
   }

}

template<class X> void vector<X>::display(int size)
{
   int i;

   for(i=0;i<size;i++)
   {
      cout<<v[i]<<" ";
   }
}

template<class X> void vector<X>::multiply(X val, int size)
{
    int i;

   for(i=0;i<size;i++)
   {
       v[i]*=val;
   }
   cout<<"\n Multiplied !";
}

template<class X> void vector<X>::modify(int size, X val, int pos)
{
    if(pos<size)
    {
       v[pos]=val;
       cout<<"\nModified.";
    }
    else
    {
       cout<<"\nPosition should be less than size.";
    }

}

template<class X> void operation( vector<X> v,int size)
{
    int n,pos;
    char ch;
    X val;
    do
   {
      cout<<"\n \n1.display\n2.modify\n3.multiply";
      cin>>n;
      switch(n)
      {
         case 1: v.display(size);
                 break;
        case 2: cout<<"\nEnter value and position";
                 cin>>val>>pos;
                 v.modify(size,val,pos);
                 break;
        case 3: cout<<"\nEnter value to multi[ply: ";
                 cin>>val;
                 v.multiply(val,size);
                 break;
      }
      cout<<"\nDo you want to continue?";
      cin>>ch;
   }while(ch=='y'|| ch=='Y');

}

int main()
{
   int n,size;
   char ch;
   do
   {
      cout<<"\nVector of \n1.integer\n2.float";
      cin>>n;
      switch(n)
      {
         case 1: cout<<"\nEnter size: ";
                 cin>>size;
                 vector<int> v1;
                 v1.create(size);
                 operation(v1,size);
                 break;
        case 2: cout<<"\nEnter size: ";
                 cin>>size;
                 vector<float> v2;
                 v2.create(size);
                 operation(v2,size);
                 break;
      }
      cout<<"\nDo you want to continue?";
      cin>>ch;
   }while(ch=='y'|| ch=='Y');
}
