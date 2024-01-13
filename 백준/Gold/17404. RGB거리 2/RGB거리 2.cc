#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define R 1
#define G 2
#define B 3
#define INF 987654321

using namespace std;

int main() {
    fast;
    
    int N; cin>>N;
    int input[N+1][4];
    int dp[N+1][4];
    
    for(int i=1; i<=N; ++i)
        for(int j=R; j<=B; ++j)
            cin>>input[i][j];
    
    int res = INF;
    for(int color=R; color<=B; ++color) {
        for(int i=R; i<=B; ++i) {
            if (i == color) {
                dp[1][i] = input[1][i];
                continue;
            }
            dp[1][i] = INF;
        }
        
        for(int i=2; i<=N; ++i) {
            dp[i][R] = min(dp[i-1][G], dp[i-1][B]) + input[i][R];
            dp[i][G] = min(dp[i-1][R], dp[i-1][B]) + input[i][G];
            dp[i][B] = min(dp[i-1][R], dp[i-1][G]) + input[i][B];
        }
        
        for(int i=R; i<=B; ++i) {
            if(i == color) continue;
            res = min(res, dp[N][i]);
        }
    }
  
    cout<<res<<"\n";
}
