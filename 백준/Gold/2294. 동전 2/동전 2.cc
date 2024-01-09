#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INF 987654321

using namespace std;

int main() {
    fast;
    
    int n,k; cin>>n>>k;
    
    int input[n+1];
    int dp[k+1];
    for(int i=1; i<=n; ++i)
        cin>>input[i];

    fill(&dp[0], &dp[k+1], INF);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=k; ++j) {
            if(j == input[i])
                dp[j] = 1;
            else if(j-input[i] >= 0)
                dp[j] = min(dp[j], dp[j-input[i]] + 1);
        }
    }
    
    dp[k] != INF ? cout<<dp[k]<<"\n" : cout<<"-1\n";
}
