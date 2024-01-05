#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define HAPPY 1
#define HEALTH 0
#define MAXHEALTH 101

using namespace std;
int dp[21][MAXHEALTH];

int main(){
    fast;
    int N; cin>>N;
    
    int input[21][2];
    for(int i=1; i<=N; ++i)
        cin>>input[i][HEALTH];
    
    for(int i=1; i<=N; ++i)
        cin>>input[i][HAPPY];
    
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<MAXHEALTH; ++j) {
            if(j - input[i][HEALTH] > 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-input[i][HEALTH]] + input[i][HAPPY]);
                continue;
            }
            dp[i][j] = dp[i-1][j];
        }
    }
   
    int res = 0;
    for(int i=1; i<=100; ++i)
        res = max(res, dp[N][i]);
    cout<<res<<"\n";
    
}
