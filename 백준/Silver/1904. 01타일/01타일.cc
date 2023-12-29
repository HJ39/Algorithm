#include <bits/stdc++.h>
#define DIVIDE 15746

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    
    int dp[1'000'001];
    
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-2] % DIVIDE) + (dp[i-1] % DIVIDE);
    }
    
    printf("%d\n",dp[n] % DIVIDE);
}