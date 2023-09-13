#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
using namespace std;

int N;
int input[17][17];
int dx[] = {0,1,1};
int dy[] = {1,0,1};
queue<tuple<int,int,int>> q; // dir 0: 가로, 1: 세로, 2: 대각선
int cnt = 0;

bool checkDiagonal(int x, int y){
    for(int i=0;i<3;++i){
        int mx = x + dx[i];
        int my = y + dy[i];
        
        if(mx<1 or my<1 or mx>N or my >N)
            continue;
        
        if(input[mx][my] == 1)
            return false;
    }
    return true;
}

void bfs(){
    
    while (!q.empty()) {
        auto[x,y,dir] = q.front();
        q.pop();
        
        if(x == N and y == N){
            cnt++;
        }
            
        for(int i=0;i<3;++i){
            int mx = x + dx[i];
            int my = y + dy[i];
            
            if(mx<1 or my<1 or mx>N or my >N)
                continue;
            if(dir == 0){ //가로

                if(i == 0 and input[mx][my] == 0) //가로 -> 가로
                    q.push({mx,my,0});
                if(checkDiagonal(x,y) && i ==2)  //대각선
                    q.push({mx,my,2});
            }
            else if(dir == 1 ){ // 세로

                if(i == 1 and input[mx][my] == 0) // 세로 -> 세로
                    q.push({mx,my,1});
                if(checkDiagonal(x,y) && i == 2)   //대각선
                    q.push({mx,my,2});
            }
            else if(dir == 2){ // 대각선

                if(i == 0 and input[mx][my] == 0) // 대각선 -> 가로
                    q.push({mx,my,0});
                if(i == 1 and input[mx][my] == 0) // 대각선 -> 세로
                    q.push({mx,my,1});
                if(checkDiagonal(x,y) && i ==2)   //대각선
                    q.push({mx,my,2});
            }
            
        }
    }
    
}

int main(){
    fast;
    
    cin>>N;
    
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cin>>input[i][j];
        }
    }
    
    q.push({1,2,0});
    bfs();
    cout<<cnt<<"\n";
    
    
}
