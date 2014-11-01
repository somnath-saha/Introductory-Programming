/*
 ============================================================================
 Description : 	Priority Queue implemented from array of structures
  				Element with highest data priority value is dequeued first
 Author      : 	Somnath Saha 
 Roll no.    : 	529/IC/10
 ============================================================================
*/
 
#include<stdio.h>

#define MAX 5

typedef struct Node
{
	int data;
	int priority;
}node;

node q[MAX];
int rear=-1,front=-1;

void insert()
{
	if(rear==MAX-1)
	{
		printf("\nPriority Queue is full.");
		return;
	}
	else
	{
		rear++;
		printf("\nEnter data: ");
		scanf("%d",&q[rear].data);
		printf("Enter data priority: ");
		scanf("%d",&q[rear].priority);
		if(front==-1)
		{
			front=rear;		
		}
		//printf("front=%d\trear=%d", front, rear);
	}
}

void remove_element()
{
	if(front==-1)
	{
		printf("\nUNDERFLOW ERROR!");
		return;
	}
	else
	{	
		if(front==rear)
		{
			printf("\n%d deleted.",q[front].data);
			front=rear=-1;			
		}
		else
		{
			node max=q[front];
			int pos=front, i;
			for(i=front+1; i<=rear; i++)
			{
				if(q[i].priority>max.priority)
				{
					pos=i;	
					max=q[i];			
				}
			}
			printf("\n%d deleted.",q[pos].data);
			for(i=pos;i<=rear-1;++i)
			{
				q[i]=q[i+1];
			}
			rear--;
		}
	}
}

void display()
{
	if(front==-1)
	{
		printf("Queue is empty.");
		return;
	}
	else
	{
		int i;
		printf("\nfront=%d\trear=%d", front, rear);
		printf("\nData:\t\t");
		for(i=front;i<=rear;i++)
		{
			printf("%d\t", q[i].data);
		}
		printf("\nPriority:\t");
		for(i=front;i<=rear;i++)
		{
			printf("%d\t", q[i].priority);
		}
	}
}

void menu()
{
	printf("PRIORITY QUEUE");
	printf("\n1.Create \n2.Insert \n3.Remove \n4.Delete \n5.Display \n6.Exit\n");
}

int main()
{	
	int c=0;
	menu();
	do
	{
		printf("\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
		case 1: front=rear=-1;
				printf("New priority queue has been created.\n");
				insert();
				break;

		case 2: insert();
				break;

		case 3: remove_element();
				break;

		case 4: front=rear=-1;
				printf("Existing priority queue has been cleared.\n");
				break;

		case 5: display();
				break;
				
		case 6: return 1;
								
		default:printf("Enter value only 1-6.");
					
		}
	}while(c!=6);
	
	return 0;
}
