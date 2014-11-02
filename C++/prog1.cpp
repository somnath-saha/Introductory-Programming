//Write a C++ Program to implement -- 
//a) Scope resolution operator
//b) Inline function 
//c) Function overloading
//d) Friend Function

#include<iostream>

using namespace std;
const int PI=3.14;

//Global variable
int x=2;

//Inline function
inline int sub(int m, int n)
{
	return(m-n);
}

//Function area overloaded
float area(float r)
{
	return(PI*r*r);
}
float area(float l, float b)
{
	return(l*b);
}

//Friend Function Implementation
class B;
class A
{
	private:
		int x;
		friend int f(A, B);
	public:
		A()
		{
			x=10;
		}
}obj1;
class B
{
	private: 
		int y;
		friend int f(A, B);
	public:
		B()
		{
			y=20;
		}
}obj2;
int f(A obj1, B obj2)//All class A and B private members can be accessed through this function
{
	return obj1.x+obj2.y;
}

int main()
{
	int x=1;
	cout<<"Implementing scope resolution operator:";
	cout<<"\nLocal value of x: "<<x;
	cout<<"\nGlobal value of x: "<<::x;
	
	cout<<"\n\nImplementing inline functions";
	int result=sub(100,20);
	cout<<"\nResult of inline subtraction function: "<<result;
	
	cout<<"\n\nImplementing function overloading";
	float circle,rect;
	circle = area(2.5);
	rect = area(3.0,4.0);
	cout<<"\nArea of circle: "<<circle<<"\nArea of rectangle: "<<rect;
	
	A obj1;
	B obj2;
	cout<<"\n\nCalling friend function that can access private members: "
		<<"\nReturns sum of private members:"<<f(obj1, obj2);
	
	return 0;
}
