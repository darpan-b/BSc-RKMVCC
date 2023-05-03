#include <stdio.h>
#include <stdlib.h>

int max(int x, int y) { return x > y ? x : y; }

void insertion_sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int value = arr[i], position = i;
        while (position > 0 && arr[position - 1] > value) {
            arr[position] = arr[position - 1]; --position;
        }
        arr[position] = value;
    }
}

void bucket_sort(int* arr, int n) {
    int max_digits = 0;
    for (int i = 0; i < n; i++) {
        int curdigits = 0, temp = arr[i];
        while (temp > 0) curdigits++, temp /= 10;
        max_digits = max(max_digits, curdigits);
    }
    int* count_per_digit = (int*)calloc(10, sizeof(int));
    for (int i = 0; i < n; i++) {
        int temp = arr[i], times = 0;
        while (times++ < max_digits) temp /= 10;
        count_per_digit[temp]++;
    }
    int** other_array = (int**)malloc(sizeof(int*) * 10);
    for (int i = 0; i < 10; i++) other_array[i] = (int*)malloc(sizeof(int) * count_per_digit[i]);
    int* cur_ptr = (int*)calloc(10, sizeof(int));
    for (int i = 0; i < n; i++) {
        int times = 0, top_dig = arr[i];
        while (times++ < max_digits) top_dig /= 10;
        other_array[top_dig][cur_ptr[top_dig]++] = arr[i];
    }
    for (int i = 0; i < 10; i++) insertion_sort(other_array[i], count_per_digit[i]);
    int cidx = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < count_per_digit[i]; j++) arr[cidx++] = other_array[i][j];
    }
}

int main() {
    printf("Enter the number of elements in the array:\n");
    int len; scanf("%d", &len);
    int* arr = (int*)malloc(sizeof(int) * len);
    printf("Enter %d elements\n", len);
    for (int i = 0; i < len; i++) scanf("%d", &arr[i]);
    bucket_sort(arr, len);
    printf("Sorted array = ");
    for (int i = 0; i < len; i++) printf("%d ", arr[i]); printf("\n");
    return 0;
}
