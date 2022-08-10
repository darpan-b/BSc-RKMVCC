#include "doubly_linked_list.h"

int main()
{
    node *head = NULL;
    while (1)
    {
        printf("Press 1 to insert node.\n");
        printf("Press 2 to delete node.\n");
        printf("Press 3 to reverse list.\n");
        printf("Press 4 to print list.\n");
        printf("Press any other number to exit.\n");
        printf("Enter your choice:\n");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            int num, pos;
            case 1:
                printf("Enter the number you want to enter:\n");
                scanf("%d", &num);
                printf("Enter the position (0-indexed) that you want to enter in:\n");
                scanf("%d", &pos);
                insert(&head, num, pos);
                break;
            case 2:
                printf("Enter the position (0-indexed) that you want to delete from:\n");
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
}
