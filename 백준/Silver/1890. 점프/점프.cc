#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long ll;
ll dp[101][101];
int N;

int main() {
    fast;
    
    cin>>N;
    
    ll input[N+1][N+1];
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=N; ++j)
            cin>>input[i][j];
    
    dp[1][1] = 1;
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            ll mi = i + input[i][j];
            ll mj = j + input[i][j];
            
            if(mi <= N and i != N)
                dp[mi][j] += dp[i][j];
            if(mj <= N and j != N)
                dp[i][mj] += dp[i][j];
        }
    }
    cout<<dp[N][N]<<"\n";
}
