#include <stdio.h>
#include <stdlib.h>

// implementing stack with multipop functionality

int* stk;
int capacity;
int top = -1;

void push(int value) {
  if (top == capacity - 1) {
    return;
  }
  stk[++top] = value;
}

void multipop(int to_pop) {
  while (top > -1 && to_pop--) {
    top--;
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
      exit(0);
    }
  }
  return 0;
}
