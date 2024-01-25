#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAXRANGE 100'001
using namespace std;

int main() {
    fast;
    int dp[MAXRANGE][3];
    vector<int> input(MAXRANGE);
    int N; cin>>N;
    
    for(int i=1; i<=N; ++i)
        cin>>input[i];
    
  
    
    int res = input[1];
    for(int i=1; i<=N; ++i) {
        dp[i][0] = input[i];
        dp[i][1] = input[i];
        if(i==1) continue;
        dp[i][0] = max(dp[i-1][0] + input[i], input[i]);
        dp[i][1] = max(dp[i-1][1] + input[i], dp[i-1][0]);
        res = max(res, max(dp[i][0], dp[i][1]));
    }
    cout<<res<<"\n";
}
