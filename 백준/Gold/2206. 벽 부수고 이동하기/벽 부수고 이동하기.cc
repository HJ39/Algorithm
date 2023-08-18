#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N,M;
int input[1001][1001];
int check[2][1001][1001];
queue<tuple<int,int,bool>> q;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int bfs(){
    
    while (!q.empty()) {
        auto [x,y,power] = q.front();
        q.pop();
        
        if (x == N and y == M)
            return check[power][x][y];
        
        for(int i=0; i<4; ++i){
            int mx = dx[i] + x;
            int my = dy[i] + y;
            
            if(mx<1 or mx >N or my <1 or my>M)
                continue;
            
            if(input[mx][my] == 1 and power ){
                check[0][mx][my] = check[1][x][y] + 1;
                q.push({mx,my,false});
            }
            else if(input[mx][my] == 0 and check[power][mx][my] == 0){
                check[power][mx][my] = check[power][x][y] + 1;
                q.push({mx,my,power});
            }
        }
    }
    return -1;
}


int main(){
    fast;
    cin>>N>>M;
    
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            char a; cin>>a;
            input[i][j] = a - '0';
        }
    }
    
    q.push({1,1,true});
    check[1][1][1] = 1;
    int cnt =  bfs();
    cnt == -1 ? cout<<"-1\n" : cout<<cnt<<"\n";
}