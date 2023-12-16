#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long ll;
int N;
vector<pair<ll, ll>> input;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;

void sol() {
    for(int i=1; i<N; ++i) {
        auto [s, e] = input[i];
        auto [qb, qa] = q.top();
        
        if(qb <= s)
            q.pop();
        q.push({e, s});
    }
    cout<<q.size()<<"\n";
}

int main(){
    fast;
    
    cin>>N;
    for(int i=0; i<N; ++i) {
        ll a, b; cin>>a>>b;
        input.push_back({a, b});
    }
    
    sort(input.begin(), input.end());
    q.push({input[0].second, input[0].first});
    sol();
}
