#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y, *y = temp;
}

int partition(int* arr, int lo, int hi) {
    int pivot = arr[hi], cidx = lo;
    for (int i = lo; i <= hi; i++) {
        if (arr[i] < pivot) swap(&arr[i], &arr[cidx++]);
    }
    swap(&arr[cidx], &arr[hi]);
    return cidx;
}

void quick_sort(int* arr, int lo, int hi) {
    if (lo >= hi) return;
    int fixed = partition(arr, lo, hi);
    quick_sort(arr, lo, fixed - 1), quick_sort(arr, fixed + 1, hi);
}

int main() {
    printf("Enter the number of elements in the array:\n");
    int len; scanf("%d", &len);
    int* arr = (int*)malloc(sizeof(int) * len);
    printf("Enter %d elements\n", len);
    for (int i = 0; i < len; i++) scanf("%d", &arr[i]);
    quick_sort(arr, 0, len - 1);
    printf("Sorted array = ");
    for (int i = 0; i < len; i++) printf("%d ", arr[i]); printf("\n");
    return 0;
}
