#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
typedef long long ll;

int main(){
    fast;
    
    int N; cin>>N;
    vector<ll> dp(N+1);
    
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=N; ++i) {
        dp[i] = ((dp[i-1]%10) + (dp[i-2]%10))%10;
    }
    cout<<dp[N]<<"\n";
}
