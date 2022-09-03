// NOT WORKING (WHY?)

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;


node * create_node(int data)
{
	node *newnode=(node *)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

void print(node *head)
{
	if(head==NULL) return;
	printf("List is: ");
	node *tmp=head;
	for(; tmp->next!=head; tmp=tmp->next) printf("%d ",tmp->data);
	printf("%d\n",tmp->data);
}

void insert_node(node **head,int data,int position)
{
	node *newnode=create_node(data);
	if(*head==NULL)
	{
		newnode->next=newnode;
		*head=newnode;
		return;
	}
	if(position==0)
	{
		node *lastnode=*head;
		while(lastnode->next!=*head) lastnode=lastnode->next;
		lastnode->next=newnode;
		newnode->next=*head;
		*head=newnode;
		return;
	}
	int i=0;
	node *tmp=*head;
	for(; i<position-1&&tmp->next!=*head; i++,tmp=tmp->next);
	newnode->next=tmp->next;
	tmp->next=newnode;
}

void delete_node(node **head,int position)
{
	if(*head==NULL) return;
	if(position==0)
	{
		node *lastnode=*head;
		while(lastnode->next!=*head) lastnode=lastnode->next;
		lastnode->next=(*head)->next;
		node *tmp=*head;
		*head=(*head)->next;
		free(tmp);
		return;
	}
	int i=0;
	node *tmp=*head;
	for(; i<position-1&&tmp->next!=*head; i++,tmp=tmp->next);
	node *todel=tmp->next;
	tmp->next=tmp->next->next;
	free(todel);
}
