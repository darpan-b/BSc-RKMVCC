#include "2_linked_list.h"
void reverse(node** head){
  node* nxt=NULL, *prev=NULL, *current=*head;
  while(current != NULL){
    nxt = current->next;
    current->next = prev;
    prev = current;
    current = nxt;
  }
  *head = prev;
}
int main(){
  node* head = NULL;
  while(1){
    printf("Press 1 to insert an element in the list.\n");
    printf("Press 2 to reverse the linked list.\n");
    printf("Press any other key to exit.\n");
    printf("Enter your choice:\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("Enter element to insert in list:\n");
        int ele;
        scanf("%d", &ele);
        insert_at_end(&head,ele);
        print(head);
        break;
      case 2:
        reverse(&head);
        print(head);
        break;
      default:
        exit(0);
    }
  }
  return 0;
}
