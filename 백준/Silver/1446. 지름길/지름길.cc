#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
int dist[10'001];
vector<pair<int, int>> adj[10'001];
int n,d;

void dijkstra(){

    while(!q.empty()){
        auto now = q.top();
        q.pop();

        if(now.first > dist[now.second])
            continue;
        
        for(auto &i: adj[now.second]){
            pair<int,int> next  = { now.first + i.second, i.first};
            
            if(next.first < dist[next.second]){
                dist[next.second] = next.first;
                q.push(next);
            }
        }
    }
}

int main() {
    fast;

    cin>>n>>d;

    for(int i=0; i<d; ++i)
        adj[i].push_back({i+1,1});

    for(int i=0; i<n; ++i){
        int s,e,l;
        cin>>s>>e>>l;
        adj[s].push_back({e,l});
    }

    fill_n(dist,10'001,INT_MAX);
    dist[0] = 0;
    q.push({0,0});

    dijkstra();

    cout<<dist[d]<<"\n";
}