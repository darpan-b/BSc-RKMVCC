#include <stdio.h>
#include <stdlib.h>

int* count_sort(int* arr, int n){
    int maxele = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > maxele){
            maxele = arr[i];
        }
    }
    int* count = (int*)calloc(maxele + 1, sizeof(int));
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }
    for(int i = 1; i <= maxele; i++){
        count[i] += count[i - 1];
    }
    int* answer = (int*)malloc(sizeof(int) * n);
    for(int i = n - 1; i >= 0; i--){
        int cidx = count[arr[i]];
        answer[cidx - 1] = arr[i];
        count[arr[i]]--;
    }
    return answer;
}

int main(){
    printf("Enter the number of elements:\n");
    int n;
    scanf("%d", &n);
    printf("Enter %d numbers:\n", n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int* answer = count_sort(arr, n);
    printf("Sorted array = ");
    for(int i = 0; i < n; i++){
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}
