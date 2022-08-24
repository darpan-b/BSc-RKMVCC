#include "circular_doubly_linked_list.h"

int main()
{
    node *head = NULL;

    while (1)
    {
        printf("Press 0 to print the list.\n");
        printf("Press 1 to insert data in the list.\n");
        printf("Press 2 to delete data from the list.\n");
        printf("Press 3 to reverse the list.\n");
        printf("Enter your choice:\n");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
        {
            print(head);
            break;
        }
        case 1:
        {
            printf("Enter the data that you want to enter:\n");
            int data;
            scanf("%d", &data);
            printf("Enter the position (0-indexed) that you want to enter the data in:\n");
            int position;
            scanf("%d", &position);
            insert(data, position, &head);
            break;
        }
        case 2:
        {
            printf("Enter the position (0-indexed) that you want to delete data from:\n");
            int position;
            scanf("%d", &position);
            delete(position, &head);
            break;
        }
        case 3:
        {
            reverse(&head);
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
