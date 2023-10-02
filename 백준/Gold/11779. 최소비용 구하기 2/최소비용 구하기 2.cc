#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
#define MAX 100'001
using namespace std;

int n,m;
int dist[MAX];
int back[MAX];
vector<int> route;
vector<pair<int,int>> input[MAX];

void dijkstra(int start, int end){
    priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> q;
    fill_n(dist, MAX, INT_MAX);
    q.push({0,start});
    dist[start] = 0;
    
    while(!q.empty()){
        auto [cost, city] = q.top();
        q.pop();
        
        if(cost > dist[city])
            continue;
        
        for(auto &i: input[city]){
            auto[ncity, ncost] = i;
            ncost += cost;
            
            if(ncost < dist[ncity]){
                dist[ncity] = ncost;
                back[ncity] = city;
                q.push({ncost, ncity});
            }
        }
    }
    
    cout<<dist[end]<<"\n";
    while(end){
        route.push_back(end);
        end = back[end];
    }
    cout<<route.size()<<"\n";
    for(int i=route.size()-1; i>=0; i--)
        cout<<route[i]<<" ";
    cout<<"\n";
}

int main(){
    fast;
    
    cin>>n>>m;
    
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        input[a].push_back({b,c});
    }
    
    int A,B;
    cin>>A>>B;
    
    dijkstra(A,B);
    
}
