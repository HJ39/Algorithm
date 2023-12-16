#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long ll;
int N;
vector<tuple<ll, ll, ll>> input;
priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> q;

void sol() {
    for(int i=1; i<N; ++i) {
        auto [s, e, n] = input[i];
        auto [qe, qs, qn] = q.top();
        
        if(qe <= s)
            q.pop();
        q.push({e,s,n});
    }
    cout<<q.size()<<"\n";
}

int main(){
    fast;
    
    cin>>N;
    
    for (int i=0; i<N; ++i) {
        ll a,b,c; cin>>a>>b>>c;
        input.push_back({b,c,a});
    }
    sort(input.begin(), input.end());
    
    auto [b,c,a] = input[0];
    q.push({c,b,a});
    sol();
}
