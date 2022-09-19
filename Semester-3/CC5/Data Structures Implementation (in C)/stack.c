#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;	
} node;

node* create_node(int data)
{
	node* newnode = (node*) malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

node* head = NULL;

void push(int data)
{
	node* newnode = create_node(data);
	if(head == NULL)
	{
		head = newnode;
		return;
	}
	newnode->next = head;
	head = newnode;
}

void pop()
{
	if(head == NULL) return;
	node* tmp = head;
	head = head->next;
	free(tmp);
}

int peek()
{
	if(head == NULL) return -1;
	return head->data;
}

int main()
{
	while(1)
	{
		printf("Press 1 to push element in stack.\n");
		printf("Press 2 to pop element from stack.\n");
		printf("Press 3 to peek.\n");
		printf("Press any other integer to exit.\n");
		printf("Enter your choice:\n");
		int choice;
		scanf("%d", &choice);
		
		switch(choice)
		{
		case 1:
		{
			printf("Enter the data that you want to push:\n");
			int data;
			scanf("%d", &data);
			push(data);
			break;
		}
		case 2:
		{
			pop();
			break;
		}
		case 3:
		{
			printf("Top element = %d\n", peek());
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
	return 0;
}
