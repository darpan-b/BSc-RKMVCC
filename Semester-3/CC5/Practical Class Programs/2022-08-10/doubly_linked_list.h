#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *previous;
    struct node *next;
} node;


node *create_node(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->previous = NULL;
    newnode->next = NULL;
    return newnode;
}

void print(node *head)
{
    printf("List is: ");
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%d ", tmp->data);
    }
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
        newnode->next = *head;
        (*head)->previous = newnode;
        *head = newnode;
        return;
    }
    int i = 0;
    node *tmp = *head;
    for (; i < pos - 1 && tmp->next != NULL; i++, tmp = tmp->next);
    newnode->next = tmp->next;
    newnode->previous = tmp;
    tmp->next = newnode;
}

void delete(node **head, int pos)
{
    if (*head == NULL) return;
    if (pos == 0)
    {
        node *temp = *head;
        if (temp->next != NULL) temp->previous = NULL;
        *head = (*head)->next;
        free(temp);
        return;
    }
    int i = 0;
    node *tmp = *head;
    for (; i < pos && tmp->next != NULL; i++, tmp = tmp->next);
    if (tmp->previous != NULL) tmp->previous->next = tmp->next;
    if (tmp->next != NULL) tmp->next->previous = tmp->previous;
    free(tmp);
}

void reverse(node **head)
{
    node *temp;
    for (node *tmp = *head; tmp != NULL; tmp = tmp->previous)
    {
        if (tmp->next == NULL) temp = tmp;
        node *temp1 = tmp->next;
        tmp->next = tmp->previous;
        tmp->previous = temp1;
    }
    *head = temp;
}
