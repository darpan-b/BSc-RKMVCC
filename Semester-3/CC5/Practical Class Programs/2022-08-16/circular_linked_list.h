// NOT DONE

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    node *next;
} node;

// maintain both head and tail

node * create_node(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
}

void print(node *head)
{
    printf("List is: ");
    for (node *temp = head; temp->next != head; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    printf("\n");
}

void insert_at_beginning(int data, node **tail)
{
}
