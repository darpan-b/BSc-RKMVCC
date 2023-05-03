#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int lo, int mid, int hi) {
    int* left_array = (int*)malloc(sizeof(int) * (mid - lo + 1));
    int* right_array = (int*)malloc(sizeof(int) * (hi - mid));
    for (int i = lo; i <= mid; i++) left_array[i - lo] = arr[i];
    for (int i = mid + 1; i <= hi; i++) right_array[i - mid - 1] = arr[i];
    int lptr = 0, rptr = 0, cidx = lo;
    while (lptr < (mid - lo + 1) || rptr < (hi - mid)) {
        if (lptr >= mid - lo + 1) arr[cidx++] = right_array[rptr++];
        else if (rptr >= hi - mid) arr[cidx++] = left_array[lptr++];
        else arr[cidx++] = (left_array[lptr] <= right_array[rptr] ? left_array[lptr++] : right_array[rptr++]);
    }
}
void merge_sort(int* arr, int lo, int hi) {
    if (lo >= hi) return;
    int mid = (lo + hi) / 2;
    merge_sort(arr, lo, mid); merge_sort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}

int main() {
    printf("Enter the number of elements in the array:\n");
    int len; scanf("%d", &len);
    int* arr = (int*)malloc(sizeof(int) * len);
    printf("Enter %d elements\n", len);
    for (int i = 0; i < len; i++) scanf("%d", &arr[i]);
    merge_sort(arr, 0, len - 1);
    printf("Sorted array = ");
    for (int i = 0; i < len; i++) printf("%d ", arr[i]); printf("\n");
    return 0;
}
