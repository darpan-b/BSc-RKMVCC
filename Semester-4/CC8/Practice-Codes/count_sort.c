#include <stdio.h>
#include <stdlib.h>

int max(int x, int y) { return x > y ? x : y; }

void count_sort(int* arr, int n) {
    int maxele = 0;
    for (int i = 0; i < n; i++) maxele = max(maxele, arr[i]);
    int* count = (int*)calloc((maxele + 1), sizeof(int));
    for (int i = 0; i < n; i++) count[arr[i]]++;
    for (int i = 1; i <= maxele; i++) count[i] += count[i - 1];
    int* other = (int*)malloc(sizeof(int) * n);
    for (int i = n - 1; i >= 0; i--) other[--count[arr[i]]] = arr[i];
    for (int i = 0; i < n; i++) arr[i] = other[i];
}

int main() {
    printf("Enter the number of elements in the array:\n");
    int len; scanf("%d", &len);
    int* arr = (int*)malloc(sizeof(int) * len);
    printf("Enter %d elements\n", len);
    for (int i = 0; i < len; i++) scanf("%d", &arr[i]);
    count_sort(arr, len);
    printf("Sorted array = ");
    for (int i = 0; i < len; i++) printf("%d ", arr[i]); printf("\n");
    return 0;
}
