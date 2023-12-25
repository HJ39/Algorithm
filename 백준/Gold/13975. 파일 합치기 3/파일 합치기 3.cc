#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
typedef long long ll;

int main(){
    fast;
    
    int testCase; cin>>testCase;
    
    while (testCase--) {
        int M; cin>>M;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        ll res = 0;
        for(int i=0; i<M; ++i) {
            ll a; cin>>a;
            q.push(a);
        }
        
        while (q.size() > 1) {
            ll first = q.top(); q.pop();
            ll second = q.top(); q.pop();

            res += first + second;
            q.push(first + second);
        }
        cout<<res<<"\n";
    }
}