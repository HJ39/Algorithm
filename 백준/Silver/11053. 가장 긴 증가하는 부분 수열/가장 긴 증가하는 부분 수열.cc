#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    
    int array[1001] = {0};
    int dp[1001] = {0};
    
    for(int i=1;i<=n;i++)
        scanf("%d",&array[i]);
        
    for(int i=1;i<=n;i++){
        dp[i] = 1;
        for(int j=1; j<i; j++){
            if(array[j] < array[i]){
                dp[i] = max(dp[j] + 1,dp[i]);
            }
        }
    }
    
    int res = 0;
    for(int i=1;i<=n;i++)
        res = max(dp[i],res);
    
    printf("%d\n",res);
}