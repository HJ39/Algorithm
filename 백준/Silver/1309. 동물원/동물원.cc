#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define DI 9901
using namespace std;

int dp[100'001][4];
int main(){
    fast;
    int N; cin>>N;
    
    dp[1][1] = 1; dp[1][2] = 1; dp[1][3] = 1;
    for(int i=2; i<=N; ++i) {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % DI;
        dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % DI;
        dp[i][3] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][3]) % DI;
    }
    cout<<(dp[N][1] + dp[N][2] + dp[N][3])%DI<<"\n";
    
}
