#include "8_stack.h"
#include <string.h>

int precedence(char ch){
  if (ch == '+' || ch == '-') return 0;
  else if (ch == '*' || ch == '/') return 1;
  else if (ch == '^') return 2;
  else if (ch == '(' || ch == ')') return 3;
  else return -1;
}
char* reverse(char *str){
  int len = strlen(str);
  char *res = (char *)malloc(sizeof(char) * len);
  for (int i = 0; i < len; i++) res[i] = str[len - 1 - i];
  return res;
}
char * convert_to_postfix(char *expr){
  char *res = (char *)malloc(sizeof(char) * strlen(expr) + 5);
  for (int i = 0; i < strlen(res); i++) res[i] = NULL;
  int res_idx = 0;
  stack_node *stk = NULL;
  for (int i = 0; i < strlen(expr); i++){
    char ch = expr[i];
    int pr = precedence(ch);
    if (pr == -1)res[res_idx++] = ch;
    else{
      if (ch == ')'){
        while (!empty(stk)){
          char ch = peek(stk);
          pop(&stk);
          if (ch == '(') break;
          else res[res_idx++] = ch;
        }
      }else{
        while (!empty(stk)){
          if (peek(stk) == '(') break;
          if (precedence(peek(stk)) > pr){
            res[res_idx++] = peek(stk);
            pop(&stk);
          }else if (precedence(peek(stk)) == pr){
            if (ch == '^' || ch == '(') break;
            res[res_idx++] = peek(stk);
            pop(&stk);
          } else break;
        }
        push(&stk, ch);
      }
    }
  }
  while (!empty(stk)){
    if (peek(stk) != '(') res[res_idx++] = peek(stk);
    pop(&stk);
  }
  return res;
}
char * convert_to_prefix(char *expr){
  char *res = reverse(expr);
  for (int i = 0; i < strlen(res); i++){
    if (res[i] == '(') res[i] = ')';
    else if (res[i] == ')') res[i] = '(';
  }
  res = convert_to_postfix(res);
  res = reverse(res);
  return res;
}
int main(){
  while (1){
    printf("Enter expression (without spaces):\n");
    char str[100] = {NULL};
    scanf("%s", str);
    printf("Press 1 to convert to postfix, 2 to convert to prefix, any other integer to exit.");
    printf("Enter your choice:");
    int choice;
    scanf("%d", &choice);
    switch (choice){
    case 1:
      printf("Postfix expression = %s\n", convert_to_postfix(str));
      break;
    case 2:
      printf("Prefix expression = %s\n", convert_to_prefix(str));
      break;
    default:
      exit(0);
    }
  }
  return 0;
}
