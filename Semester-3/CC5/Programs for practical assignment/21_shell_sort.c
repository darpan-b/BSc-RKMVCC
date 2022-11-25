#include <stdio.h>
#include <stdlib.h>
int main(){
  printf("Enter number of elements in the array:\n");
  int n;
  scanf("%d", &n);
  int* a = (int*)malloc(sizeof(int)*n);
  printf("Enter the elements of the array:\n");
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  for(int gap = n/2; gap > 0; gap /= 2){
    for(int i = gap; i < n; i += 1){
      int temp = a[i],j;
      for(j=i;j>=gap&&a[j-gap]>temp; j-=gap) a[j] = a[j-gap];
      a[j] = temp;
    }
  }
  printf("Sorted array = ");
  for(int i = 0; i < n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
