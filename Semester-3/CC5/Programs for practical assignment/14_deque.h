#include <stdio.h>
#include <stdlib.h>
#define MAX 101
int deque[MAX];
int head=-1, tail=-1;

void push_back(int data){
  if(head == -1){
    head = tail = 0;
    deque[head] = data;
    return;
  }
  if((tail+1)%MAX != head){
    tail = (tail+1)%MAX;
    deque[tail] = data;
  }else{
    printf("Queue is full!\n");
  }
}
void push_front(int data){
  if(head == -1){
    head = tail = 0;
    deque[head] = data;
    return;
  }
  if((head-1+MAX)%MAX != tail){
    head = (head-1+MAX)%MAX;
    deque[head] = data;
  }else{
    printf("Queue is full!\n");
  }  
}
void pop_front(){
  if(head == -1) return;
  head = (head+1)%MAX;
  if(head > tail) head = tail = -1;
}
void pop_back(){
  if(head == -1) return;
  tail = (tail-1+MAX)%MAX;
  if(head > tail) head = tail = -1;
}
int peek_front(){
  if(head == -1){
    printf("Deque is empty!\n");
    return -1;
  }else return deque[head];
}
int peek_back(){
  if(head == -1){
    printf("Deque is empty!\n");
    return -1;
  }else return deque[tail];
}
