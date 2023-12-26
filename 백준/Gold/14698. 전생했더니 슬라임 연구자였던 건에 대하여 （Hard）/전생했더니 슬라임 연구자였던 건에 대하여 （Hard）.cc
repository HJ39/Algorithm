#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define DI 1'000'000'007
using namespace std;

typedef long long ll;

int main(){
    fast;
    
    int test; cin>>test;
    
    while (test--) {
        int N; cin>>N;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for(int i=0; i<N; ++i) {
            ll a; cin>>a;
            q.push(a);
        }
        
        ll res = 1;
        while (q.size() > 1) {
            ll f = q.top(); q.pop();
            ll s = q.top(); q.pop();
            
            res *= (f%DI*s%DI)%DI;
            res %= DI;
            q.push(f*s);
        }
        cout<<res%DI<<"\n";
    }
    
}
