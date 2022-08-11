#include <stdio.h>
#include <stdlib.h>

/* Structure of a node in the linked list. */
typedef struct node
{
    int data;              /* data stored in the node */
    struct node *previous; /* link to the previous node */
    struct node *next;     /* link to the next node */
} node;

/* Creates a new node with the given data. */
node * create_node(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->previous = NULL;
}

/* Prints the linked list. */
void print(node *head)
{
    printf("List is: ");
    for (node *temp = head; temp != NULL; temp = temp->next) printf("%d ", temp->data);
    printf("\n");
}

/* Inserts a node with the given data at the specified position (0-indexed).
   If the position is less than 0, it inserts the node at the beginning, and
   if the position is greater than the size of the list, it inserts the node
   at the end of the list. */
void insert(node **head, int data, int pos)
{
    node *newnode = create_node(data);
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    if (pos <= 0)
    {
        (*head)->previous = newnode;
        newnode->next = *head;
        *head = newnode;
        return;
    }
    int curpos = 0;
    node *temp = *head;
    for (; curpos < pos - 1 && temp->next != NULL; curpos++, temp = temp->next);
    newnode->next = temp->next;
    temp->next = newnode;
    if (newnode->next != NULL) newnode->next->previous = newnode;
    newnode->previous = temp;
}

/* Deletes the node present at the specified position (0-indexed).
   If the position is less than 0, it deletes the first node, and
   if the position is greater than the size of the list, it deletes
   the last node in the list. */
void delete(node **head, int pos)
{
    if (*head == NULL) return;
    if (pos <= 0)
    {
        node *temp = *head;
        *head = (*head)->next;
        if (*head != NULL) (*head)->previous = NULL;
        free(temp);
        return;
    }
    int curpos = 0;
    node *temp = *head;
    for (; curpos < pos && temp->next != NULL; curpos++, temp = temp->next);
    if (temp->previous != NULL) temp->previous->next = temp->next;
    if (temp->next != NULL) temp->next->previous = temp->previous;
    free(temp);
}

/* Reverses the list. */
void reverse(node **head)
{
    node *temp = *head;
    node *lastnode = NULL;
    for (; temp != NULL; temp = temp->previous)
    {
        node *tnode = temp->next;
        temp->next = temp->previous;
        temp->previous = tnode;
        lastnode = temp;
    }
    *head = lastnode;
}

/* Searches for an element in the list using linear search algorithm.
   If the search key is found in the list, it returns the index of the
   first occurrence of the search key in the list. If the search key is
   not found in the list, it returns -1. */
int linear_search(node *head, int key)
{
    int index = 0;
    node *temp = head;
    for (; temp != NULL; index++, temp = temp->next)
    {
        if (temp->data == key) return index;
    }
    return -1;
}
