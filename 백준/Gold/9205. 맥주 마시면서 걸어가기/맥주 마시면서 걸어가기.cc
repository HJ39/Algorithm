#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

pair<int, int> start, last;
vector<pair<int, int>> input;
bool check[101];

bool bfs(int n) {
    queue<pair<int, int>> q;
    q.push(start);
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if(abs(last.first - x) + abs(last.second - y) <= 1000)
            return true;
        
        for(int i=0; i<n; ++i) {
            if(check[i]) continue;
            
            if(abs(input[i].first - x) + abs(input[i].second - y) <= 1000) {
                q.push(input[i]);
                check[i] = true;
            }
        }
    }
    
    return false;
}

int main() {
    fast;
    
    int t; cin>>t;
    
    while (t--) {
        int n; cin>>n;
        
        cin >> start.first >> start.second;
        
        for(int i=0; i<n; ++i) {
            int s,e; cin>>s>>e;
            input.push_back({s,e});
        }
        
        cin >> last.first >> last.second;
        
        if(bfs(n))
            cout<<"happy\n";
        else
            cout<<"sad\n";
        
        input.clear();
        fill_n(check, 101, false);
    }
}
