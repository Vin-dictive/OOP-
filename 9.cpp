//Demonstration of command line arguments for finding and replacing string in a file
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main(int argc,char *argv[])
{
	if(argc<4)
	{
		cout<<"\n Insufficient number of arguments from command line.";
		return 1;
	}
	string data,newdata;
	fstream fin;
	cout<<"\n\t Find String "<<argv[2]<<" and replace with "<<argv[3];
	cout<<"\n\t *** Contents of File Before Replacing ***";
	fin.open(argv[1],ios::in);
	if(!fin)
	{
		cout<<"\n\t Unable to open a file.";
		return 1;
	}
	while(fin)
	{
		getline(fin,data);
		cout<<data<<endl;
	}
	fin.close();
	fin.open(argv[1],ios::in);
	newdata="";
	if(!fin)
	{
		cout<<"\n\t Unable to open a file.";
		return 1;
	}
	while(fin)
	{
		getline(fin,data);
		int b;
		int a=(int) data.find(argv[2],0);
		while(a!=string::npos)
		{
			data.replace(a,strlen(argv[2]),argv[3]);
			a=(int)data.find(argv[2],(a+1));
		}
		newdata=newdata+data+"\n";
	}
	fin.close();
	fin.open(argv[1],ios::out);
	if(!fin)
	{
		cout<<"\n\t Unable to open a file.";
		return 1;
	}
	fin<<newdata;
	cout<<"\n\t Replacement Done Successfully.";
	fin.close();
	cout<<"\n\t *** Contents of File After Replacing ***";
	fin.open(argv[1],ios::in);
	if(!fin)
	{
		cout<<"\n\t Unable to open a file.";
		return 1;
	}
	while(fin)
	{
		getline(fin,data);
		cout<<data<<endl;
	}
	fin.close();
	return 0;
}
