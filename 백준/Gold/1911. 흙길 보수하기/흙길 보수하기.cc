#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long ll;
int N, L;
vector<pair<ll, ll>> input;

void sol() {
    int res = 0;
    ll idx = 0;
    for(int i=0; i<N; ++i) {
        if(idx >= input[i].second)
            continue;
        
        idx = max(idx, input[i].first);
        
        ll cnt = (input[i].second - (idx + 1))/L + 1;
        res += cnt;
        idx += L * cnt;
    }
    cout<<res<<"\n";
}

int main(){
    fast;
    
    cin>>N>>L;
    
    for(int i=0; i<N; ++i) {
        ll a, b; cin>>a>>b;
        input.push_back({a, b});
    }
    
    sort(input.begin(), input.end());
    
    
    sol();
}
