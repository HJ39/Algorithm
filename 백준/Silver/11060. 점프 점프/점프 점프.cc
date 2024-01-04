#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INF 987654321
using namespace std;

int dp[1001];
int jump[1001];
int main(){
    fast;
        
    int N; cin>>N;
    
    vector<int> input(N+1);
    for(int i=1; i<=N; ++i)
        cin>>input[i];
    
    fill_n(dp, 1001, INF);
    dp[1] = 0;
    for(int i=1; i<=N; ++i) {
        
        for(int j=i+1; j<=min(N,i+input[i]); ++j) {
            dp[j] = min(dp[j], dp[i]+1);
        }
       
    }
    
    if(dp[N] == INF)
        cout<<"-1\n";
    else
        cout<<dp[N]<<"\n";
        
}
