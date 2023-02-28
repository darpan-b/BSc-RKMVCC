#include <stdio.h>
#include <stdlib.h>
static int counter = 0;
void merge(int* arr, int lo, int mid, int hi) {
    int s1 = mid - lo + 1; counter++;
    int s2 = hi - mid; counter++;
    int* arr1 = (int*) malloc(sizeof(int) * s1); counter += s1;
    int* arr2 = (int*) malloc(sizeof(int) * s2); counter += s2;
    for (int i = 0; i < s1; i++) {
        arr1[i] = arr[i + lo]; counter++;
    }
    for (int i = 0; i < s2; i++) {
        arr2[i] = arr[i + mid + 1]; counter++;
    }
    int ptr1 = 0, ptr2 = 0; counter++;
    for (int i = lo; i <= hi; i++) {
        if (ptr1 >= s1) {
            arr[i] = arr2[ptr2]; counter++;
            ptr2++; counter++;
        }
        else if (ptr2 >= s2) {
            arr[i] = arr1[ptr1]; counter++;
            ptr1++; counter++;
        }
        else {
            if (arr1[ptr1] < arr2[ptr2]) {
                arr[i] = arr1[ptr1]; counter++;
                ptr1++; counter++;
            }
            else {
                arr[i] = arr2[ptr2]; counter++;
                ptr2++; counter++;
            }
        }
    }
}

void merge_sort(int* arr, int lo, int hi) {
    if (lo >= hi) {
        return; counter++;
    }
    int mid = (lo + hi) / 2; counter++;
    merge_sort(arr, lo, mid); counter++;
    merge_sort(arr, mid + 1, hi); counter++;
    merge(arr, lo, mid, hi); counter++;
}

int main() {
    printf("Enter the number of elements in the array:\n"); //counter++;
    int n; //counter++;
    scanf("%d", &n); //counter++;
    int* arr = (int*) malloc(sizeof(int) * n); //counter += n;
    printf("Enter %d numbers:\n", n); //counter++;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); //counter++;
    }
    merge_sort(arr, 0, n - 1); //counter++;
    printf("Sorted array = "); //counter++;
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); //counter++;
    }
    printf("\n"); //counter++;
    printf("counter = %d\n", counter);
    return 0;
}
