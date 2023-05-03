#include <stdio.h>
#include <stdlib.h>

void radix_sort(int* arr, int n) {
    for (int bit = 0; bit < 30; bit++) {
        int count[] = {0, 0};
        for (int i = 0; i < n; i++) count[(arr[i] & (1 << bit)) > 0]++;
        count[1] += count[0];
        int* other = (int*)malloc(sizeof(int) * n);
        for (int i = n - 1; i >= 0; i--) other[--count[(arr[i] & (1 << bit)) > 0]] = arr[i];
        for (int i = 0; i < n; i++) arr[i] = other[i];
    }
}

int main() {
    printf("Enter the number of elements in the array:\n");
    int len; scanf("%d", &len);
    int* arr = (int*)malloc(sizeof(int) * len);
    printf("Enter %d elements\n", len);
    for (int i = 0; i < len; i++) scanf("%d", &arr[i]);
    radix_sort(arr, len);
    printf("Sorted array = ");
    for (int i = 0; i < len; i++) printf("%d ", arr[i]); printf("\n");
    return 0;
}
