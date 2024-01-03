#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 1'000'000'009

using namespace std;
typedef long long ll;

int main(){
    fast;
    
    int T; cin>>T;
    
    while (T--) {
        int N; cin>>N;
        ll dp[100'001][4];
        
        dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
        dp[2][1] = 0; dp[2][2] = 1; dp[2][3] = 0;
        dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
        for(int i=4; i<=N; ++i) {
            dp[i][1] = (dp[i-1][2] + dp[i-1][3])%MAX;
            dp[i][2] = (dp[i-2][1] + dp[i-2][3])%MAX;
            dp[i][3] = (dp[i-3][1] + dp[i-3][2])%MAX;
        }
        cout<<(dp[N][1] + dp[N][2] + dp[N][3])%MAX<<"\n";
    }   
}