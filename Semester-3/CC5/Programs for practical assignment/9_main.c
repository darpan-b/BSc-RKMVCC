#include "8_stack.h"
int main(){
  printf("Enter the number of elements in the array:\n");
  int n;
  scanf("%d",&n);
  printf("Enter %d elements:\n", n);
  int* a = (int*)malloc(sizeof(int)*n);
  for(int i=0; i<n; i++) scanf("%d", &a[i]);
  stack_node* head = NULL;
  for(int i=0; i<n; i++) push(&head,a[i]);
  for(int i=0; i<n; i++){ a[i] = peek(head); pop(&head); }
  printf("Reversed array = ");
  for(int i=0; i<n; i++) printf("%d ",a[i]);
  printf("\n");
  return 0;
}
