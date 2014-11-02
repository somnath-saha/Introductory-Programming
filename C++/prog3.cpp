//WAP to implement Default Constructor, Parameterized Constructor and 
//Copy Constructor in class and Destructors function

#include<iostream>

using namespace std;

//Class defined for handling complex numbers
class complex
{
	private:
		static int count;
		float r, i;
	public:
		complex()//Default constructor
		{
			r=i=0.0;
			count++;
			cout<<"\nCreating object "<<count<<"\n";
			
		}
		complex(float r, float i)//Parameterised constructor
		{
			count++;
			this->r=r;
			this->i=i;
			cout<<"\nCreating object "<<count<<"\n";
			
		}
		complex(complex& z)//Copy constructor
		{
			count++;
			cout<<"\nCopy Constructor called..."
				<<" Object "<<count<<" created.\n";
			r=z.r;
			i=z.i;
		}
		~complex()//Destructor
		{
			
			cout<<"Destructing object "<<count<<"\n";
			count--;
		}
		void show_data()
		{
			cout<<"("<<r<<","<<i<<")\n";
		}
};
int complex::count=0;

void f()
{
	complex z;
	z.show_data();
}

int main()
{
	cout<<"Calling default constructor...";
	f();
	cout<<"\nCalling parameterised constructor...";
	complex z(2,7);
	z.show_data();
	cout<<"\nCalling copy constructor...";
	complex z2=z;
	z2.show_data();
	return 0;
}
