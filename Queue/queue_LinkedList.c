/*
 ============================================================================
 Description : Queue implemented from linked list
 Author      : Somnath Saha 
 Roll no.    : 529/IC/10
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node * next;
}*temp=NULL, *front=NULL, *rear=NULL;

typedef struct Node node;

void enqueue()
{
	if(rear==NULL)
	{
		rear=(node *)malloc(sizeof(node));
		printf("Enter data:");
		scanf("%d", &rear->data);
		rear->next=NULL;
		front=rear;
	}
	else
	{
		temp=(node *)malloc(sizeof(node));
		printf("Enter data:");
		scanf("%d", &temp->data);
		temp->next=NULL;
		rear->next=temp;
		rear=temp;
	}
	printf("Element %d added to queue.\n", rear->data);
}

void display()
{
	if(front==NULL)
	{
		printf("Queue empty.");
	}
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

void dequeue()
{
	if(front==NULL)
	{
		printf("Queue empty!\n");
	}
	else
	{
		temp=front;
		front=front->next;
		printf("Element %d deleted.\n",temp->data);
		free(temp);
	}
}

void clear()
{
	while(front!=NULL)
	{
		temp=front;
		front=front->next;
		free(temp);
	}
	rear=NULL;
}

void menu()
{
	printf("QUEUE IMPLEMENTED FROM LINKED LIST");
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
		case 1: clear();
				printf("New queue has been created.\n");
				enqueue();
				break;

		case 2: enqueue();
				break;

		case 3: dequeue();
				break;

		case 4: clear();
				printf("Existing queue has been cleared.\n");
				break;

		case 5: display();
				break;
				
		case 6: return 1;
								
		default:printf("Enter value only 1-6.");
					
		}
	}while(c!=6);
	
	return 0;
}
