#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node * create_node(int data)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void print(node *head)
{
    if(head==NULL)
    {
        printf("MEOW!\n");
        return;
    }
    printf("List is = ");
    node* tmp=head;
    printf("%d ",tmp->data);
    for(tmp=head->next;tmp->next!=head;tmp=tmp->next)printf("%d ",tmp->data);
    printf("\n");
}

void insert_node(node **head,int data,int pos)
{
    node *newnode=create_node(data);
    if(*head==NULL)
    {
        *head=newnode;
        (*head)->next=newnode;
        printf("head data=%d next data=%d\n",(*head)->data,(*head)->next->data);
        return;
    }
    if(pos==0)
    {
        node *lastnode=*head;
        while(lastnode->next!=*head)lastnode=lastnode->next;
        lastnode->next=newnode;
        newnode->next=*head;
        *head=newnode;
        return;
    }
    node *tmp=*head;
    int i=0;
    while(i<pos-1&&tmp->next!=*head)tmp=tmp->next;
    newnode->next=tmp->next;
    tmp->next=newnode;
}

void delete_node(node **head,int pos)
{
    if(*head==NULL)return;
    if(pos==0)
    {
        node *lastnode=*head;
        while(lastnode->next!=*head)lastnode=lastnode->next;
        lastnode->next=(*head)->next->next;
        node *tmp=*head;
        *head=(*head)->next;
        free(tmp);
        return;
    }
    node *tmp=*head;
    int i=0;
    while(i<pos-1&&tmp->next!=*head)tmp=tmp->next;
    node *todel=tmp->next;
    tmp->next=tmp->next->next;
    free(todel);
}
