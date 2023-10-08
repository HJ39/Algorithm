#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int input[101][101];
int result[101][101];
bool check[101][101];
int W,H;
vector<pair<int,int>> point;
queue<tuple<int,int>> q;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void lazer(){
    
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        
        for(int i=0; i<4; ++i){
            int mx = x + dx[i];
            int my = y + dy[i];
            
            while(true){
                if(mx < 1 or my < 1 or mx > H or my > W or input[mx][my] == -1)
                    break;
                
                if(result[mx][my] == 0){
                    result[mx][my] = result[x][y] + 1;
                    q.push({mx,my});
                }
                mx += dx[i];
                my += dy[i];
            }
        }
    }
    
    cout<<result[point[1].first][point[1].second] - 1<<"\n";
}

int main(){
    fast;
    cin>>W>>H;
    
    for(int i=1; i<=H; ++i){
        for(int j=1; j<=W; ++j){
            char a;
            cin>>a;
            
            if (a== '*')
                input[i][j] = -1;
            else if(a == '.')
                input[i][j] = 0;
            else
                point.push_back({i,j});
        }
    }
    
    q.push({point[0].first,point[0].second});
    lazer();
 
}
