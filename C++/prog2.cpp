//Define the class to represent a student record, include the following data members:
//Roll No., Name, Branch, Address etc.
//Member functions - Input of the 10 students record and display all 10 records.

#include<iostream>
#include<cstring>

using namespace std;

class student
{
	private:
		int rollNo;
		char name[20];
		char branch[10];
		char address[40];
		float percentage;
	public:
		student();
		void setup_data();
		void show_data();
}b[10];

student::student()
{
	rollNo=0;
	strcpy(name,"NULL");
	strcpy(branch,"NULL");
	strcpy(address,"NULL");
	percentage=0.0;
}
void student::setup_data()
{
	cout<<"\nEnter the roll no: ";
	cin>>rollNo;
	cout<<"Enter the name: ";
	cin.ignore();
	cin.getline(name, 80, '\n');
	cout<<"Enter the branch: ";
	cin.getline(branch, 80, '\n');
	cout<<"Enter the address: ";
	cin.getline(address, 80, '\n');
	cout<<"Enter the percentage: ";
	cin>>percentage;
}
void student::show_data()
{
	cout<<"\nRoll no: "<<rollNo;
	cout<<"\nName: "<<name;
	cout<<"\nBranch: "<<branch;
	cout<<"\nAddress: "<<address;
	cout<<"\nPercentage: "<<percentage<<endl;
}

int main()
{
	for(int i=0; i<5; ++i)
	{
		cout<<"\nEnter data for student "<<i+1<<":";
		b[i].setup_data();
	}
	for(int i=0; i<5; ++i)
	{
		b[i].show_data();
	}
	return 0;
}
