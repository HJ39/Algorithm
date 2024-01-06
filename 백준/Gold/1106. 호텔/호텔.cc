#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define M 100'001
using namespace std;

int dp[M];
int main(){
    fast;
    
    int C,N; cin>>C>>N;
    
    pair<int, int> input[21];
    for(int i=1; i<=N; ++i)
        cin>>input[i].first>>input[i].second;
    
    for(int i=1; i<=N; ++i)
        for(int j=1; j<M; ++j)
            if(j-input[i].first>= 0)
                dp[j] = max(dp[j], dp[j-input[i].first] + input[i].second);
    
    for(int j=1; j<M; ++j) {
        if(dp[j] >= C) {
            cout<<j<<"\n";
            break;
        }
    }
        
}
