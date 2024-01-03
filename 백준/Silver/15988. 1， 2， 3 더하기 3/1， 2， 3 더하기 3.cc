#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define DI 1'000'000'009
using namespace std;
typedef long long ll;

int main(){
    fast;
    
    int T; cin>>T;
    
    while (T--) {
        
        int n; cin>>n;
        
        ll dp[1'000'001];
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i=4; i<=n; ++i)
            dp[i] = (((dp[i-1]%DI) + (dp[i-2]%DI)%DI) + (dp[i-3]%DI)%DI);
        
        cout<<dp[n]%DI<<"\n";
    }
    
}
