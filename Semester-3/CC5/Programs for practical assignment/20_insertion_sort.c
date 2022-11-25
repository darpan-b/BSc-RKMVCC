#include <stdio.h>
#include <stdlib.h>
int main(){
  printf("Enter number of elements in the array:\n");
  int n;
  scanf("%d", &n);
  int* a = (int*)malloc(sizeof(int)*n);
  printf("Enter the elements of the array:\n");
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  for(int i = 1; i < n; i++){
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key){
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
  }
  printf("Sorted array = ");
  for(int i = 0; i < n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
