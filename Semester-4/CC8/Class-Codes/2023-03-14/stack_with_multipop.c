#include <stdio.h>
#include <stdlib.h>

// implementing stack with multipop functionality

int* stk;
int capacity;
int top = -1;
int count;

void push(int value) {
    if (top == capacity - 1) {
        return;
    }
    stk[++top] = value;
    count++;
}

void multipop(int to_pop) {
    while (top > -1 && to_pop--) {
        top--;
        count++;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element of stack = %d\n", stk[top]);
}

int main() {
    printf("Enter capacity of the stack:\n");
    scanf("%d", &capacity);
    stk = (int*)malloc(sizeof(int) * capacity);
    while (1) {
        printf("Enter 1 for pushing element in the stack:\n");
        printf("Enter 2 for popping element from the stack:\n");
        printf("Enter any other number to exit:\n");
        printf("Enter your choice:\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to be pushed:\n");
            int value;
            scanf("%d", &value);
            push(value);
            peek();
        } else if (choice == 2) {
            printf("Number of elements to be popped:\n");
            int numele;
            scanf("%d", &numele);
            multipop(numele);
            peek();
        } else {
            break;
        }
    }
    printf("Average cost = %lf\n", count * 1.0 / capacity);
    return 0;
}
