#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int dp[1001][1001];

int main(){
    fast;
    
    int N; cin>>N;
    
    int input[N+1];
    for(int i=1; i<=N; ++i)
        cin>>input[i];
    
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            if(j-i >= 0) {
                dp[i][j] = max(dp[i][j-i] + input[i], dp[i-1][j]);
                continue;
            }
            dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[N][N]<<"\n";
}
