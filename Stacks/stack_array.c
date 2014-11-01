/*
 ============================================================================
 Description : Stack implemented from arrays
 Author      : Somnath Saha
 Roll no.    : 529/IC/10
 ============================================================================
 */

#include <stdio.h>
#define LENGTH 10

int a[LENGTH], top=-1;

void push()
{
	if(top<LENGTH-1)
	{
		int x=0;
		printf("Enter value of element:");
		scanf("%d",&x);
		top++;
		a[top]=x;
	}
	else
	{
		printf("Stack full!\n");
	}
}

void display()
{
	if(top==-1)
	{
		printf("Stack empty!\n");
	}
	else
	{
		int j=0;
		for(;j<=top;++j)
		{
			printf("%d ", a[j]);
		}
		printf("\n");
	}
}

void pop()
{
	if(top==-1)
			printf("Stack empty!\n");
	else
		top--;
}

void menu()
{
	printf("STACK IMPLEMENTED FROM ARRAYS:");
	printf("\n1.Create \n2.Push \n3.Pop \n4.Delete \n5.Display \n6.Exit\n\n");
}

int main()
{
	int c=0;
	menu();
	do
	{
		printf("Enter your choice:");
		scanf("%d",&c);
		switch(c)
		{
		case 1: top=-1;
				push();
				break;

		case 2: push();
				break;

		case 3: pop();
				break;

		case 4: top=-1;
				break;

		case 5: display();
				break;
				
		case 6: return 1;
								
		default: 	printf("Enter value only 1-6.\n");
					
		}
	}while(c!=6);
	
	return 0;
}
