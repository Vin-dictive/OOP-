//Demonstration of multiple Inheritance to create Bio-data of student
#include<iostream>
#include<stdlib.h>
using namespace std;
class Personal
{
	private:
		string name,address,gender;
		int contact;
	public:
		Personal()
		{
			name="";
			address="";
			gender="";
			contact=-1;
		}
		void getData()
		{
			cout<<"\n********** ENTER YOUR PERSONAL DETAILS************";
			cout<<"\nENTER YOUR NAME:";
			cin>>name;
			cout<<"\nENTER GENDER:";
			cin>>gender;
			cout<<"\nENTER ADDRESS:";
			cin>>address;
			cout<<"\nENTER CONTACT NUMBER:";
			cin>>contact;
		}
		void putData()
		{
      cout<<"\n********** YOUR PERSONAL DETAILS ARE AS FOLLOWS************";
			cout<<"\n\nNAME:"<<name;
			cout<<"\nGENDER:"<<gender;
      cout<<"\nADDRESS:"<<address;
			cout<<"\nCONTACT NUMBER:"<<contact;
		}
};
class Professional
{
	private:
		string os,pl;
		string classname;
	public:
		Professional()
		{
			os="";
			pl="";
			classname="";
		}
		void getData()
		{
			cout<<"\n\n********** ENTER YOUR PROFESSIONAL DETAILS ************";

			cout<<"\n\nPRESENTLY WORKING AT: ";
			cin>>classname;
			cout<<"\nPREFERABLE OPERATING SYSTEM?:";
			cin>>os;
			cout<<"\nPROGRAMMING LANGUAGE YOU KNOW:";
			cin>>pl;
		}
		void putData()
		{
      cout<<"\n\n********** YOUR PROFESSIONAL DETAILS ARE AS FOLLOWS ************";

			cout<<"\n\n PRESENTLY WORKING AT: "<<classname;
			cout<<"\n PREFERABLE OPERATING SYSTEM: "<<os;
			cout<<"\n PROGRAMMING LANGUAGE YOU KNOW: "<<pl;
		}
};
class Academic
{
	private:
		float ten,twe,fe,se;
	public:
		Academic()
		{
			ten=-1;
			twe=-1;
			fe=-1;
			se=-1;
		}
		void getData()
		{
			cout<<"\nENTER 10TH,12TH,FIRST YEAR,SECOND YEAR PERCENT: \n";
			cin>>ten>>twe>>fe>>se;
		}
		void putData()
		{
      cout<<"\n\n********** YOUR ACADEMIC DETAILS ARE ************";
			cout<<"\n 10th marks are "<<ten;
			cout<<"\n 12th marks are "<<twe;
			cout<<"\n FE marks are "<<fe;
			cout<<"\n SE marks are "<<se;
		}
};
class CV:public Personal,public Professional,public Academic
{
	private:
		string title;
	public:
		CV():Personal(),Professional(),Academic()
		{
			title="";
		}
		void getData()
		{
			Personal::getData();
			Professional::getData();
			Academic::getData();
			cout<<"\nENTER THE TITLE:";
			cin>>title;
		}
		void putData()
		{
			cout<<"\n************"<<title<<"**************\n";
			Personal::putData();
			Professional::putData();
			Academic::putData();
		}
};
int main()
{
	CV c1;
	c1.getData();
	c1.putData();
	return 0;
}
