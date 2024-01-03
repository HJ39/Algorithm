#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int dp[1001][1001], input[1001][1001];
int dx[] = {1,0,1};
int dy[] = {0,1,1};

int main(){
    fast;
    
    int N,M; cin>>N>>M;
    
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j)
            cin>>input[i][j];
 
    dp[1][1] = input[1][1];
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=M; ++j) {
            for(int k=0; k<3; ++k) {
                int mx = i+dx[k];
                int my = j+dy[k];
                if(mx<1 or my<1 or mx>N or my>M) continue;
                dp[mx][my] = max(dp[mx][my], input[mx][my] + dp[i][j]);
            }
        }
    }
    
    cout<<dp[N][M]<<"\n";
}
