/*
 ============================================================================
 Description : Merge Sort in an array
 Author      : Somnath Saha 
 Roll no.    : 529/IC/10
 ============================================================================
*/

#include<stdio.h>

#define MAX 100

int size=MAX+1;

void displayArray(int*, int);
void merge(int*, int, int, int);

void mergeSort(int a[], int start, int end)
{
	int mid=(start+end)/2;
	if(start<end)
	{
		mergeSort(a, start, mid);
		mergeSort(a, mid+1, end);
		merge(a, start, mid, end); 
	}	
}

void merge(int *a, int start, int mid, int end)
{
	int b[MAX], p=start, q=mid+1, i=0, flg=0;

	while(i<=(end-start+1))
	{
		if(a[p]<=a[q])
		{
			b[i++]=a[p++];
			if(p==mid+1) 
			{
				flg=1;
				break;
			}
			
		}
		else
		{
			b[i++]=a[q++];
			if(q==end+1)
			{
				flg=2;
				break;
			}
		}			
	}
	if(flg==1)
	{
		while(q<=end)
		{
			b[i++]=a[q++];
		}
	}
	if(flg==2)
	{
		while(p<=mid)
		{
			b[i++]=a[p++];
		}
	}
	int j, k;
	for(j=start, k=0; k<i; k++, j++)
	{
		a[j]=b[k];
	}
}

void displayArray(int a[], int size)
{
	int i;
	for(i=0; i<size; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[MAX], i;
	
	printf("Merge Sort in an Array\n\n");
		
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
	displayArray(a, size);
	
	mergeSort(a, 0, size-1);
		
	printf("\nSorted Array:  ");
	displayArray(a, size);
	
	return 0;
}
