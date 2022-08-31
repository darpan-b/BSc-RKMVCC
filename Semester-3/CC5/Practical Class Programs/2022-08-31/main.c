#include "queue_using_array.h"

int main()
{
    while (1)
    {
        printf("Press 1 to insert element, 2 to pop element from queue.\n");
        printf("Press 3 to print the queue, 4 to print the topmost element.\n");
        printf("Press any other integer to exit.\n");
        printf("Enter your choice:\n");
        int choice;
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
        {
            printf("Enter data to be added to queue:\n");
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
            print();
            break;
        }
        case 4:
        {
            printf("Topmost element = %d\n", top());
        }
        default:
        {
            exit(0);
        }
        }
    }
}
