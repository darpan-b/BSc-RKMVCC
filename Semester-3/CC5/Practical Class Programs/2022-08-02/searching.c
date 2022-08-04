#include <stdio.h>
#include <stdlib.h>

/* linear search using array */
void linearSearchUsingArray(int* arr, int size, int key)
{
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }
    if (index != -1) printf("%d is present in the array at index %d\n", key, index);
    else printf("%d is not present in the array\n", key);
}

/* binary search using array */
void binarySearchUsingArray(int* arr, int size, int key)
{
    // This assumes that the array is sorted.
    // If the array is not sorted, this may produce incorrect results.
    int index = -1;
    int lo = 0, hi = size - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == key) {
            index = mid;
            break;
        }
        else if (arr[mid] < key) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }    
    if (index != -1) printf("%d is present in the array at index %d\n", key, index);
    else printf("%d is not present in the array\n", key);

}

/* linked list */
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
}

void insertAtEnd(Node** head, int data)
{
    Node* newNode = createNode(data);
    if ((*head) == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

int getValue(Node* head, int index)
{
    Node* temp = head;
    int currentIndex = 0;
    while (temp != NULL) {
        if (currentIndex == index) return temp->data;
        currentIndex++;
        temp = temp->next;
    }
    return -1;
}


/* linear search using linked list */
void linearSearchUsingLinkedList(Node* head, int key)
{
    Node* temp = head;
    int index = 0;
    int found = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            found = 1;
            break;
        }
        index++;
        temp = temp->next;
    }
    if (found == 1) printf("%d is present in the array at index %d\n", key, index);
    else printf("%d is not present in the array\n", key);
}

/* binary search using linked list */
void binarySearchUsingLinkedList(Node* head, int key)
{
    // This assumes that the list is sorted.
    // If the list is not sorted, this may produce incorrect results.
    int index = -1;
    int lo = 0, hi = -1;
    Node* temp = head;
    while (temp != NULL) {
        hi++;
        temp = temp->next;
    }
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (getValue(head, mid) == key) {
            index = mid;
            break;
        }
        else if (getValue(head, mid) < key) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    if (index != -1) printf("%d is present in the list at index %d\n", key, index);
    else printf("%d is not present in the list\n", key);
}

int main()
{
    int* arr = NULL;   /* array */
    Node* head = NULL; /* list */

    printf("SEARCHING IN AN ARRAY\n");
    printf("---------------------\n");
    printf("Enter the number of elements in the array:\n");
    int size;
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int) * size);
    printf("NOTE: If you want to perform binary search, please enter the elements sorted in non-decreasing order. Sorting ekhono obdi syllabus e asheni.\n");
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    printf("Press 1 to perform binary search, 2 to perform linear search, and any other key to exit.\n");
    printf("Enter your choice:\n");
    int choice;
    scanf("%d", &choice);
    printf("Enter the element to be searched in the array:\n")
    int key;
    scanf("%d", &key);
    if (choice == 2) linearSearchUsingArray(arr, size, key);
    else if (choice == 1) binarySearchUsingArray(arr, size, key);
    else exit(0);
    
    printf("\n\n");
    printf("SEARCHING IN A LINKED LIST\n");
    printf("--------------------------\n");
    printf("NOTE: If you want to perform binary search, please enter the elements sorted in non-decreasing order. Sorting ekhono obdi syllabus e asheni.\n");
    printf("Press -1 to stop adding elements.\n");
    while (1) {
        printf("Enter element to be added to the list:\n");
        int element;
        scanf("%d", &element);
        if (element == -1) break;
        insertAtEnd(&head, element);
    }
    printf("Press 1 to perform binary search, 2 to perform linear search, and any other key to exit.\n");
    printf("Enter your choice:\n");
    choice;
    scanf("%d", &choice);
    printf("Enter the element to be searched in the array:\n");
    key;
    scanf("%d", &key);
    if (choice == 2) linearSearchUsingLinkedList(head, key);
    else if (choice == 1) binarySearchUsingLinkedList(head, key);
    else exit(0);
    return 0;
}
