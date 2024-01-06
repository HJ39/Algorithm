#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define R 1
#define G 2
#define B 3
using namespace std;

int dp[1001][4];
int main(){
    fast;
    
    int N; cin>>N;
    
    int input[1001][4];
    
    for(int i=1; i<=N; ++i)
        cin>>input[i][R]>>input[i][G]>>input[i][B];
    
    dp[1][R] = input[1][R];
    dp[1][G] = input[1][G];
    dp[1][B] = input[1][B];
    for(int i=2; i<=N; ++i) {
        dp[i][R] = min(dp[i-1][G], dp[i-1][B]) + input[i][R];
        dp[i][G] = min(dp[i-1][R], dp[i-1][B]) + input[i][G];
        dp[i][B] = min(dp[i-1][R], dp[i-1][G]) + input[i][B];
    }
    
    int res = 987654321;
    for(int i=1; i<=3; ++i)
        res = min(res, dp[N][i]);
    cout<<res<<"\n";
}
