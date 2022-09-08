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

void insert(int data,int pos){
    node* newnode = create_node(data);
    if(head == NULL){
        newnode->next = newnode;
        head = newnode;
        return;
    }
    if(pos == 0){
        node* lastnode = head;
        while(lastnode->next != head) lastnode = lastnode->next;
        lastnode->next = newnode;
        newnode->next = head;
        head = newnode;
        return;
    }
    node* tmp = head;
    int i = 0;
    while(i < pos-1 && tmp->next != head){
        tmp = tmp->next;
        i++;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
}

void delete(int pos){
    if(head == NULL) return;
    if(pos == 0){
        node* lastnode = head;
        while(lastnode->next != head) lastnode = lastnode->next;
        lastnode->next = head->next;
        node* tmp = head;
        head = head->next;
        free(tmp);
        return;
    }
    if(head->next == head){
        head = NULL;
        return;
    }
    node* tmp = head;
    int i = 0;
    while(i < pos-1 && tmp->next->next != head){
        tmp = tmp->next;
        i++;
    }
    node* todel = tmp->next;
    tmp->next = tmp->next->next;
    if(todel == head) head = head->next;
    free(todel);
}

int main(){
    while(1){
        printf("Press 1 to enter an element in the list.\n");
        printf("Press 2 to delete an element from the list.\n");
        printf("Press 3 to print the list.\n");
        printf("Press any other integer to exit.\n");
        printf("Enter your choice:\n");
        int choice;
        scanf("%d",&choice);
        
        switch(choice){
        case 1:{
            printf("Enter the data that you want to enter in the list:\n");
            int data;
            scanf("%d", &data);
            printf("Enter the index(0-indexed) that you want to enter the data to:\n");
            int pos;
            scanf("%d", &pos);
            insert(data,pos);
            break;
        }
        case 2:{
            printf("Enter the index that you want to delete data from:\n");
            int pos;
            scanf("%d", &pos);
            delete(pos);
            break;
        }
        case 3:{
            print();
            break;
        }
        default:{
            exit(0);
        }
        }
    }
    return 0;
}

