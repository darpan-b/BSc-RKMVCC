/**
 * @file linked_list.c
 * @author Darpan Bhattacharya
 * @brief Implementing a linked list in C
 * @date 2022-07-26
 * 
 */

#include <stdio.h>
#include <stdlib.h>


/* linked list node */
typedef struct Node
{
    int data;          /* data inside the node */
    struct Node* next; /* link to next node */
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head)
{
    if (head == NULL) printf("HOO");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtBeginning(Node** head, int data)
{
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int data)
{
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

void insertAtIndex(Node** head, int data, int index) /* 0-indexed */
{
    // inserts at end of linked list if size of list is less than index
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* temp = *head;
        if (index == 0) {
            insertAtBeginning(head, data);
            return;
        }
        int counter = 0;
        while (temp->next != NULL && counter < index - 1) {
            temp = temp->next;
            counter++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

/* all remove methods do nothing if the list is empty */

void removeFromBeginning(Node** head)
{
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void removeFromEnd(Node** head)
{
    if (*head == NULL) return;
    Node* temp = *head;
    if ((*head)->next == NULL) {
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) temp = temp->next;
    Node* lastNode = temp->next;
    free(lastNode);
    temp->next = NULL;
}

void removeFromIndex(Node** head, int index) /* 0-indexed */
{
    // does nothing if the linked list isn't large enough
    if (*head == NULL) return;
    int counter = 0;
    Node* temp = *head;
    while (temp->next != NULL && counter < index - 1) {
        temp = temp->next;
        counter++;
    }
    if (counter != index - 1) return;
    Node* nodeAtIndex = temp->next;
    temp->next = temp->next->next;
    free(nodeAtIndex);
}

int main()
{
    Node* head = NULL;
    insertAtBeginning(&head, 5);
    printList(head);
    insertAtBeginning(&head, 7);
    printList(head);
    insertAtEnd(&head, 12);
    printList(head);
    insertAtIndex(&head, 15, 0);
    printList(head);
    removeFromBeginning(&head);
    printList(head);
    removeFromIndex(&head, 2);
    printList(head);
    removeFromEnd(&head);
    printList(head);
}
