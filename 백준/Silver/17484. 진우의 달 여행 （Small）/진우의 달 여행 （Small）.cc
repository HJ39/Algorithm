#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 987654321
using namespace std;

int input[7][7], dp[7][7][4];
int N, M;
int dd[] = {-1, 0, 1, MAX};

// sol
// 0: 왼, 1: 가, 2: 오
int sol(int x, int y, int past) {
    if(1>y or y>M) return MAX;
    if(x == N)  return input[x][y];
    int &val = dp[x][y][past];
    if(val != MAX) return val;
    
    for(int i=0; i<3; ++i) {
        if(i == past) continue;
        val = min(val, input[x][y] + sol(x+1, y + dd[i] , i));
    }
    
    return val;
}

int main(){
    fast;
    cin>>N>>M;
    
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j)
            cin>>input[i][j];
    
    fill(&dp[0][0][0], &dp[6][6][4], MAX);
  
    int res = MAX;
    for(int j=1; j<=M; ++j)
        res = min(res, sol(1, j, 3));

    cout<<res<<"\n";
}