#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
typedef long long ll;

ll dp[1'500'010];

int main(){
    fast;
    
    ll N; cin>>N;
    vector<pair<ll, ll>> input(N+1);
    
    for(ll i=1; i<=N; ++i)
        cin>> input[i].first >> input[i].second;
    
    ll cnt = 0;
    for(ll i=1; i<=N+1; ++i) {
        cnt = max(cnt, dp[i]);
        if(i+ input[i].first > N+1) continue;
        dp[i+input[i].first] = max(cnt + input[i].second, dp[i + input[i].first]);
    }
 
    cout<<cnt<<"\n";
}

