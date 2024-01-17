#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int input[51][51];
bool check[51][51];
int dis[51][51];
int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
queue<pair<int, int>> q;

int bfs(int x, int y) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({x,y});
    check[x][y] = true;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for(int i=0; i<4; ++i) {
            int mx = x + dx[i];
            int my = y + dy[i];
            
            if(mx < 1 or my < 1 or mx > n or my > m) continue;
            
            if(input[mx][my] == 1 and !check[mx][my]) {
                check[mx][my] = true;
                q.push({mx,my});
                dis[mx][my] = dis[x][y] + 1;
                cnt = max(cnt, dis[mx][my]);
            }
        }
    }
    
    return cnt;
}

void reset() {
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            dis[i][j] = 0;
            check[i][j] = false;
        }
    }
}

int main() {
    fast;
    
    cin >> n >> m;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            char a; cin>>a;
            a == 'L' ? input[i][j] = 1 : input[i][j] = 0;
        }
    }

    int res = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(input[i][j] == 1 and !check[i][j]) {
                res = max(res, bfs(i, j));
                reset();
            }
        }
    }
    
    cout<<res<<"\n";
}
