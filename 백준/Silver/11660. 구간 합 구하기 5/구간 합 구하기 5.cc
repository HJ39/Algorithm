#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int dp[1025][1025];

int main(){
    fast;
    
    int N,M; cin>>N>>M;
    
    int input[N+1][N+1];
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            cin>>input[i][j];
            dp[i][j] += dp[i][j-1] + input[i][j];
        }
    }
    
    for(int i=0; i<M; ++i) {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        int sum = 0;
        for(int j=x1; j<=x2; ++j) {
            sum += (dp[j][y2] - dp[j][y1-1]);
        }
        cout<<sum<<"\n";
    }
    
    
}
