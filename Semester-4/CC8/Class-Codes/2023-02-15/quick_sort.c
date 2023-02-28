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

int main() {
  printf("Enter the size of the array:\n");
  int n;
  scanf("%d", &n);
  int* arr = (int*) malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 10000;
  }
  printf("Initial array = ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  quick_sort(arr, 0, n - 1);
  printf("Sorted array = ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
