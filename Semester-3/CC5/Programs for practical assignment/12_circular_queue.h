#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
int queue[MAX];
int tail=-1, head=-1;

void push(int data){
  if(head == -1){
    head = tail = 0;
    queue[head] = data;
    return;
  }
  if((tail+1)%MAX != head){
    tail = (tail+1)%MAX;
    queue[tail] = data;
  }else{
    printf("Queue is full!\n");
  }
}
void pop(){
  if(head == -1) return;
  head = (head+1)%MAX;
  if(head > tail) head = tail = -1;
}
int peek(){
  if(head == -1){
    printf("Queue is empty!\n");
    return -1;
  }
  return queue[head];
}
