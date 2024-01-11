#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int dp[31];

int main() {
    fast;
    int N; cin>>N;
    
    dp[0] = 1;
    dp[2] = 3;
    for(int i=4; i<=N; i+=2) {
        dp[i] = dp[i-2] * dp[2];
        for(int j=i-4; j>=0; j-=2)
            dp[i] += dp[j]*2;
    }
    
    cout<<dp[N]<<"\n";
}
