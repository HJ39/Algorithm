#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int dp[501][501];
int main(){
    fast;
    
    int N; cin>>N;
    
    int input[501][501];
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=i; ++j) {
            cin>>input[i][j];
        }
    }
    
    dp[1][1] = input[1][1];
    for(int i=2; i<=N; ++i) {
        for(int j=1; j<=i; ++j) {
            dp[i][j] = max(dp[i][j], dp[i-1][j] + input[i][j]);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + input[i][j]);
        }
    }
    
    int res = 0;
    for(int i=1; i<=N; ++i)
        res = max(res, dp[N][i]);
    cout<<res<<"\n";
}
