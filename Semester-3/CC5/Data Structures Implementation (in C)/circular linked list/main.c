#include "circular_linked_list.h"

int main()
{
	while (1)
	{
		printf("Press 1 to add element to list.\n");
		printf("Press 2 to delete element from list.\n");
		printf("Press 3 to print the list.\n");
		printf("Press any other integer to exit.\n");
		printf("Enter your choice:\n");
		int choice;
		scanf("%d", &choice);

		node *head = NULL;

		switch (choice)
		{
		case 1:
		{
			printf("Enter the data that you want to enter:\n");
			int data;
			scanf("%d", &data);
			printf("Enter the position (0-indexed):\n");
			int position;
			scanf("%d", &position);
			insert_node(&head, data, position);
			printf("head data=%d next data=%d %d\n",head->data,head->next->data,head==NULL);
			break;
		}
		case 2:
		{
			printf("Enter the position (0-indexed) that you want to delete data from:\n");
			int position;
			scanf("%d", &position);
			delete_node(&head, position);
			break;
		}
		case 3:
		{
			print(head);
			break;
		}
		default:
		{
			exit(0);
		}
		}
	}
	return 0;
}
