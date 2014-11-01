/*
 ============================================================================
 Description : Stack implemented from linked list
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
}*temp=NULL, *top=NULL;

typedef struct Node node;

void push()
{
	if(top==NULL)
	{
		top=(node *)malloc(sizeof(node));
		printf("Enter data:");
		scanf("%d", &top->data);
		top->next=NULL;
	}
	else
	{
		temp=(node *)malloc(sizeof(node));
		temp->next=NULL;
		printf("Enter data:");
		scanf("%d", &temp->data);
		temp->next=top;
		top=temp;
	}
	printf("Element %d added to stack.\n", top->data);
}

void display()
{
	if(top==NULL)
	{
		printf("Stack empty.");
	}
	else
	{
		temp=top;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

void pop()
{
	if(top==NULL)
	{
		printf("Stack empty!\n");
	}
	else
	{
		temp=top;
		top=top->next;
		printf("Element %d deleted.\n",temp->data);
		free(temp);
	}
}

void clear()
{
	while(top!=NULL)
	{
		temp=top;
		top=top->next;
		free(temp);
	}
}

void menu()
{
	printf("STACK IMPLEMENTED FROM LINKED LIST");
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
		case 1: clear();
				printf("New stack has been created.\n");
				push();
				break;

		case 2: push();
				break;

		case 3: pop();
				break;

		case 4: clear();
				printf("Existing stack has been cleared.\n");
				break;

		case 5: display();
				break;
				
		case 6: return 1;
								
		default:printf("Enter value only 1-6.");
					
		}
	}while(c!=6);
	
	return 0;
}
