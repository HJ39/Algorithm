#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 987654321
using namespace std;

int input[7][7], check[7];
int N, M;
int dd[] = {-1, 0, 1, MAX};
int res = MAX;

void dfs(int x, int y, int past) {
    if(x == N+1) {
        int sum = 0;
        for(int i=1; i<=N; ++i) {
            sum += input[i][check[i]];
        }
        res = min(res, sum);
        return;
    }
  
    for(int i=0; i<3; ++i) {
        int dy = y + dd[i];
        if(dy<1 or dy>M or past == i) continue;
        check[x] = dy;
        dfs(x+1, dy, i);
    }
}

int main(){
    fast;
    cin>>N>>M;
    
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j)
            cin>>input[i][j];

    for(int j=1; j<=M; ++j)
        dfs(1, j, 3);
    
    cout<<res<<"\n";
}