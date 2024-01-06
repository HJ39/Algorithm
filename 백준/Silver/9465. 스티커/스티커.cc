#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fast;
    
    int T; cin>>T;
    
    while (T--) {
        int N; cin>>N;
        int input[N+1][3];
        int dp[N+1][3];
        
        for(int i=1; i<=N; ++i)
            cin>>input[i][1];
        for(int i=1; i<=N; ++i)
            cin>>input[i][2];
        
        memset(dp, 0, sizeof(dp));
        
        dp[1][1] = input[1][1]; dp[1][2] = input[1][2];
        for(int i=2; i<=N; ++i) {
            for(int j=1; j<=2; ++j) {
                if(j==1) {
                    dp[i][j] = max(dp[i-2][1], dp[i][j]);
                    dp[i][j] = max(dp[i-2][2], dp[i][j]);
                    dp[i][j] = max(dp[i-1][2], dp[i][j]);
                    dp[i][j] += + input[i][j];
                } else {
                    dp[i][j] = max(dp[i-2][1], dp[i][j]);
                    dp[i][j] = max(dp[i-2][2], dp[i][j]);
                    dp[i][j] = max(dp[i-1][1], dp[i][j]);
                    dp[i][j] += + input[i][j];
                }
            }
        }
        
        int res = 0;
        for(int i=1; i<=N; ++i)
            for(int j=1; j<=2; ++j)
                res = max(res, dp[i][j]);
        
        cout<<res<<"\n";
    }
}
