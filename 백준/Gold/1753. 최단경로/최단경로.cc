#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
#define MAXNODE 20'001
using namespace std;

int v,e;
int dist[MAXNODE];
vector<tuple<int,int>> input[MAXNODE];

void dijkstra(int start){
    priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> q;
    fill_n(dist, MAXNODE, INT_MAX);
    dist[start] = 0;
    q.push({0,start});
    
    while(!q.empty()){
        auto[move, node] = q.top();
        q.pop();
        
        if(move > dist[node])
            continue;
        
        for(auto &i: input[node]){
            auto [nnode, nmove] = i;
            nmove += move;
            
            if(nmove < dist[nnode]){
                dist[nnode] = nmove;
                q.push({nmove, nnode});
            }
        }
        
    }
    
    
}

int main(){
    fast;
    
    cin>>v>>e;
    
    int start;
    cin>>start;
    
    for(int i=0 ;i<e;++i){
        int a, b, c;
        cin>>a>>b>>c;
        input[a].push_back({b,c});
    }
    
    dijkstra(start);
    
    for(int i=1; i<=v; ++i){
        if(dist[i] == INT_MAX)
            cout<<"INF\n";
        else{
            cout<<dist[i]<<"\n";
        }
    }
    
}
