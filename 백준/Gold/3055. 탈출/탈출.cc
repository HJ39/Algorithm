#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int R, C;
char arr[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
queue<tuple<int,int>> hegeQ;
queue<tuple<int,int>> water;
int cnt = 0;

int bfs(){
    
    while (!hegeQ.empty()) {
        
        int wSize = water.size();
        for(int i=0; i<wSize; ++i) {
            auto [wX, wY] = water.front();
            water.pop();
            
            for(int i=0;i<4; ++i) {
                int mwX = wX + dx[i];
                int mwY = wY + dy[i];
                
                if(mwX < 1 or mwX > R or mwY < 1 or mwY > C or arr[mwX][mwY] == 'X')
                    continue;
                
                if(arr[mwX][mwY] == '.' or arr[mwX][mwY] == 'S') {
                    water.push({mwX,mwY});
                    arr[mwX][mwY] = '*';
                }
            }
        }
        
        int hSize = hegeQ.size();
        for(int i=0; i<hSize; ++i) {
            auto [hX, hY] = hegeQ.front();
            hegeQ.pop();
            
            for(int i=0;i<4; ++i) {
                int mhX = hX + dx[i];
                int mhY = hY + dy[i];
                
                if(mhX < 1 or mhX > R or mhY < 1 or mhY > C or arr[mhX][mhY] == 'X')
                    continue;
                
                if(arr[mhX][mhY] == 'D')
                    return cnt+1;
                
                if(arr[mhX][mhY] == '.') {
                    hegeQ.push({mhX,mhY});
                    arr[mhX][mhY] = 'S';
                }
            }
        }
        cnt++;
    }
    
    return -1;
}

int main(){
    fast;
    cin>>R>>C;
    
    for(int i=1; i<=R; ++i){
        for(int j=1; j<=C; ++j){
            char a; cin>>a;
            arr[i][j] = a;
            if(a == '*')
                water.push({i,j});
            else if(a == 'S')
                hegeQ.push({i,j});
            
        }
    }
    
    int res = bfs();
    res == -1 ? cout<<"KAKTUS\n" : cout<<res<<"\n";
}
