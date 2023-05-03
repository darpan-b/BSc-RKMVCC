#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1], arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    printf("Enter the number of elements in the array:\n");
    int len; scanf("%d", &len);
    int* arr = (int*)malloc(sizeof(int) * len);
    printf("Enter %d elements\n", len);
    for (int i = 0; i < len; i++) scanf("%d", &arr[i]);
    bubble_sort(arr, len);
    printf("Sorted array = ");
    for (int i = 0; i < len; i++) printf("%d ", arr[i]); printf("\n");
    return 0;
}
