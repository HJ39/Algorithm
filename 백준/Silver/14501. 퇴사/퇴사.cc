#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;


int dp[20];

int main(){
    fast;
    
    int N; cin>>N;
    vector<pair<int, int>> input(N+1);
    
    for(int i=1; i<=N; ++i) {
        int time, pay; cin>>time >>pay;
        input[i].first = time + i;
        input[i].second = pay;
    }
    
    dp[0] = 0;
    for(int i=1; i<=N; ++i) {
        int sum = 0;
        for(int j=1; j<i; ++j) {
            if(i >= input[j].first) {
                sum = max(sum, dp[j]);
            }
        }
        if(input[i].first <= N+1)
            dp[i] = sum + input[i].second;
    }
    
    int res = 0;
    for(int i=1; i<=N; ++i)
        res = max(res, dp[i]);
    cout<<res<<"\n";
}
