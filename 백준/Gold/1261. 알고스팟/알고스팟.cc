#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N,M;
int input[101][101];
int dist[101][101];
//priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>> q;
queue<tuple<int,int>> q;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dijkstra(){
    
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        
        for(int i=0; i<4; ++i){
            int mx = dx[i] + x;
            int my = dy[i] + y;
            
            if(mx<1 or my<1 or mx>M or my>N)
                continue;
            
            if(input[mx][my] == 1){
                if(dist[mx][my] > dist[x][y] + 1){
                    dist[mx][my] = dist[x][y] + 1;
                    q.push({mx,my});
                }
                
            }
            else if(input[mx][my] == 0){
                if(dist[mx][my] > dist[x][y]){
                    dist[mx][my] = dist[x][y];
                    q.push({mx,my});
                }
            }
        }
    }
}

int main(){
    fast;
    
    cin>>N>>M;
    
    for(int i=1; i<=M; ++i){
        for(int j=1; j<=N; ++j){
            char a; cin>>a;
            input[i][j] = a-'0';
            dist[i][j] = INT_MAX;
        }
    }

    
    q.push({1,1});
    dist[1][1] = 0;
    dijkstra();
    
    cout<<dist[M][N]<<"\n";
}
