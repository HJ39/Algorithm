#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define DAY 0
#define PAGE 1
using namespace std;

int dp[21][201];

int main(){
    fast;
    
    int N, M; cin>>N>>M;
    
    int input[M+1][2];
    
    for(int i=1; i<=M; ++i)
        cin>>input[i][DAY]>>input[i][PAGE];
    
    for(int i=1; i<=M; ++i) {
        for(int j=1; j<=200; ++j) {
            if(j-input[i][DAY] >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-input[i][DAY]] + input[i][PAGE]);
                continue;
            }
            dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[M][N];
}
