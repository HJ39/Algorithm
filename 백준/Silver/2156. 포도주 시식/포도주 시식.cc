#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    
    int array[n+1];
    
    for(int i=1;i<=n;i++)
        scanf("%d",&array[i]);
    
    int dp[n+1];
    
    dp[0] = 0;
    dp[1] = array[1];
    dp[2] = array[2] + array[1];
    for(int i=3; i<=n;i++){
        dp[i] = max(dp[i-2] + array[i], dp[i-3] + array[i] + array[i-1]);
        dp[i] = max(dp[i], dp[i-1]);
    }
    
    printf("%d\n",dp[n]);
}
