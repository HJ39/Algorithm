#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int dp[1'000'001];

int main() {
    fast;
    
    int N; cin>>N;
    
    
    for(int i=1; i<=N; ++i) {
        dp[i] = i;
        if(i%2 == 0)
            dp[i] = min(dp[i], dp[i/2] + 1);
        
        if(i%3 == 0)
            dp[i] = min(dp[i], dp[i/3] + 1);
        dp[i] = min(dp[i], dp[i-1] + 1);
    }
 
    cout<<dp[N]-1<<"\n";
    
    while (N != 0) {
        cout<<N<<" ";
        if(dp[N] == dp[N-1] + 1)
            N = N-1;
        else if(dp[N] == dp[N/2] + 1 and N%2 == 0)
            N = N/2;
        else if(dp[N] == dp[N/3] + 1 and N%3 == 0)
            N = N/3; 
    }
}
