#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1005
int stack[MAX_SIZE];
int stackptr = -1;

void push(int data){
  if (stackptr == MAX_SIZE - 1){
    printf("Stack Overflow!\n");
    return;
  }
  stack[++stackptr] = data;
}
void pop(){
  if (stackptr == -1){
    printf("Stack Underflow!\n");
    return;
  }
  stackptr--;
}
void peek(){
  if (stackptr == -1){
    printf("Stack is empty!\n");
    return;
  }
  printf("Top element of stack = %d\n", stack[stackptr]);
}

int main(){
  while (1){
    printf("Press 1 to push element in stack.\n");
    printf("Press 2 to pop element in stack.\n");
    printf("Press 3 to view top element in stack.\n");
    printf("Press any other key to exit.\n");
    printf("Enter your choice:\n");
    int choice;
    scanf("%d", &choice);
    switch(choice){
    case 1:
      printf("Enter the element that you want to push in the stack:\n");
      int data;
      scanf("%d", &data);
      push(data);
      break;
    case 2:
      pop();
      break;
    case 3:
      peek();
      break;
    default:
      exit(0);
    }
  }
  return 0;
}
