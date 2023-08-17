#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int R, C;
int arr[21][21];
int alaphbet[26];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int cnt = 0;

void dfs(int x, int y, int count){
    
    if(x<=0 or x>R or y<=0 or y >C)
        return;
    
    for(int i=0; i<4; ++i){
        int mx = dx[i] + x;
        int my = dy[i] + y;
        
        if(alaphbet[arr[mx][my]] == 0){
            alaphbet[arr[mx][my]] = 1;
            dfs(mx, my, count+1);
            alaphbet[arr[mx][my]] = 0;
        }
        else{
            cnt = max(cnt, count);
        }
    }
    
    
}


int main(){
    fast;
    cin>>R>>C;
    
    for(int i=1; i<=R; ++i){
        for(int j=1; j<=C; ++j){
            char input;
            cin >> input;
            arr[i][j] = input - 'A';
        }
    }
    
    alaphbet[arr[1][1]] = 1;
    dfs(1, 1, 1);
    
    cout<<cnt<<"\n";
    
}
