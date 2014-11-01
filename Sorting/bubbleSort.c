/*
 ============================================================================
 Description : Bubble Sort in an array
 Author      : Somnath Saha 
 Roll no.    : 529/IC/10
 ============================================================================
*/

#include <stdio.h>
#define MAX_SIZE 100

void bubbleSort(int a[], int size)
{
	int i, j, temp;
	
	for(i=0; i<size; ++i)
	{
		for(j=0; j<size-i-1; ++j)
		{
				if(a[j]>a[j+1])
				{
					temp=a[j+1];
					a[j+1]=a[j];
					a[j]=temp;
				}
				////For observing the steps:
				//printf("\nIteration at i=%d j=%d: ", i, j);
				//int k;
				//for(k=0; k<size; ++k)
				//{
					//printf("%d ", a[k]);
				//}
		}	
	}
}

int main()
{
	int a[MAX_SIZE], i, size=MAX_SIZE+1;
	
	printf("Bubble Sort in an Array\n\n");
	
	while(size>MAX_SIZE)
	{
		printf("Enter size[max %d]:", MAX_SIZE);
		scanf("%d",&size);
	}
	
	for(i=0; i<size; ++i)
	{
		printf("Enter value %d:", i+1);
		scanf("%d",&a[i]);
	}
		
	bubbleSort(a,size);
	
	printf("\nArray after being sorted:  ");
	for(i=0; i<size; ++i)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}
