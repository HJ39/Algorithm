#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main(){
    fast;
    
    int t; cin>>t;
    int dp[11];
    
    while (t--) {
        int n; cin>>n;
        fill_n(dp, 11, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i=4; i<=n; ++i) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout<<dp[n]<<"\n";
    }
}
