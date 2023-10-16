#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
#define INF 987654321
using namespace std;

char input[51][51];
int moving[4][51][51];
int N;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
vector<pair<int,int>> point;
int res = INT_MAX;
//2151

void print(int k){
    cout<<"\n";
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j)
            cout<<moving[k][i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

void mirror(int a, int b){
    queue<tuple<int, int, int, int>> q;
    
    for(int i=0; i<4; ++i){
        moving[i][a][b] = 0;
        q.push({a,b,i,0});
    }
    
    while (!q.empty()) {
        auto [x,y,dir,cnt] = q.front();
        q.pop();
        
        if(x == point[1].first and y == point[1].second){
            res = min(res,cnt);
        }
        
        int mx = x + dx[dir];
        int my = y + dy[dir];
        
        if(mx<1 or my<1 or mx>N or my>N or input[mx][my] == '*')
            continue;
        
        if(moving[dir][mx][my] > cnt){
            q.push({mx, my, dir, cnt});
            moving[dir][mx][my] = cnt;
        }
        
        if(input[mx][my] == '!'){
            int nd = (dir+1)%4;
            if(moving[nd][mx][my] > cnt + 1){
                q.push({mx, my, nd, cnt+1});
                moving[nd][mx][my] = cnt + 1;
            }
            
            nd = (dir+3)%4;
            if(moving[nd][mx][my] > cnt + 1){
                q.push({mx, my, nd, cnt+1});
                moving[nd][mx][my] = cnt + 1;
            }
        }
        
    }
    
}

int main(){
    fast;
    
    cin>>N;
    
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            char a; cin>>a;
            input[i][j] = a;
            if(a == '#'){
                point.push_back({i,j});
            }
        }
    }
    
    for(int k=0;k<4; ++k)
        for(int i=1; i<=N; ++i)
            for(int j=1; j<=N; ++j)
                moving[k][i][j] = INF;
    
    mirror(point[0].first, point[0].second);

    cout<<res<<"\n";
}