#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* compute_prefix_function(char* s){
    // pi[i] stores the max INDEX from the prefix of s, say j, such that s[i]=s[j] holds.
    int m = strlen(s);
    int* pi = (int*)malloc(sizeof(int)*m);
    pi[0] = -1;
    int k = -1;
    for(int q = 1; q < m; q++){
        while(k >= 0 && s[k+1] != s[q]) k = pi[k];
        if(s[k+1] == s[q]) k++;
        pi[q] = k;
    }
    return pi;
}

int main(){
    printf("Enter a string:\n");
    char* s = (char*)malloc(sizeof(char)*100);
    scanf("%s", s);
    int* pi = compute_prefix_function(s);
    int m = strlen(s);
    for(int i = 0; i < m; i++) printf("%d ",pi[i]);
    printf("\n");
    printf("Enter the bigger string:\n");
    char* t = (char*)malloc(sizeof(char)*100);
    scanf("%s", t);
    int sl = strlen(s);
    int tl = strlen(t);
    int to_match = -1;
    for(int i = 0; i < tl; i++){
        while(to_match >= 0 && t[i] != s[to_match+1]) to_match = pi[to_match];
        if(s[to_match+1] == t[i]) to_match++;
        if(to_match == sl-1){
            printf("FOUND AT INDEX %d!\n", i);
            return 0;
        } 
    }
    printf("NOT FOUND!\n");
    return 0;
}
