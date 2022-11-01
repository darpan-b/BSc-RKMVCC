#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Enter number of elements in the array:\n");
	int n;
	scanf("%d", &n);
	int* a = (int*)malloc(sizeof(int)*n);
	printf("Enter the elements of the array:\n");
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	// doing selection sort
	for(int i = 0; i < n; i++)
	{
		int minidx = i;
		for(int j = i+1; j < n; j++)
		{
			if(a[j] < a[minidx]) minidx = j;
		}
		int temp = a[minidx];
		a[minidx] = a[i];
		a[i] = temp;
	}
	
	printf("Sorted array = ");
	for(int i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
}
