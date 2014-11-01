/*
 ============================================================================
 Description : Heap Sort to sort an array of integers
 Author      : Somnath Saha 
 Roll no.    : 529/IC/10
 ============================================================================
*/
 
#include<stdio.h>

#define MAX 100

int size=MAX+1;

void displayHeap(int*, int);

void heapify(int a[])
{
	int i, j, parent,temp;
	for(i=1;i<size;++i)
	{
		j=i;
		while(j>0)
		{
			parent=(j-1)/2;
			if(a[j]<a[parent])
			{
				temp=a[j];
				a[j]=a[parent];
				a[parent]=temp;
				j=parent;
			}
			else
				break;			
		}
	}
}

void removeRoot(int a[])
{
	int child_1, child_2, parent, temp;
	temp=a[0];
	a[0]=a[size-1];
	a[size-1]=temp;
	size--;
	parent=0;
	while((2*parent+2)<size)
	{
		child_1=2*parent+1;
		child_2=2*parent+2;
		if((a[child_1]<=a[child_2])&&(a[child_1]<a[parent]))
		{	
			temp=a[child_1];
			a[child_1]=a[parent];
			a[parent]=temp;
			parent=child_1;
		}
		else if((a[child_2]<a[child_1])&&(a[child_2]<a[parent]))
		{	
			temp=a[child_2];
			a[child_2]=a[parent];
			a[parent]=temp;
			parent=child_2;
		}
		else
		{
			return;
		}
	}
	
}

void displayHeap(int a[], int size)
{
	int i;
	for(i=0; i<size; ++i)
	{
		printf("%d ", a[i]);
	}
}

int main()
{
	int a[MAX], i;
	
	printf("Heap Sort in an Array\n\n");
	
	while(size>MAX)
	{
		printf("Enter size[max 100]:");
		scanf("%d",&size);
	}
	
	for(i=0; i<size; ++i)
	{
		printf("Enter value %d:", i+1);
		scanf("%d",&a[i]);
	}
		
	printf("\nArray before being sorted:  ");
	displayHeap(a, size);
	
	heapify(a);
	printf("\nArray converted to heap:  ");
	displayHeap(a, size);

	int n=size;
	
	for(i=0; i<n; ++i)
	{
		removeRoot(a);
	}
	
	size=n;
	
	printf("\nSorted Array:  ");
	displayHeap(a, size);
	
	return 0;
}
