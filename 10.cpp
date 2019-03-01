/*Write a function template selection Sort. Write a program that inputs, sorts and outputs an int
array and a float array.*/
//Demonstrate function template for selection sorting algorithm.
#include<iostream>
using namespace std;
template<typename T>
void input(T *a, int n)
{
	cout<<"\nENTER "<<n<<" ELEMENTS IN ARRAY";
	for(int i=0;i<n;i++)
		cin>>a[i];
}
template<typename T>
void sorting(T *a, int n)
{
	int min;
	for(int i=0;i<n;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		swap(a[i],a[min]);
	}
}
template<typename T>
void display(T *a, int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
}
int main()
{
	cout<<"\nNO. OF ELEMENTS YOU WANT TO SORT:\n";
	int n;
	cin>>n;
	if(n <= 0)
	{
		cout<<"ENTER VALUE IS INVALID.ENTER THE AGAIN:";
		cin>>n;
	}
	int a[n];
	input(a,n);
	cout<<"\nElements before sorting\n";
	display(a,n);
	cout<<"\nElements after sorting\n";
	sorting(a,n);
	display(a,n);
	float b[n];
	input(b,n);
	cout<<"\nElements before sorting\n";
	display(b,n);
	cout<<"\nElements after sorting\n";
	sorting(b,n);
	display(b,n);
	return 0;
}
