#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N,M;
vector<pair<int, int>> adj[50'001]; // 도시, 여물양
int dist[50'001];
priority_queue<pair<int,int>, vector<pair<int, int>>,greater<pair<int,int>>> q; // 여물양, 도시

void dijkstra(){
    
    while(!q.empty()){
        auto [cost, city] = q.top();
        q.pop();
        
        if(dist[city] < cost)
            continue;
        
        for(auto &i: adj[city]){
            auto [nCity, nCost] = i;
            nCost += cost;
            
            if(nCost < dist[nCity]){
                dist[nCity] = nCost;
                q.push({nCost,nCity});
            }
        }
        
    }
    
}

int main(){
    fast;
    
    cin>>N>>M;
    
    adj[0].push_back({0,0});
    for(int i=0; i<M; ++i){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    
    fill_n(dist, 50'001, INT_MAX);
    dist[1] = 0;
    q.push({0,1});
    dijkstra();
    
    cout<<dist[N]<<"\n";
    
    
}
