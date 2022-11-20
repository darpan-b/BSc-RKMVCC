#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node{
  int data;
  struct stack_node *previous;
} stack_node;

stack_node* create_node(int data){
  stack_node *newnode = (stack_node *)malloc(sizeof(stack_node));
  newnode->data = data;
  newnode->previous = NULL;
  return newnode;
}
void push(stack_node **head, int data){
  stack_node *newnode = create_node(data);
  if (*head == NULL){
    *head = newnode;
    return;
  }
  newnode->previous = *head;
  *head = newnode;
}
void pop(stack_node **head){
  if (*head == NULL) return;
  stack_node *tmp = *head;
  *head = (*head)->previous;
  free(tmp);
}
int peek(stack_node *head){
  if (head == NULL) return -1;
  return head->data;
}
int empty(stack_node *head){
  return head == NULL;
}
