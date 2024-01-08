#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int input[1001];
int dp[1001][1001];

int main() {
    fast;
    
    int N; cin>>N;
    
    for(int i=1; i<=N; ++i)
        cin>>input[i];
    
    fill(&dp[0][0], &dp[N][N], 987654321);
    for(int i=1; i<=N; ++i)
        dp[i][0] = 0;
    
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            if(j-i >= 0) {
                dp[i][j] = min(dp[i][j-i] + input[i], dp[i-1][j]);
                continue;
            }
            dp[i][j] = dp[i-1][j];
        }
    }
 
    cout<<dp[N][N]<<"\n";
}
