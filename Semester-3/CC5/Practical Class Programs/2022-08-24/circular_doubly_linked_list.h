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
    newnode->previous = NULL;
    newnode->next = NULL;
}

void print(node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    printf("Linked list is: ");
    node *tmp = head;
    for (; tmp->next != head; tmp = tmp->next)
    {
        printf("%d ", tmp->data);
    }
    printf("%d\n", tmp->data);
}

void insert(int data, int position, node **head)
{
    node *newnode = create_node(data);
    if (*head == NULL)
    {
        newnode->previous = newnode;
        newnode->next = newnode;
        *head = newnode;
        return;
    }
    if (position == 0)
    {
        newnode->next = *head;
        newnode->previous = (*head)->previous;
        (*head)->previous = newnode;
        newnode->previous->next = newnode;
        *head = newnode;
        return;
    }
    node *tmp = *head;
    int i = 0;
    for (tmp = *head; tmp->next != *head && i < position - 1; tmp = tmp->next, i++);
    newnode->previous = tmp;
    newnode->next = tmp->next;
    tmp->next = newnode;
    newnode->next->previous = newnode;
}

void delete(int position, node **head)
{
    if (*head == NULL) return;
    node *tmp;
    int i = 0;
    for (tmp = *head; tmp->next != *head && i < position; tmp = tmp->next, i++);
    tmp->next->previous = tmp->previous;
    tmp->previous->next = tmp->next;
    if (tmp == *head)
    {
        if (tmp->next != tmp) *head = tmp->next;
        else *head = NULL;
    }
    free(tmp);
}

void reverse(node **head)
{
    node *lastnode = (*head)->previous;
    node *temp;
    for (node *tmp = *head; ; tmp = tmp->previous)
    {
        if (tmp->next == NULL) temp = tmp;
        node *temp1 = tmp->next;
        tmp->next = tmp->previous;
        tmp->previous = temp1;
        if (tmp->previous == *head)
        {
            *head = tmp;
            return;
        }
    }
}
