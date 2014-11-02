//Working with C++ files

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct emp
{
		char name[20];
		char phone[15];
}e[10];

void search(int i, char* data, short control=0)
{
	short flg=0;
	if(control==0)
	{
		for(int j=0; j<i; ++j)
		{
			if(strcmp(data, e[j].phone)==0)
			{
				flg=1;
				cout<<e[j].name<<"\t"<<e[j].phone<<endl;
			}
		}
		if (flg==0)
			cout<<"No record exists for the given phone number.";
	}
	else
	{
		for(int j=0; j<i; ++j)
		{
			if(strcasecmp(data, e[j].name)==0)
			{
				flg=1;
				cout<<e[j].name<<"\t"<<e[j].phone<<endl;
			}
		}
		if (flg==0)
			cout<<"No record exists for the given name.";
	}
}

void update(int i, char* data)
{
	short flg=0;
	for(int j=0; j<i; ++j)
	{
		if(strcasecmp(data, e[j].name)==0)
		{
			flg=1;
			cout<<"\nEnter new phone number:";
			cin>>e[j].phone;
			break;
		}
	}
	if (flg==0)
		cout<<"No record exists for the given name.";
	if(flg==1)
	{
		ofstream f("emp.txt", ios::out);
		for(int j=0; j<i; ++j)
		{
			f<<e[j].name<<"\t"<<e[j].phone<<endl;
		}
		f.close();
	}
}

int main()
{
	ifstream f("emp.txt",ios::in);
	char data[15];
	int i=0;
	short choice;
	while(!f.eof())
	{
		f>>data;
		strcpy(e[i].name,data);
		f>>data;
		strcpy(e[i].phone, data);
		i++;
	}
	i--;
	f.close();
	do
	{
		cout<<"\nMENU"
			<<"\n1.Display file data"
			<<"\n2.Find telephone number"
			<<"\n3.Find name"
			<<"\n4.Update telephone no."
			<<"\n5.Exit"
			<<"\n\nEnter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: for(int j=0; j<i; ++j)
					{
						cout<<e[j].name<<"\t"<<e[j].phone<<endl;
					}
					break;
			case 2: cout<<"Enter telephone no. to search: ";
					cin>>data;
					search(i, data);
					break;
			case 3: cout<<"Enter name to search: ";
					cin>>data;
					search(i, data, 1);
					break;
			case 4: cout<<"Enter name for which phone is to be updated: ";
					cin>>data;
					update(i, data);
					break;
			case 5: break;
			default: cout<<"\nEnter a valid choice:";
		}
	} while(choice!=5);
	return 0;
}
