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
    scanf("%s",s);
    int* pi = compute_prefix_function(s);
    int m = strlen(s);
    printf("Pi table = ");
    for(int i = 0; i < m; i++) printf("%d ",pi[i]);
    printf("\n");
    return 0;
}
