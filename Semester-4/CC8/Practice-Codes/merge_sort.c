#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int lo, int mid, int hi) {
    int s1 = mid - lo + 1;
    int s2 = hi - mid;
    int* arr1 = (int*) malloc(sizeof(int) * s1);
    int* arr2 = (int*) malloc(sizeof(int) * s2);
    for (int i = 0; i < s1; i++) {
        arr1[i] = arr[i + lo];
    }
    for (int i = 0; i < s2; i++) {
        arr2[i] = arr[i + mid + 1];
    }
    int ptr1 = 0, ptr2 = 0;
    for (int i = lo; i <= hi; i++) {
        if (ptr1 >= s1) {
            arr[i] = arr2[ptr2];
            ptr2++;
        }
        else if (ptr2 >= s2) {
            arr[i] = arr1[ptr1];
            ptr1++;
        }
        else {
            if (arr1[ptr1] < arr2[ptr2]) {
                arr[i] = arr1[ptr1];
                ptr1++;
            }
            else {
                arr[i] = arr2[ptr2];
                ptr2++;
            }
        }
    }
}

void merge_sort(int* arr, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int mid = (lo + hi) / 2;
    merge_sort(arr, lo, mid);
    merge_sort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}

int main() {
    printf("Enter the number of elements in the array:\n");
    int n;
    scanf("%d", &n);
    int* arr = (int*) malloc(sizeof(int) * n);
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, 0, n - 1);
    printf("Sorted array = ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
