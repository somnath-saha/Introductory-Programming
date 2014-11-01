/*
 ============================================================================
 Description : Insertion Sort in an array
 Author      : Somnath Saha 
 Roll no.    : 529/IC/10
 ============================================================================
*/

#include <stdio.h>
#define MAX_SIZE 100

void displayArray(int a[], int size)
{
	int i;
	for(i=0; i<size; ++i)
	{
		printf("%d ", a[i]);
	}
}

void InsertionSort(int a[], int size)
{
	int i, j, key;		
	for(i=0; i<size; i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

int main()
{
	int a[MAX_SIZE], i, size=MAX_SIZE+1;
	
	printf("Insertion Sort in an Array\n\n");
	
	while(size>MAX_SIZE)
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
	displayArray(a, size);
	
	InsertionSort(a,size);
	
	printf("\nArray after being sorted:  ");
	displayArray(a, size);
	
	return 0;
}
