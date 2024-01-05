#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define BYTE 0
#define COST 1
using namespace std;

long long dp[101][10001];

int searching(int N, int M) {
    int minCost = 987654321;
    for(int i=1; i<=N; ++i)
        for(int j=0; j<=10000; ++j)
            if(dp[i][j] >= M)
                minCost = min(minCost, j);
    
    return minCost;
}

int main(){
    fast;
    
    int N,M; cin>>N>>M;
    int input[101][2];
    
    
    for(int i=1; i<=N; ++i)
        cin>>input[i][BYTE];
    
    for(int i=1; i<=N; ++i)
        cin>>input[i][COST];
    
    for(int i=1; i<=N; ++i) {
        for(int j=0; j<=10000; ++j) {
            if(j - input[i][COST] >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-input[i][COST]] + input[i][BYTE]);
                continue;
            }
            dp[i][j] = dp[i-1][j];
        }
    }

    cout<<searching(N,M)<<"\n";
}