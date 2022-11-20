#include <stdio.h>
#include <stdlib.h>

int main(){
  printf("Enter the dimensions of the array:\n");
  int n1,n2,n3,n4,n5;
  scanf("%d%d%d%d%d", &n1,&n2,&n3,&n4,&n5);
  int***** arr;
  arr = (int*****)malloc(sizeof(int****)*n1);
  for(int i=0; i<n1; i++){
    arr[i] = (int****)malloc(sizeof(int***)*n2);
    for(int j=0; j<n2; j++){
      arr[i][j] = (int***)malloc(sizeof(int**)*n3);
      for(int k=0; k<n3; k++){
        arr[i][j][k] = (int**)malloc(sizeof(int*)*n4);
        for(int l=0; l<n4; l++){
          arr[i][j][k][l] = (int*)malloc(sizeof(int)*n5);
        }
      }
    }
  }
  printf("Enter the array elements:\n");
  for(int i=0; i<n1; i++){
    for(int j=0; j<n2; j++){
      for(int k=0; k<n3; k++){
        for(int l=0; l<n4; l++){
          for(int m=0; m<n5; m++){
            scanf("%d", &arr[i][j][k][l][m]);
          }
        }
      }
    }
  }
  printf("The array is:\n");
  for(int i=0; i<n1; i++){
    for(int j=0; j<n2; j++){
      for(int k=0; k<n3; k++){
        for(int l=0; l<n4; l++){
          for(int m=0; m<n5; m++){
            printf("%d ", arr[i][j][k][l][m]);
          }
          printf("\n");
        }
      }
    }
  }
  return 0;
}
