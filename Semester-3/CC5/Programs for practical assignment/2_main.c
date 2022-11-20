#include "2_linked_list.h"

int main(){
  node* head = NULL;
  while (1) {
    printf("Press 1 to add a node, and 2 to delete a node, and 3 to exit.\n");
    printf("Enter your choice: \n");
    int choice;
    scanf("%d", &choice);
    if(choice == 1) {
      printf("Press 1 to add node at beginning, 2 to add node at end, and 3 to add node after a certain index.\n");
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      int value;
      printf("Enter the value to be added to the list:\n");
      scanf("%d", &value);
      if (choice == 1) {
        insert_at_beginning(&head, value);
      } else if (choice == 2) {
        insert_at_end(&head, value);
      } else if (choice == 3) {
        printf("Enter the index at which you want to enter the value:\n");
        int index;
        scanf("%d", &index);
        insert_at_index(&head, value, index);
      } else {
        printf("Wrong choice entered!\n");
      }
    } else if (choice == 2) {
      printf("Press 1 to delete node from beginning, 2 to delete node from end, and 3 to delete node from any index.\n");
      printf("Press 4 to delete the entire list.\n");
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      if (choice == 1) {
        delete_from_beginning(&head);
      } else if (choice == 2) {
        delete_from_end(&head);
      } else if (choice == 3) {
        printf("Enter the index that you want to delete from:\n");
        int index;
        scanf("%d", &index);
        delete_from_index(&head, index);
      } else if(choice == 4) {
        clear_list(&head);
      } else {
        printf("Wrong choice entered.\n");
      }
    } else if (choice == 3) {
      return 0;
    } else {
      printf("Wrong choice entered!");
    }
    print(head);
  }
  return 0;
}
