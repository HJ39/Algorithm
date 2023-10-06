#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n,m,r;
int item[101];
int dist[101];
vector<tuple<int,int>> input[101];

int dijkstra(int start){
    priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> q;
    fill_n(dist, 101, INT_MAX);
    dist[start] = 0;
    q.push({0,start});
    
    while(!q.empty()){
        auto[dis, node] = q.top();
        q.pop();
        
        for(auto &i: input[node]){
            auto[nnode, ndis] = i;
            ndis += dis;
            
            if(ndis < dist[nnode]){
                dist[nnode] = ndis;
                q.push({ndis, nnode});
            }
        }
    }
    
    int sum = 0;
    for(int i=1; i<=n; ++i)
        if(dist[i] <= m)
            sum += item[i];
        
    return sum;
}

int main(){
    fast;
    
    cin>>n>>m>>r;
    
    for(int i=1; i<=n; ++i){
        int a; cin>>a;
        item[i] = a;
    }
        
    
    for(int i=0; i<r; ++i){
        int a,b,c;
        cin>>a>>b>>c;
        input[a].push_back({b,c});
        input[b].push_back({a,c});
    }
    
    int result = 0;
    
    for(int i=1; i<=n; ++i)
        result = max(result,dijkstra(i));
    cout<<result<<"\n";
}
