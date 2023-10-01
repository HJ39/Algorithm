#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int input[51][51];
int dist[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dijkstra(){
    priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> q;
    q.push({1,1});
    dist[1][1] = 0;
    
    while(!q.empty()){
        auto [x,y] = q.top();
        q.pop();
        
        for(int i=0; i<4; ++i){
            int mx = dx[i] + x;
            int my = dy[i] + y;
            
            if(mx<1 or my<1 or mx>n or my>n)
                continue;
            
            if(input[mx][my] == 0 and dist[mx][my] > dist[x][y] + 1){
                dist[mx][my] = dist[x][y] + 1;
                q.push({mx,my});
            }
            else if(input[mx][my] == 1 and dist[mx][my] > dist[x][y]){
                dist[mx][my] = dist[x][y];
                q.push({mx,my});
            }
            
        }
        
    }
    
    
    
}

int main(){
    fast;
    
    cin>>n;
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            char a; cin>>a;
            input[i][j] = a-'0';
            dist[i][j] = INT_MAX;
        }
    }
    
    dijkstra();

    cout<<dist[n][n]<<"\n";
    
}
