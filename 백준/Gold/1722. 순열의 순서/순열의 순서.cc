#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long ll;
ll N, k;
ll c;

bool check[21];
ll  res[21];

int main(){
    fast;
    cin >>N >>k;
    
    res[0] = 1;
    for(int i=1; i<=N; ++i)
        res[i] = res[i-1] * i;
    
    if (k==1) {
        cin>>c;
        vector<ll> input(21);
        
        for(int i=1; i<=N; ++i) {
            for(int j=1; j<=N; ++j) {
                if(check[j]) continue;
                if(res[N-i] < c) {
                    c -= res[N-i];
                } else {
                    input[i] = j;
                    check[j] = true;
                    break;
                }
            }
        }
        
        for(int i=1; i<=N; ++i)
            cout<<input[i]<<" ";
        cout<<"\n";
        
    } else if (k==2) {
        vector<ll> input(21);
        for(int i=1; i<=N; ++i) {
            cin>>input[i];
        }
        ll ans = 1;
        
        for(int i=1; i<=N; ++i) {
            for(int j=1; j<input[i]; ++j) {
                if(!check[j]) {
                    ans += res[N-i];
                }
            }
            check[input[i]] = true;
        }
        cout<<ans<<"\n";
    }
}