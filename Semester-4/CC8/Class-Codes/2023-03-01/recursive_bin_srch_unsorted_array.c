#include <stdio.h>
#include <stdlib.h>

void swap(int* lhs, int* rhs) {
    int k = *lhs;
    *lhs = *rhs;
    *rhs = k;
}

int partition(int* arr, int l, int h) {
    int pivot = arr[h];
    int cidx = l - 1;
    for (int i = l; i <= h; i++) {
        if (arr[i] < pivot) {
        cidx++;
        swap(&arr[i], &arr[cidx]);
        }
    }
    cidx++;
    swap(&arr[cidx], &arr[h]);
    return cidx;
}

void quick_sort(int* arr, int l, int h) {
    if (l >= h) {
        return;
    }
    int k = partition(arr, l, h);
    quick_sort(arr, l, k - 1);
    quick_sort(arr, k + 1, h);
}   

int binsrch(int* arr, int lo, int hi, int key){
    if(lo > hi){
        return 0;
    }
    int mid = (lo + hi) / 2;
    if(arr[mid] == key){
        return 1;
    }
    else if(arr[mid] > key){
        return binsrch(arr, lo, mid - 1, key);
    }
    else{
        return binsrch(arr, mid + 1, hi, key);
    }
}

int main(){
    printf("Enter the number of elements:\n");
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    printf("Enter the element to be searched:\n");
    int key;
    scanf("%d", &key);
    if(binsrch(arr, 0, n - 1, key)){
        printf("Element present in array\n");
    }
    else{
        printf("Element not present in array\n");
    }
    return 0;
}
