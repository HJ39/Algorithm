#include <bits/stdc++.h>
using namespace std;
int  dp[100'001];
int main(){
    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        dp[i] = i;
        if(i >= 2){
            dp[i] = min(dp[i-2] + 1, dp[i]);
        }
        if(i >= 5){
            dp[i] = min(dp[i-5] + 1, dp[i]);
        }
        if(i >= 7){
            dp[i] = min(dp[i-7] + 1, dp[i]);
        }
    }
    
    printf("%d\n",dp[n]);
}