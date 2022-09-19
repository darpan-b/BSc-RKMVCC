#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* prev;
	struct node* next;
} node;

node* head = NULL;

void print()
{
	printf("List is: ");
	for(node* tmp = head; tmp != NULL; tmp = tmp->next)
	{
		printf("%d ", tmp->data);
	}
	printf("\n");
}

void insert(int data, int pos)
{
	node* newnode = (node*) malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;

	if(head == NULL)
	{
		head = newnode;
		return;
	}
	if(pos == 0)
	{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
		return;
	}
	int idx = 0;
	node* tmp = head;
	for(; idx < pos-1 && tmp->next != NULL; idx++, tmp = tmp->next);
	newnode->next = tmp->next;
	newnode->prev = tmp;
	tmp->next = newnode;
	if(newnode->next != NULL) newnode->next->prev = newnode;
}

void delete(int pos)
{
	if(head == NULL) return;
	if(pos == 0)
	{
		node* tmp = head;
		head = head->next;
		if(head != NULL) head->prev = NULL;
		free(tmp);
		return;
	}

	int idx = 0;
	node* tmp = head;
	for(; idx < pos-1 && tmp->next != NULL; idx++, tmp = tmp->next);
	if(tmp->next == NULL)
	{
		if(tmp->prev != NULL) tmp->prev->next = NULL;
		free(tmp);
		return;
	}
	node* todel = tmp->next;
	tmp->next = tmp->next->next;
	if(tmp->next != NULL) tmp->next->prev = tmp;
	free(todel);
}

void reverse()
{
	node* tmp = head;
	for(; tmp != NULL; tmp = tmp->prev)
	{
		node* tswap = tmp->next;
		tmp->next = tmp->prev;
		tmp->prev = tswap;
		if(tmp->prev == NULL) head = tmp;
	}
}

int main()
{
	while(1)
	{
		printf("Press 1 to enter data into the list.\n");
		printf("Press 2 to delete element from the list.\n");
		printf("Press 3 to print the list.\n");
		printf("Press 4 to reverse the list.\n");
		printf("Press any other key to exit.\n");
		printf("Enter your choice:\n");
		int choice;
		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
		{
			printf("Enter the data that you want to insert in the list:\n");
			int data;
			scanf("%d", &data);
			printf("Enter the position that you want to insert the data in:\n");
			int pos;
			scanf("%d", &pos);
			insert(data,pos);
			break;
		}
		case 2:
		{
			printf("Enter the position that you want to delete data from:\n");
			int pos;
			scanf("%d", &pos);
			delete(pos);
			break;
		}
		case 3:
		{
			print();
			break;
		}
		case 4:
		{
			reverse();
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
