#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

bool check[1001][1001];
int S;

int bfs() {
    queue<tuple<int, int, int>> q;
    
    q.push({1, 0, 0});
    
    while (!q.empty()) {
        auto [screen, clip, time] = q.front();
        q.pop();
        
        if(screen == S) return time;
        
        if(screen > 1000 or screen <= 0) continue;
        
        if(!check[screen][screen]) {
            check[screen][screen] = true;
            q.push({screen, screen, time+1});
        }
        
        if(!check[screen-1][screen]) {
            check[screen-1][screen] = true;
            q.push({screen-1, clip, time+1});
        }
        
        if(screen + clip <= 1000 and !check[screen + clip][screen]) {
            check[screen + clip][screen] = true;
            q.push({screen + clip, clip, time+1});
        }
    }
    return 0;
}

int main() {
    fast;
    cin>>S;
    
    cout<<bfs()<<"\n";
}
