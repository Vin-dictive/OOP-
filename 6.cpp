/*Write a function in C++ to count and display the number of lines not starting with
alphabet 'A' present in a text file "STORY.TXT".
Example:
If the file "STORY.TXT" contains the following lines,
The roses are red.
A girl is playing there.
There is a playground.
An aeroplane is in the sky.
Numbers are not allowed in the password.
The function should display the output as 3.*/
#include<bits/stdc++.h>

using namespace std;
int main()
{
    string s;
        int l,i;
    ofstream o("a.txt", ios::in|ios::trunc);
    if(!(o.is_open()))
    {
        cout<<"\nFailed in opening file.";
    }
    else
    {
        cout<<"\nEnter no of string you want to enter in file.";

        cin>>l;
        cin.ignore();

        for(i=0;i<l;i++)
        {
            getline(cin, s);
            o<<s;
            o<<"\n";
        }
    }

    o.close();
    int count=0;
    ifstream ii("a.txt", ios::in );
    if(!(ii.is_open()))
    {
        cout<<"\nFailed in opening file.";
    }
    else
    {

        for(i=0;i<l;i++)
        {
            getline(ii, s);

            if(s[0]!='a' && s[0]!='A')
                count++;
        }
        ii.close();
        cout<<"\n--------------------------------------------------------\n";
        cout<<"\nNumber of lines not starting with a/A are: "<<count;
        cout<<"\n--------------------------------------------------------\n";
    }
}
