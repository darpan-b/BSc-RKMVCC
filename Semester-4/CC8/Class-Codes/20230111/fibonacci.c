#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXN 105

int dp[MAXN];

int f(int n){
    if(dp[n] != -1) return dp[n];
    dp[n] = f(n-1) + f(n-2);
    printf("%d ", dp[n]);
    return dp[n];
}

// CH Sir
int f2(int n, int a, int b){
    if(n == 0) return a;
    else if(n == 1) return b;
    printf("%d ", a+b);
    return f2(n-1, b, a+b);
}

int main(){
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    int n;
    scanf("%d", &n);
    printf("0 1 ");
    assert(n >= 2);
    //~ f(n);
    printf("%d", f2(n,0,1));
    return 0;
}
