#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node * create_node(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void print(node *head)
{
    printf("List is :");
    if (head == NULL) return;
    node *tmp = head;
    for (; tmp->next != head; tmp = tmp->next) printf("%d ", tmp->data);
    printf("%d\n", tmp->data);
}

void insert_node(node **head, int data, int position)
{
    node *newnode = create_node(data);
    if (*head == NULL)
    {
        printf("meow!\n");
        // KI PROBLEM HOCCHE?
        newnode->next = newnode;
        *head = newnode;
        printf("head data = %d\n", (*head)->data);
        return;
    }
    if (position == 0)
    {
        node *tmp = *head;
        while (tmp->next != *head) tmp = tmp->next;
        tmp->next = newnode;
        newnode->next = *head;
        *head = newnode;
        return;
    }
    node *tmp = *head;
    int i = 0;
    for (i = 0; tmp->next != *head && i < position - 1; i++, tmp = tmp->next);
    newnode->next = tmp->next;
    tmp->next = newnode;
}

void delete_node(node **head, int position)
{
    if (*head == NULL) return;
    if (position == 0)
    {
        node *tmp = *head;
        while (tmp->next != *head) tmp = tmp->next;
        tmp->next = (*head)->next;
        node *todel = *head;
        *head = (*head)->next;
        free(todel);
        return;
    }
    node *tmp = *head;
    int i = 0;
    for (i = 0; tmp->next != *head && i < position - 1; i++, tmp = tmp->next);
    node *todel = tmp->next;
    tmp->next = tmp->next->next;
    free(todel);
}
