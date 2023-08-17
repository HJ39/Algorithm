#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N,M,H;
int arr[101][101][101];
queue<tuple<int,int,int>> qm;
int cnt = 0;
int dx[] = {0,0,1,-1,0,0};
int dy[] = {1,-1,0,0,0,0};
int dz[] = {0,0,0,0,1,-1};


void bfs(){
    queue<tuple<int,int,int>> q;
    
    while (!qm.empty()) {
        
        while (!qm.empty()) {
            auto [z,x,y] = qm.front();
            q.push({z,x,y});
            qm.pop();
        }
        cnt++;
        
        while (!q.empty()) {
            auto [z,x,y] = q.front();
            q.pop();
            
            for(int i=0; i<6; ++i){
                int mx = dx[i] + x;
                int my = dy[i] + y;
                int mz = dz[i] + z;
                
                if (mx<=0 || mx>M || my<=0 || my>N || mz<=0 || mz> H)
                    continue;
                
                if(arr[mz][mx][my] == 0){
                    qm.push({mz,mx,my});
                    arr[mz][mx][my] = arr[z][x][y] + 1;
                }
            }
        }
        
    }
}

bool check(){
    for(int k=1; k<=H; ++k){
        for(int i=1; i<=M; ++i){
            for(int j=1; j<=N; ++j){
                
                if (arr[k][i][j] == 0)
                    return false;
            }
        }
    }
    return true;
}

int main(){
    fast;
    
    cin>>N>>M>>H;
    
    for(int k=1; k<=H; ++k){
        for(int i=1; i<=M; ++i){
            for(int j=1; j<=N; ++j){
                cin>>arr[k][i][j];
                if(arr[k][i][j] == 1) qm.push({k,i,j});
            }
        }
    }
    
    bfs();
    
    if(check())
        cout<<cnt-1<<"\n";
    else
        cout<<"-1\n";
}
