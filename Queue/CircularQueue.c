/*
 ============================================================================
 Description : Circular Queue implementation in arrays
 Author      : Somnath Saha
 Roll no.    : 529/IC/10
 ============================================================================
 */

#include <stdio.h>
#define LENGTH 10

int a[LENGTH], end=-1, start=-1;

void enqueue()
{
	if((end==start-1)||((end==LENGTH-1)&&(start==0)))
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
			++end;
			end=end%LENGTH;
			a[end]=data;
			printf("%d inserted in queue successfully!\n", data);

		}
	}
}

void display()
{
	if(end==-1)
	{
		printf("Queue empty!\n");
	}
	else
	{
		int j=start, i;
		printf("ACTUAL ARRAY:");
		for(i=0;i<LENGTH;++i)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
		if(start<=end)
		{
			for(;j<=end;++j)
			{
				printf("%d ", a[j]);
			}
		}
		else
		{
			for(;j<LENGTH;++j)
			{
				printf("%d ", a[j]);
			}
			for(j=0;j<=end;++j)
			{
				printf("%d ", a[j]);
			}
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
		printf("%d removed from queue successfully!\n", a[start]);
		if(start==end)	
			start=end=-1;
		else
		{
			start++;
			start=start%LENGTH;
		}
	}
}

void menu()
{
	printf("CIRCULAR QUEUE IMPLEMENTATION IN ARRAYS:");
	printf("\n1.Create \n2.Enqueue \n3.Dequeue \n4.Delete \n5.Display \n6.Exit\n\n");
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
