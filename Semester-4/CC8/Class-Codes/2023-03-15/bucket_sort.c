#include <stdio.h>
#include <stdlib.h>

int xp(int x, int p){
    if(p == 0){
        return 1;
    }
    int res = xp(x, p / 2);
    res *= res;
    if(p & 1){
        res *= x;
    }
    return res;
}

int main(){
    printf("Enter the number of elements in the array:\n");
    int size;
    scanf("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size);
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    int** groups = (int**)malloc(sizeof(int*) * 10);
    int max_digits = 0;
    for(int i = 0; i < size; i++){
        int curdig = 0;
        int curele = arr[i];
        while(curele > 0){
            curele /= 10;
            curdig++;
        }
        if(curdig > max_digits){
            max_digits = curdig;
        }
    }
    int* count_per_dig = (int*)calloc(10, sizeof(int));
    for(int i = 0; i < size; i++){
        count_per_dig[arr[i] / xp(10, max_digits - 1)]++;
    }
    for(int i = 0; i < 10; i++){
        groups[i] = (int*)calloc(count_per_dig[i] + 1, sizeof(int));
    }
    int* cidx = (int*)calloc(10, sizeof(int));
    for(int i = 0; i < size; i++){
        groups[arr[i] / xp(10, max_digits - 1)][cidx[arr[i] / xp(10, max_digits - 1)]++] = arr[i];
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < count_per_dig[i]; j++){
            int minidx = j;
            for(int k = j + 1; k < count_per_dig[i]; k++){
                if(groups[i][minidx] > groups[i][k]){
                    minidx = k;
                }
            }
            int temp = groups[i][j];
            groups[i][j] = groups[i][minidx];
            groups[i][minidx] = temp;
        }
    }
    int* answer = (int*)malloc(sizeof(int) * size);
    int aidx = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < count_per_dig[i]; j++){
            answer[aidx++] = groups[i][j];
        } 
    }
    printf("Sorted array = ");
    for(int i = 0; i < size; i++){
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}
