#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
#define MAX 126
using namespace std;

int n;
int input[MAX][MAX];
int dist[MAX][MAX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dijkstra(){
    priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> q;
    q.push({0,0});
    dist[0][0] = input[0][0];
    
    while(!q.empty()){
        auto [x,y] = q.top();
        q.pop();
        
        for(int i=0; i<4; ++i){
            int mx = dx[i] + x;
            int my = dy[i] + y;
            
            if(mx<0 or my<0 or mx>=n or my>=n)
                continue;
            
            if(dist[mx][my] > dist[x][y] + input[mx][my]){
                dist[mx][my] = dist[x][y] + input[mx][my];
                q.push({mx,my});
            }
            
        }
        
    }
    
    
    
}

int main(){
    fast;
    int cnt = 1;
    while(1){
        cin>>n;
        
        if(n == 0)
            break;
        
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                cin>>input[i][j];
        
        fill(&dist[0][0], &dist[MAX-1][MAX-1], INT_MAX);
        dijkstra();
        
        cout<<"Problem "<<cnt++<<": "<<dist[n-1][n-1]<<"\n";
    }
}
