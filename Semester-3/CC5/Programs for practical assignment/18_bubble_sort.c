#include <stdio.h>
#include <stdlib.h>
int main(){
  printf("Enter number of elements in the array:\n");
  int n;
  scanf("%d", &n);
  int* a = (int*)malloc(sizeof(int)*n);
  printf("Enter the elements of the array:\n");
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  for(int i=0; i<n; i++){
    for(int j=0; j<n-i-1; j++){
      if(a[j] > a[j+1]){
        int temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;
      }
    }
  }
  printf("Sorted array = ");
  for(int i = 0; i < n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
