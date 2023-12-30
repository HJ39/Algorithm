#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main(){
    fast;
    
    int N; cin>>N;
    
    vector<int> dp(1001);
    
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;
    for(int i=6; i<=N; ++i) {
        dp[i] = 0;
        if(dp[i-1] == 0)
            dp[i] = 1;
        if(dp[i-3] == 0)
            dp[i] = 1;
        if(dp[i-4] == 0)
            dp[i] = 1;
    }
    
    dp[N] == 0 ? cout<<"CY\n" : cout<<"SK\n";
    
}
