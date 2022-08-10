#include "doubly_linked_list.h"

int main()
{
    node *head = NULL;

    while (1)
    {
        printf("Press 1 to insert a number to the list.\n");
        printf("Press 2 to delete a number from the list.\n");
        printf("Press 3 to reverse the list.\n");
        printf("Press 4 to print the list.\n");
        printf("Press any other integer to exit.\n");
        printf("Enter your choice:\n");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            int num, pos;
        case 1:
            printf("Enter the number which you want to add to the list:\n");
            scanf("%d", &num);
            printf("Enter the position (0-indexed) that you want to add the number in:\n");
            scanf("%d", &pos);
            insert(&head, num, pos);
            break;
        case 2:
            printf("Enter the position (0-indexed) of the number that you want to remove from the list:\n");
            scanf("%d", &pos);
            delete(&head, pos);
            break;
        case 3:
            reverse(&head);
            break;
        case 4:
            print(head);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
