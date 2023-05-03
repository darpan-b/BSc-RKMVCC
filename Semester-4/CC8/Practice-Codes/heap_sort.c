#include <stdio.h>
#include <stdlib.h>

void max_heapify(int* arr, int cidx) {
    int curridx = 1;
    while (curridx < cidx) {
        int lchild = 2 * curridx, rchild = 2 * curridx + 1, largest = curridx;
        largest = (lchild <= cidx && arr[lchild] > arr[curridx] ? lchild : curridx);
        largest = (rchild <= cidx && arr[rchild] > arr[largest] ? rchild : largest);
        if (largest == curridx) break;
        int temp = arr[curridx];
        arr[curridx] = arr[largest], arr[largest] = temp, curridx = largest;
    }
}

void heap_sort(int* arr, int n) { // arr is 1-indexed
    max_heapify(arr, n);
    for (int i = n; i > 1; i--) {
        int temp = arr[i];
        arr[i] = arr[1], arr[1] = temp;
        max_heapify(arr, i - 1);
    }
}

int main() {
    printf("Enter the number of elements in the array:\n");
    int len; scanf("%d", &len);
    int* arr = (int*)malloc(sizeof(int) * (len + 1));
    printf("Enter %d elements\n", len);
    for (int i = 1; i <= len; i++) scanf("%d", &arr[i]);
    heap_sort(arr, len);
    printf("Sorted array = ");
    for (int i = 1; i <= len; i++) printf("%d ", arr[i]); printf("\n");
    return 0;
}
