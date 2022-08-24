#include "stack.h"

int main()
{
    while (1)
    {
        printf("Press 1 to push element in stack.\n");
        printf("Press 2 to pop element in stack.\n");
        printf("Press 3 to view top element in stack.\n");
        printf("Press any other key to exit.\n");
        printf("Enter your choice:\n");
        int choice;
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
        {
            printf("Enter the element that you want to push in the stack:\n");
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
            peek();
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
