/*
 ============================================================================
 Description : Binary Search in an array
 Author      : Somnath Saha 
 Roll no.    : 529/IC/10
 ============================================================================
*/

#include <stdio.h>

int binarySearch(int a[], int size, int item)
{
	int beg=0, last=size-1, mid=size/2;
	while(beg<=last)
	{
		mid=(beg+last)/2;
		if(item==a[mid])
			return mid;
		else if (item>a[mid])
		{
			beg=mid+1;
		}
		else
		{
			last=mid-1;
		}
	}
	return -1;
}

int main()
{
	int a[100], i, item, size=101;
	
	printf("Binary Search in an Array\n\n");
	
	while(size>100)
	{
		printf("Enter size[max 100]:");
		scanf("%d",&size);
	}
	
	for(i=0; i<size; ++i)
	{
		printf("Enter value %d:", i+1);
		scanf("%d",&a[i]);
	}
	
	printf("Enter item to search:");
	scanf("%d",&item);
	
	int val=binarySearch(a, size, item);
	
	if(val==-1)
	{
		printf("\n\nItem not found.");
	}
	else
	{
		printf("\n\nItem found at location %d.", val+1);
		return 1;
	}
		
	return 0;
}

