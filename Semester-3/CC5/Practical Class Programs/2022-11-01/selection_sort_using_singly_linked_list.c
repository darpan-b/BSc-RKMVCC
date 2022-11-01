#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
} node;

void selection_sort(node** head)
{
	for(node* tmp = *head; tmp != NULL; tmp = tmp->next)
	{
		node* min_node = tmp;
		for(node* tmp2 = tmp->next; tmp2 != NULL; tmp2 = tmp2->next)
		{
			if(tmp2->data < min_node->data) min_node = tmp2;
		}
		int temp_data = min_node->data;
		min_node->data = tmp->data;
		tmp->data = temp_data;
	}
}

int main()
{
	node* head = NULL;
	printf("Enter the number of elements:\n");
	int n;
	scanf("%d", &n);
	node* curnode = NULL;
	printf("Enter the elements:\n");
	for(int i = 0; i < n; i++)
	{
		node* newnode = (node*)malloc(sizeof(node));
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		if(curnode == NULL)
		{
			curnode = newnode;
			head = curnode;
		}
		else
		{
			curnode->next = newnode;
			curnode = newnode;
		}
	}
	selection_sort(&head);
	printf("Sorted list = ");
	for(node* tmp = head; tmp != NULL; tmp = tmp->next)
	{
		printf("%d ", tmp->data);
	}
	printf("\n");
	return 0;
}
