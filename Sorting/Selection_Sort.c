/*
 ============================================================================
 Description : Selection Sort in an array
 Author      : Somnath Saha 
 Roll no.    : 529/IC/10
 ============================================================================
*/

#include <stdio.h>
#define SIZE 100

void SelectionSort(int a[], int size)
{
	int i, pos, j, temp;
	for(i=0; i<size; ++i)
	{
		pos=i; 
		for(j=i+1; j<size; ++j)
		{
			if(a[j]<a[pos])
			{
				pos=j;
			}
		}
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;		
	}
}

int main()
{
	int a[SIZE]={10,5,2,0,-1,-2000,0,5,9,4}, i;
	
	printf("Selection Sort in an Array\n\n");
		
	//for(i=0; i<SIZE; ++i)
	//{
		//printf("Enter value %d:", i+1);
		//scanf("%d",&a[i]);
	//}	
		
	SelectionSort(a, SIZE);
	
	printf("\nArray after being sorted:  ");
	for(i=0; i<SIZE; ++i)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}
