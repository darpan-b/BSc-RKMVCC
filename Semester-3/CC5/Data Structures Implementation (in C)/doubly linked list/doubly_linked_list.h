#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *previous;
    struct node *next;
} node;

node * create_node(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->previous = NULL;
}

void print(node *head)
{
    printf("List is: ");
    for (node *temp = head; temp != NULL; temp = temp->next) printf("%d ", temp->data);
    printf("\n");
}

void insert(node **head, int data, int pos)
{
    node *newnode = create_node(data);
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    if (pos == 0)
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

void delete(node **head, int pos)
{
    if (*head == NULL) return;
    if (pos == 0)
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



