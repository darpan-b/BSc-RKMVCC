#include "13_circular_queue.h"
int main(){
  while(1){
    printf("Press 1 to insert an element, 2 to pop an element, 3 to peek.\n");
    printf("Press any other integer to exit.\n");
    printf("Enter your choice:\n");
    int choice;
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("Enter element to insert in queue:\n");
        int ele;
        scanf("%d", &ele);
        push(ele);
        break;
      case 2:
        pop();
        break;
      case 3:
        printf("Top element = %d\n", peek());
        break;
      default:
        exit(0);
    }
  }
  return 0;
}
