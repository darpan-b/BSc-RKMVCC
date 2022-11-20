#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};
typedef struct node node;

node* create_node(int data){
  node* newnode = (node*)malloc(sizeof(node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}
node* head;
void print(){
  if(head == NULL){
    printf("List is empty!\n");
    return;
  }
  printf("List is = %d ", head->data);
  for(node* tmp = head->next; tmp != head; tmp = tmp->next){
    printf("%d ", tmp->data);
  }
  printf("\n");
}

void insert_at_beginning(int data){
  node* newnode = create_node(data);
  if(head == NULL){
    newnode->next = newnode;
    head = newnode;
    return;
  }
  node* lastnode = head;
  while(lastnode->next != head) lastnode = lastnode->next;
  lastnode->next = newnode;
  newnode->next = head;
  head = newnode;
}
void insert_at_end(int data){
  node* newnode = create_node(data);
  if(head == NULL){
    newnode->next = newnode;
    head = newnode;
    return;
  }
  node* tmp = head;
  int i = 0;
  while(tmp->next != head){
    tmp = tmp->next; i++;
  }
  newnode->next = tmp->next;
  tmp->next = newnode;
}
void insert_at_index(int data,int pos){
  node* newnode = create_node(data);
  if(head == NULL){
    newnode->next = newnode;
    head = newnode;
    return;
  }
  if(pos == 0){ insert_at_beginning(data); return; }
  node* tmp = head;
  int i = 0;
  while(i < pos-1 && tmp->next != head){
    tmp = tmp->next; i++;
  }
  newnode->next = tmp->next;
  tmp->next = newnode;
}

void delete_from_beginning(){
  if(head == NULL) return;
  node* lastnode = head;
  while(lastnode->next != head) lastnode = lastnode->next;
  lastnode->next = head->next;
  node* tmp = head;
  head = head->next;
  free(tmp);
  return;
}
void delete_from_end(){
  if(head == NULL) return;
  node* tmp = head;
  int i = 0;
  while(tmp->next->next != head){
    tmp = tmp->next; i++;
  }
  node* todel = tmp->next;
  tmp->next = tmp->next->next;
  if(todel == head) head = head->next;
  free(todel);
}
void delete_from_index(int pos){
  if(head == NULL) return;
  if(pos == 0){ delete_from_beginning(); return; }
  if(head->next == head){
    head = NULL; return;
  }
  node* tmp = head;
  int i = 0;
  while(i < pos-1 && tmp->next->next != head){
    tmp = tmp->next; i++;
  }
  node* todel = tmp->next;
  tmp->next = tmp->next->next;
  if(todel == head) head = head->next;
  free(todel);
}
void clear_list(){
  if(head->next == head){
    head = NULL; return;
  }
  node* temp = head;
  while(temp != NULL){
    head = NULL;
    free(head);
    head = temp->next;
    temp = temp->next;
  }
}
