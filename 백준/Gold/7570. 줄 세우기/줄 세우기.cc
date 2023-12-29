#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int dp[1'000'001];
int nToi[1'000'001];
int iToN[1'000'001];

int main(){
    fast;
    
        int N; cin>>N;
    
    
        for(int i=0; i<N; ++i) {
            int a; cin>>a;
            nToi[a] = i;
            iToN[i] = a;
        }
    
        int res = 0;
        for(int i=N-1; i>=0; --i) {
                dp[i] = dp[nToi[iToN[i] + 1]] + 1;
            res = max(res, dp[i]);
        }
        cout<<N - res<<"\n";
}
