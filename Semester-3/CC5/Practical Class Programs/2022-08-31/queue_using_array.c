#include <stdlib.h>

#define MAX 100001
int queue[MAX];
int front = -1, rear = -1;

void push(int data)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full!\n");
        return;
    }
    queue[++rear] = data;
    if (front == -1) front = rear;
}

void pop()
{
    if (front == -1)
    {
        printf("Queue in empty!\n");
        return;
    }
    front++;
    front = (front > rear ? -1 : front);
}

int front()
{
    if (front == -1)
    {
        printf("Queue in empty!\n");
        return -1;
    }
    return queue[front];
}

void print()
{
    printf("Queue is : ");
    for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}

int empty()
{
    return front == -1;
}

