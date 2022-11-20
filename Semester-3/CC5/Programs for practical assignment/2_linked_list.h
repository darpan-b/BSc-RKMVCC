#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int data;
  struct node* next;
}node;

node* create_node(int data){
  node* newnode = (node*)malloc(sizeof(node));
  newnode->data = data; 
  newnode->next = NULL;
}

void print(node* head){
  node* temp = head;
  printf("List is: ");
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void insert_at_beginning(node** head,int data){
  node* newnode = create_node(data);
  if((*head) == NULL){ *head = newnode; }
  else{ newnode->next = *head; *head = newnode; }
}

void insert_at_end(node** head,int data){
  node* newnode = create_node(data);
  if((*head) == NULL){ *head = newnode; return; }
  node* temp = *head;
  while(temp->next != NULL) temp = temp->next;
  temp->next = newnode;
}

void insert_at_index(node** head,int data,int idx){
  node* newnode = create_node(data);
  if(idx==0 || (*head)==NULL){
    insert_at_beginning(head,data); 
    return;
  }
  int counter = 0; node* temp = *head;
  while(temp->next!=NULL && counter<idx-1){
    temp = temp->next; counter++;
  }
  newnode->next = temp->next; 
  temp->next = newnode;
}

void delete_from_beginning(node** head){
  if((*head) == NULL) return;
  node* tmp = *head; 
  *head = (*head)->next; 
  free(tmp);
}

void delete_from_end(node** head){
  if((*head) == NULL) return;
  node* temp = *head;
  if((*head)->next == NULL){
    free(*head); head=NULL; 
    return;
  }
  while(temp->next->next != NULL) temp = temp->next;
  node* last_node = temp->next; 
  temp->next = NULL;
  free(last_node);
}

void delete_from_index(node** head,int idx){
  if(idx==0 || (*head)==NULL){
    delete_from_beginning(head); return;
  }
  int counter = 0;
  node* temp = *head;
  while(temp->next->next!=NULL && counter<idx-1){
    temp = temp->next; counter++;
  }
  node* to_delete=temp->next; 
  temp->next=temp->next->next;
  free(to_delete);
}

void clear_list(node** head){
  node* temp = *head;
  while(temp != NULL){
    *head=NULL;
    free(*head);
    (*head) = temp->next;
    temp = temp->next;
  }
}
