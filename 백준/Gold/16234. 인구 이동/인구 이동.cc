#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
int N16234, L16234, R16234;
int input16234[51][51];
vector<vector<bool>> check16234(51,vector<bool>(51,false));


void bfs16234(int x, int y){
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    
    check16234[x][y] = true;
    queue<tuple<int,int>> q;
    vector<tuple<int,int>> u;
    u.push_back({x,y});
    q.push({x,y});
    
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        
        for(int i=0;i<4;++i){
            int mx = x + dx[i];
            int my = y + dy[i];
            
            if(mx<1 or my<1 or mx>N16234 or my>N16234)
                continue;
            
            int dis = abs(input16234[mx][my] - input16234[x][y]);
            if(dis <= R16234 and dis >= L16234 and !check16234[mx][my]){
                check16234[mx][my] = true;
                q.push({mx,my});
                u.push_back({mx,my});
            }
        }
    }
    
    int sum = 0;
    for(int i=0;i<u.size(); ++i){
        auto[x,y] = u[i];
        sum += input16234[x][y];
    }
    
    int avg = (int) sum / u.size();
    
    for(int i=0;i<u.size(); ++i){
        auto[x,y] = u[i];
        input16234[x][y] = avg;
    }
    
}


int main(){
    fast;
    
    cin>>N16234>>L16234>>R16234;
    
    for(int i=1;i<=N16234;++i)
        for(int j=1; j<=N16234; ++j)
            cin>>input16234[i][j];
    
    int count = 0;
    int time = 0;
    
    while (count != N16234*N16234) {
        count = 0;
        time++;
        for(int i=1;i<=N16234;++i){
            for(int j=1; j<=N16234; ++j){
                if(!check16234[i][j]){
                    bfs16234(i, j);
                    count++;
                }
            }
        }
        fill(check16234.begin(), check16234.end(), vector<bool>(51,false));
    }
    
    if(time != 0)
        cout<<time-1<<"\n";
    else
        cout<<time<<"\n";
}
