#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *previous;
  struct node *next;
} node;


node *create_node(int data){
  node *newnode = (node *)malloc(sizeof(node));
  newnode->data = data;
  newnode->previous = NULL;
  newnode->next = NULL;
  return newnode;
}

void print(node *head){
  printf("List is: ");
  for (node *tmp = head; tmp != NULL; tmp = tmp->next){
    printf("%d ", tmp->data);
  }
  printf("\n");
}

void insert_at_beginning(node** head,int data){
  node* newnode = create_node(data);
  if(*head == NULL){ *head = newnode; return; }
  newnode->next = *head;
  (*head)->previous = newnode;
  *head = newnode;
  return;
}
void insert_at_end(node** head,int data){
  if(*head == NULL) return;
  node* newnode = create_node(data);
  node* tmp = *head;
  int i = 0;
  for (; tmp->next != NULL; i++, tmp = tmp->next);
  newnode->next = tmp->next;
  newnode->previous = tmp;
  tmp->next = newnode;
}
void insert_at_index(node **head, int data, int pos){
  node *newnode = create_node(data);
  if (*head == NULL){
    *head = newnode;
    return;
  }
  if (pos == 0){ insert_at_beginning(head,data); return; }
  int i = 0;
  node *tmp = *head;
  for (; i < pos - 1 && tmp->next != NULL; i++, tmp = tmp->next);
  newnode->next = tmp->next;
  newnode->previous = tmp;
  tmp->next = newnode;
}

void delete_from_beginning(node** head){
  if (*head == NULL) return;
  node *temp = *head;
  if (temp->next != NULL) temp->previous = NULL;
  *head = (*head)->next;
  free(temp);
}
void delete_from_end(node** head){
  if (*head == NULL) return;
  int i = 0;
  node *tmp = *head;
  for (; tmp->next != NULL; i++, tmp = tmp->next);
  if (tmp->previous != NULL) tmp->previous->next = tmp->next;
  if (tmp->next != NULL) tmp->next->previous = tmp->previous;
  free(tmp);
}
void delete_from_index(node **head, int pos){
  if (*head == NULL) return;
  if (pos == 0){ delete_from_beginning(head); return; }
  int i = 0;
  node *tmp = *head;
  for (; i < pos && tmp->next != NULL; i++, tmp = tmp->next);
  if (tmp->previous != NULL) tmp->previous->next = tmp->next;
  if (tmp->next != NULL) tmp->next->previous = tmp->previous;
  free(tmp);
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

void reverse(node **head){
  node *temp;
  for (node *tmp = *head; tmp != NULL; tmp = tmp->previous){
    if (tmp->next == NULL) temp = tmp;
    node *temp1 = tmp->next;
    tmp->next = tmp->previous;
    tmp->previous = temp1;
  }
  *head = temp;
}
