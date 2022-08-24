#include <stdio.h>

#define MAX_SIZE 200001

int stack[MAX_SIZE];
int stackptr = -1;

void push(int data)
{
    if (stackptr == MAX_SIZE - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++stackptr] = data;
}

void pop()
{
    if (stackptr == -1)
    {
        printf("Stack Underflow!\n");
        return;
    }
    stackptr--;
}

void peek()
{
    if (stackptr == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element of stack = %d\n", stack[stackptr]);
}
