#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int data;
  struct node* next;
} node;
node* head=NULL, *tail=NULL;
node* create_node(int data){
  node* newnode = (node*)malloc(sizeof(node));
  newnode->data = data;
  newnode->next = NULL;
}

void push(int data){
  node* newnode = (node*)malloc(sizeof(node));
  newnode->data = data;
  if(head == NULL){
    head = tail = newnode;
    head->next = tail;
    tail->next = head;
    return;
  }
  tail->next = newnode;
  newnode->next = head;
  tail = newnode;
}
void pop(){
  if(head == NULL) return;
  node* tmp = head;
  if(head == tail) head = NULL;
  else head = head->next;
  free(tmp);
  if(head == NULL) tail=NULL;
}
int peek(){
  if(head == NULL){
    printf("Queue is empty!\n");
    return -1;
  }
  return head->data;
}
