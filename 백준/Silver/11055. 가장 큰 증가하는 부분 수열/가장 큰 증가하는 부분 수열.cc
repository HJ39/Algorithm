#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    
    int array[1001] = {0};
    int dp[1001] = {0};
    
    for(int i=1;i<=n;i++)
        scanf("%d",&array[i]);
    
    int res = 0;
    for(int i=1;i<=n;i++){
        dp[i] = array[i];
        for(int j=1; j<i; j++){
            if(array[j] < array[i] && dp[i] < dp[j] + array[i]){
                dp[i] = dp[j] + array[i];
            }
        }
        res = max(res, dp[i]);
    }
    printf("%d\n",res);
}