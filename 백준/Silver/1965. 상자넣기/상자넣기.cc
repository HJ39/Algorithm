#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int dp[1001];
int main(){
    fast;
    
    int N; cin>>N;
    vector<int> input(N+1);
    
    for(int i=1; i<=N; ++i)
        cin>>input[i];
    
    for(int i=1; i<=N; ++i) {
        dp[i] = 1;
        for(int j=1; j<i; ++j) {
            if(input[j] < input[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int res = 0;
    for(int i=1; i<=N; ++i)
        res = max(res, dp[i]);
    cout<<res<<"\n";
}
