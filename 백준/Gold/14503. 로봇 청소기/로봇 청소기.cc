#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N14503, M14503;
vector<vector<int>> input14503(51,vector<int>(51,0));
int clean14503 = 0;

int back14503(int d){
    if(d == 0)
        return 2;
    else if (d == 1)
        return 3;
    else if(d == 2)
        return 0;
    else
        return 1;
}

void dfs14503(int x, int y, int d){
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    
    if(x<0 || x>=N14503 || y<0 || y>=M14503 || input14503[x][y] == 1)
        return;
    
    for(int i=0;i<4;++i){
        d--;
        if(d<0) d=3;
        
        int mx = dx[d] + x;
        int my = dy[d] + y;
        
        if(input14503[mx][my] == 0){
            clean14503++;
            input14503[mx][my] = 2;
            dfs14503(mx, my, d);
        }
    }
    
    int backD = back14503(d);
    int backX = x + dx[backD];
    int backY = y + dy[backD];
    
    if(input14503[backX][backY] == 0 or input14503[backX][backY] == 2){
        dfs14503(backX, backY, d);
    }
    else{
        
            cout<<clean14503<<"\n";
        exit(0);
    }
    
    
    
}

int main(){
    fast;
    
    cin>>N14503>>M14503;
    int x,y,d; cin>>x>>y>>d;
    
    for(int i=0;i<N14503;++i){
        for(int j=0;j<M14503;++j){
            cin >> input14503[i][j];
        }
    }
    
    input14503[x][y] = 2;
    clean14503++;
    dfs14503(x, y, d);
    
    cout<<clean14503<<"\n";
    
    
}
