#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int value = arr[i], position = i;
        while (position > 0 && arr[position - 1] > value) {
            arr[position] = arr[position - 1]; --position;
        }
        arr[position] = value;
    }
}

int main() {
    printf("Enter the number of elements in the array:\n");
    int len; scanf("%d", &len);
    int* arr = (int*)malloc(sizeof(int) * len);
    printf("Enter %d elements\n", len);
    for (int i = 0; i < len; i++) scanf("%d", &arr[i]);
    insertion_sort(arr, len);
    printf("Sorted array = ");
    for (int i = 0; i < len; i++) printf("%d ", arr[i]); printf("\n");
    return 0;
}
