#include "6_circular_doubly_linked_list.h"

int main(){
  node* head = NULL;
  while(1){
    printf("Press 1 to enter an element in the list.\n");
    printf("Press 2 to delete an element from the list.\n");
    printf("Press 3 to print the list.\n");
    printf("Press any other integer to exit.\n");
    printf("Enter your choice:\n");
    int choice;
    scanf("%d",&choice);
    switch (choice){
      int num, pos;
      case 1:
        printf("Enter the number you want to enter:\n");
        scanf("%d", &num);
        printf("Press 1 to enter at beginning, 2 to enter at end, 3 to enter at any index.\n");
        printf("Enter your choice:\n");
        int choice2;
        scanf("%d", &choice2);
        switch(choice2){
          case 1:
            insert_at_beginning(num,&head);
            break;
          case 2:
            insert_at_end(num,&head);
            break;
          case 3:
            printf("Enter the position (0-indexed) that you want to enter in:\n");
            scanf("%d", &pos);
            insert_at_index(num,pos,&head);
            break;
          default:
            exit(0);
        }
        break;
      case 2:
        printf("Press 1 to delete from beginning,2 to delete from end,3 to delete from any index\n");
        printf("Press 4 to delete entire list.\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice2);
        switch(choice2){
          case 1:
            delete_from_beginning(&head);
            break;
          case 2:
            delete_from_end(&head);
            break;
          case 3:
            printf("Enter the position (0-indexed) that you want to delete from:\n");
            scanf("%d", &pos);
            delete_from_index(pos,&head);
            break;
          case 4:
            clear_list(&head);
            break;
          default:
            exit(0);
        }
        break;
      case 3:
        print(head);
        break;
      default:
        exit(0);
    }
  }
  return 0;
}
