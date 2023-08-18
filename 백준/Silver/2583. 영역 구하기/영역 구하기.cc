#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int M,N,K;
int arr[101][101];
bool check[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int cnt = 0;
vector<int> result;

void bfs(int x, int y){
    queue<tuple<int,int>> q;
    q.push({x,y});
    check[x][y] = true;
    int count = 1;
    
    while (!q.empty()) {
        auto [a,b] = q.front();
        q.pop();
        
        for(int i=0; i<4; ++i){
            int mx = a + dx[i];
            int my = b + dy[i];
            
            if (mx<0 or mx>=N or my <0 or my>=M)
                continue;
            
            if(arr[mx][my] == 0 and !check[mx][my]){
                count++;
                check[mx][my] = true;
                q.push({mx,my});
            }
            
        }
        
    }
    
    result.push_back(count);
    
}


int main(){
    fast;
    
    cin>>M>>N>>K;

    for(int i=0;i<K;++i){
        int x,y,p,q;
        cin>> x>>y>>p>>q;
        
        for(int i=x; i<p; ++i){
            for(int j=y; j<q; ++j){
                arr[i][j] = 1;
            }
        }
    }
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(arr[i][j] == 0 and !check[i][j]){
                cnt++;
                bfs(i, j);
            }
        }
    }
    
    
    cout<<cnt<<"\n";
    sort(result.begin(), result.end());
    for(int i=0; i<cnt; ++i)
        cout<<result[i]<<" ";
}
