#include <bits/stdc++.h>
#define MAXNUM 1'000'000'000

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int dp[1'000'001];
  
    bool check = n < 0 ? true : false;
    
    if(n%2 == 0 && check)
        printf("-1\n");
    else if(n == 0)
        printf("0\n");
    else
        printf("1\n");
    
    n = abs(n);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n;i++){
        dp[i] = (dp[i-1] % MAXNUM) + (dp[i-2] % MAXNUM);
        
    }
    printf("%d\n",dp[n] % MAXNUM);
    
    
}