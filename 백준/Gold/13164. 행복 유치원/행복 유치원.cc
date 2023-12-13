#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long ll;
vector<ll> height, dis;
int N, K;

int main() {
    fast;
    
    cin>>N>>K;
    
    for(int i=0; i<N; ++i) {
        ll a; cin>>a;
        height.push_back(a);
    }
    
    for(int i=1; i<N; ++i)
        dis.push_back(height[i] - height[i-1]);
    
    sort(dis.begin(), dis.end());
    
    ll res = 0;
    for(int i=0; i<N-K; ++i)
        res += dis[i];
    
    cout<<res<<"\n";
}
