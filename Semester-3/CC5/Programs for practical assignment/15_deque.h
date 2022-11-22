#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
  struct node* prev;
}node;
node* head=NULL, *tail=NULL;
node* create_node(int data){
  node* newnode = (node*)malloc(sizeof(node));
  newnode->data = data;
  newnode->next = NULL;
  newnode->prev = NULL;
}

void push_back(int data){
  node* newnode = create_node(data);
  if(head == NULL){
    head = tail = newnode;
    return;
  }
  tail->next = newnode;
  tail = newnode;
}
void push_front(int data){
  node* newnode = create_node(data);
  if(head == NULL){
    head = tail = newnode;
    return;
  }
  head->prev = newnode;
  head = newnode;
}

void pop_back(){
  if(head == NULL) return;
  node* tmp = tail;
  tail = tail->prev;
  free(tmp);
  if(tail == NULL) head = NULL;
}
void pop_front(){
  if(head == NULL) return;
  node* tmp = tail;
  tail = tail->prev;
  free(tmp);
  if(tail == NULL) head = NULL;
}

int peek_back(){
  if(head == NULL){
    printf("Deque is empty!\n");
    return -1;
  }
  return tail->data;
}
int peek_front(){
  if(head == NULL){
    printf("Deque is empty!\n");
    return -1;
  }
  return head->data;
}
