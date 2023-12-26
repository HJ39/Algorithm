#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
typedef long long ll;

vector<pair<ll, ll>> input;
ll sum[100'001];
ll N;

ll binarySeacrh() {
    ll start = 0;
    ll end = N-1;
    ll pos = INFINITY;
    
    while (start <= end) {
        ll mid = (start + end)/2;
        
        ll lSum = sum[mid];
        ll rSum = sum[N-1] - sum[mid];
        if(lSum >= rSum) {
            end = mid - 1;
            pos = min(pos, input[mid].first);
        } else {
            start = mid + 1;
        }
    }
    
    return pos;
}

int main(){
    fast;
    
    cin>>N;
    
    for(ll i=0; i<N; ++i) {
        ll a, b; cin>>a>>b;
        input.push_back({a,b});
    }
    
    sort(input.begin(), input.end());
    
    sum[0] = input[0].second;
    for(ll i=1; i<N; ++i) {
        sum[i] += sum[i-1] + input[i].second;
    }
    
    cout<<binarySeacrh()<<"\n";
    
}