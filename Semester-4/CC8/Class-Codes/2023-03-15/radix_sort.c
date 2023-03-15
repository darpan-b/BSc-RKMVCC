#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Enter the number of elements in the array:\n");
	int size;
	scanf("%d", &size);
	int* arr = (int*)malloc(sizeof(int) * size);
	printf("Enter the elements of the array:\n");
	for(int i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}
	for(int i = 0; i < 30; i++){
		int count[2] = {0, 0};
		for(int j = 0; j < size; j++){
			count[((arr[j] & (1 << i)) > 0)]++;
		}
		count[1] += count[0];
		int* b = (int*)malloc(sizeof(int) * size);
		for(int j = size - 1; j >= 0; j--){
			int curbit = (arr[j] & (1 << i)) > 0;
			b[count[curbit] - 1] = arr[j];
			count[curbit]--;
		}
		arr = b;
	}
	printf("Sorted array = ");
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
