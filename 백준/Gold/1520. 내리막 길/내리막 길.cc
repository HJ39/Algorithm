#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int M,N;
int arr[501][501];
int dp[501][501] = {-1};
bool visited[501][501] = {false};
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int dfs(int x, int y){

    if (x == M and y == N) return 1;
    if (visited[x][y]) return dp[x][y];

    dp[x][y] = 0;
    visited[x][y] = true;
    for(int i=0; i<4; ++i){
        int mx = dx[i] + x;
        int my = dy[i] + y;

        if(mx < 1 or mx > M or my < 1 or my > N)
            continue;

        if(arr[mx][my] < arr[x][y]){
            dp[x][y] += dfs(mx, my);
        }
    }

    return dp[x][y];
}


int main(){
    fast;
    
    cin>>M>>N;
    
    for(int i=1;i<=M; ++i)
        for(int j=1;j<=N; ++j)
            cin>>arr[i][j];

    cout<<dfs(1, 1)<<"\n";
    
}
