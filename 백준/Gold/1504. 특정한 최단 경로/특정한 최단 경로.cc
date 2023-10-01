#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N,E;
int A,B;
vector<pair<int, int>> input[801];
int dist[801];

int dijkstra(int st, int end) {
    // 이동거리, 현재 정점 위치
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    fill_n(dist, 801, INT_MAX);
    dist[st] = 0;
    q.push({0,st});
    
    while(!q.empty()){
        auto [move, node] = q.top();
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
    
    return dist[end];
}

int main(){
    fast;
        
    cin>>N>>E;
    
    for(int i=0; i<E; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        input[a].push_back({b,c});
        input[b].push_back({a,c});
    }
    
    cin>>A>>B;
    int res1, res2;
    
    int d1 = dijkstra(1,A);
    int d2 = dijkstra(A,B);
    int d3 = dijkstra(B,N);
    if(d1 == INT_MAX or d2 == INT_MAX or d3 == INT_MAX)
        res1 = INT_MAX;
    else
        res1 = d1 + d2 + d3;
    
    int dd1 = dijkstra(1,B);
    int dd2 = dijkstra(B,A);
    int dd3 = dijkstra(A,N);
    if(dd1 == INT_MAX or dd2 == INT_MAX or dd3 == INT_MAX)
        res2 = INT_MAX;
    else
        res2 = dd1 + dd2 + dd3;
    
    int result = (res1 > res2) ? res2 : res1;
    
    if (res1 == INT_MAX and res2 == INT_MAX)
        cout<<"-1\n";
    else
        cout<<result<<"\n";
    
}