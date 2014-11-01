/*
 ============================================================================
 Description : Sequential Search in an array (for array of size 10)
 Author      : Somnath Saha 
 Roll no.    : 529/IC/10
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int a[10], i, item, flg=0;
	
	printf("Sequential Search in an Array\n\n");
		
	for(i=0; i<10; ++i)
	{
		printf("Enter value at location %d:", i);
		scanf("%d",&a[i]);
	}
	
	printf("\nEnter item value to search: ");
	scanf("%d",&item);
		
	for(i=0; i<10; ++i)
	{
		if(item==a[i])
		{
			printf("\nItem found at location %d.", i);
			flg=1;
			break;
		}
	}	
	if (flg==0)
	{
		printf("\nItem wasn't found in the array.");
	}
	return 0;
}
