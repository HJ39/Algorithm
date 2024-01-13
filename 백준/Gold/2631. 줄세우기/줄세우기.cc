#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fast;
    
    int N; cin>>N;
    int input[N+1];
    int dp[N+1];
    
    for(int i=1; i<=N; ++i)
        cin>>input[i];
    
    for(int i=1; i<=N; ++i) {
        dp[i] = 1;
        for(int j=1; j<i; ++j)
            if(input[j] < input[i])
                dp[i] = max(dp[j] + 1, dp[i]);
    }
    
    int res = 0;
    for(int i=1; i<=N; ++i)
        res = max(res, dp[i]);
    cout<<N-res<<"\n";
}
