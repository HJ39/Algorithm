#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N,M;
int arr[1001][1001];
queue<pair<int, int>> qm;
int cnt = 0;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


void bfs(){
    queue<pair<int, int>> q;
    
    while (!qm.empty()) {
        
        while (!qm.empty()) {
            q.push({qm.front().first,qm.front().second});
            qm.pop();
        }
        cnt++;
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=0; i<4; ++i){
                int mx = dx[i] + x;
                int my = dy[i] + y;
                
                if (mx<=0 || mx>M || my<=0 || my>N)
                    continue;
                
                if(arr[mx][my] == 0){
                    qm.push({mx,my});
                    arr[mx][my] = 1;
                }
            }
        }
        
    }
}

bool check(){
    for(int i=1; i<=M; ++i){
        for(int j=1; j<=N; ++j){
            if (arr[i][j] == 0)
                return false;
        }
    }
    return true;
}
int main(){
    fast;
    
    cin>>N>>M;
    
    for(int i=1; i<=M; ++i){
        for(int j=1; j<=N; ++j){
            cin>>arr[i][j];
            if(arr[i][j] == 1) qm.push({i,j});
        }
    }
    
    bfs();
    if(check())
        cout<<cnt-1<<"\n";
    else
        cout<<"-1\n";
    
}
