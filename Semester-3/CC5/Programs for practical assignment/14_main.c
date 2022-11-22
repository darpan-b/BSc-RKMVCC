#include "14_deque.h"
int main(){
  while(1){
    printf("Press 1 to insert at back, 2 to insert at front.\n");
    printf("Press 3 to delete from back, 4 to delete from front.\n");
    printf("Press 5 to peek last element, 6 to peek first element.\n");
    printf("Press any other integer to exit.\n");
    printf("Enter your choice:\n");
    int choice;
    scanf("%d",&choice);
    if(choice == 1 || choice == 2){
      printf("Enter element to insert in queue:\n");
      int ele;
      scanf("%d", &ele);
      if(choice == 1) push_back(ele);
      else push_front(ele);
    }else if(choice == 3 || choice == 4){
      if(choice == 3) pop_back();
      else pop_front();
    }else if(choice == 5 || choice == 6){
      if(choice == 5) printf("Top element = %d\n", peek_back());
      else printf("Top element = %d\n", peek_front());
    }else{
      exit(0);
    }
  }
  return 0;
}
