#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;

vector<pair<int, int>> adj[1001];   // 도착 도시, 비용
int dist[100'001];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> q;

void dijkstra(){
    
    while(!q.empty()){
        auto [cost, city] = q.top();
        q.pop();
        
        if(cost > dist[city])
            continue;
        
        for(auto &i: adj[city]){
            auto [ncity, ncost] = i;
            ncost += cost;  // 다음 도시까지의 비용
            
            if(dist[ncity] > ncost){
                dist[ncity] = ncost;
                q.push({ncost,ncity});
            }
            
        }
        
    }
}

int main(){
    fast;
    
    cin>>N>>M;
    
    adj[0].push_back(make_pair(0, 0));
    for(int i=0; i<M; ++i){
        int s,e,l;
        cin>>s>>e>>l;
        adj[s].push_back({e,l});
    }
    
    int s, e;
    cin>> s>>e;
    
    fill_n(dist,100'001,INT_MAX);
    dist[s] = 0;
    q.push({0,s});
    
    
    dijkstra();
    cout<<dist[e]<<"\n";
        
}