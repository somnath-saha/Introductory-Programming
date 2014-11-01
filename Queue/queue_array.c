/*
 ============================================================================
 Description : Queue implemented from arrays
 Author      : Somnath Saha
 Roll no.    : 529/IC/10
 ============================================================================
 */

#include <stdio.h>
#define LENGTH 5

int a[LENGTH], end=-1, start=-1;

void enqueue()
{
	if(end==LENGTH-1)
	{
		printf("Overflow error!\n");
	}
	else
	{
		int data;
		printf("Enter data:");
		scanf("%d",&data);
		if(end==-1)
		{
			start=end=0;
			a[start]=data;
			printf("%d inserted in queue successfully!\n", data);
		}
		else
		{
			a[++end]=data;
			printf("%d inserted in queue successfully!\n", data);

		}
	}
}

void display()
{
	if(end==-1||start>end)
	{
		printf("Queue empty!\n");
	}
	else
	{
		int j=start;
		for(;j<=end;++j)
		{
			printf("%d ", a[j]);
		}
		printf("\n");
	}
}

void dequeue()
{
	if(start==-1)
		printf("Queue empty!\n");
	else
	{
		start++;
		printf("%d removed from queue successfully!\n", a[start-1]);
	}
}

void menu()
{
	printf("QUEUE IMPLEMENTED FROM ARRAYS:");
	printf("\n1.Create new queue \n2.Enqueue \n3.Dequeue \n4.Delete queue \n5.Display queue \n6.Exit\n\n");
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
			case 1: start=end=-1;
				enqueue();
				break;

			case 2: enqueue();
				break;

			case 3: dequeue();
				break;

			case 4: start=end=-1;
				break;

			case 5: display();
				break;
					
			case 6: return 1;
									
			default:printf("Enter value only 1-6.\n");
					
		}
	}while(c!=6);
	
	return 0;
}
