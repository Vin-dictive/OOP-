//Demonstrate file handling operations to create phonebook.
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;
class Telephone
{
	char na[20],tel[15];
	public:
			void getdata()
			{
				cout<<"\n Enter the Telephone details:";
				cout<<"\n Name:";
				cin>>na;
				cout<<"\n Telephone Number:";
				cin>>tel;
			}
			void putdata()
			{
				cout<<"\n"<<left<<setw(20)<<na;
				cout<<left<<setw(15)<<tel;
			}
			char *getName()
			{
				return na;
			}
			char *gettel()
			{
				return tel;
			}
			void update(char *nam,char *telno)
			{
				strcpy(nam,na);
				strcpy(tel,telno);
			}
};
int main()
{
	char telno[15],name[20],ch;
	int cho,flag=0,cnt=0;
	fstream f;
	Telephone t;
	f.open("TData.dat",ios::out|ios::in|ios::binary);
	do
	{
		cout<<"\n Telephone Directory";
		cout<<"\n 1. Create Record";
		cout<<"\n 2. Display All Records";
		cout<<"\n 3. Search by Name";
		cout<<"\n 4. Search by Telephone Number";
		cout<<"\n 5. Update Telephone Number";
		cout<<"\n 6. Exit";
		cout<<"\n Enter your choice:";
		cin>>cho;
		switch(cho)
		{
			case 1:	t.getdata();
					f.write((char*)&t,sizeof(t));
					break;
			case 2: cout<<"\n All Telephone Records are:";
					cout<<"\n  Name \t\tTelephoneNumber";
					f.seekg(0,ios::beg);
					for(f.read((char*)&t,sizeof(t));!f.eof();f.read((char*)&t,sizeof(t)))
						t.putdata();
					f.clear();
					break;
			case 3: cout<<"\n Enter Name for Searching:";
					cin>>name;
					f.seekg(0,ios::beg);
					for(f.read((char*)&t,sizeof(t));!f.eof();f.read((char*)&t,sizeof(t)))
					{
						if(strcmp(name,t.getName())==0)
						{
							cout<<"\n All Telephone Records are:";
							cout<<"\n  Name \t\tTelephoneNumber";
							t.putdata();
							flag=1;
						}
					}
					f.clear();
					if(flag==0)
						cout<<"\n Record not Found.";
					break;
			case 4: cout<<"\n Enter Telphone Number for Searching:";
					cin>>telno;
					f.seekg(0,ios::beg);
					flag=0;
					for(f.read((char*)&t,sizeof(t));!f.eof();f.read((char*)&t,sizeof(t)))
					{
						if(strcmp(telno,t.gettel())==0)
						{
							cout<<"\n All Telephone Records are:";
							cout<<"\n  Name \t\tTelephoneNumber";
							t.putdata();
							flag=1;
						}
					}
					f.clear();
					if(flag==0)
						cout<<"\n Record not Found.";
					break;
			case 5: cout<<"\n Enter Name for Updation:";
					cin>>name;
					flag=0;
					f.seekg(0,ios::beg);
					for(f.read((char*)&t,sizeof(t));!f.eof();f.read((char*)&t,sizeof(t)))
					{
						cnt++;
						if(strcmp(name,t.getName())==0)
						{
							flag=1;
							break;
						}
					}
					f.clear();
					if(flag==0)
						cout<<"\n Record not Found.";
					else
					{
						int loc=(cnt-1)*sizeof(t);
						if(f.eof())
 							f.clear();
						cout<<"Enter New Telephone No : ";
 						cin>>telno;
 						f.seekp(loc);
 						t.update(name,telno);
 						f.flush();
 						f.write((char *) &t, sizeof(t));
 					}
					break;
			case 6: return 0;
			default:cout<<"\n Enter valid Choice.";
					break;
		}
		cout<<"\n Do you want to continue(y/n):";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	return 0;
}
