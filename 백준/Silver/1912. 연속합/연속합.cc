#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int array[100'001];
    int dp[100'001];
    
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        array[i] = num;
    }
    
    dp[0] = array[0];
    int ans = dp[0];
    
    for(int i=1;i<n;i++){
        dp[i] = max(array[i], dp[i-1] + array[i]);
        
        if(ans < dp[i])
            ans = dp[i];
    }
    printf("%d\n",ans);
    
}