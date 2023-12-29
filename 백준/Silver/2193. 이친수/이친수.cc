#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
typedef long long ll;
ll dp[91];
int main(){
    fast;
    
    int N; cin>>N;
    
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3; i<=N; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[N]<<"\n";
}
