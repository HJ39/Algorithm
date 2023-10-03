#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N,M;
long long dist[501];
vector<tuple<int,int,int>> edge;

void bellMan(){
    dist[1] = 0;
    for(int i=1; i<N; ++i){
        for (auto &i: edge){
            auto [start, end, value] = i;
            
            if(dist[start] != INT_MAX and dist[start] + value < dist[end]){
                dist[end] = dist[start] + value;
            }
            
        }
    }
    
}

int main(){
    fast;
    cin>>N>>M;
    
    for(int i=0; i<M; ++i){
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back({a,b,c});
    }
    
    fill_n(dist, 501, INT_MAX);
    
    bellMan();
    
    for (auto &i: edge){
        auto [start, end, value] = i;
        
        if(dist[start] != INT_MAX and dist[start] + value < dist[end]){
            cout<<"-1\n";
            return 0;
        }
    }
    
    for(int i=2; i<=N; ++i){
        if(dist[i] == INT_MAX){
            cout<<"-1\n";
        }
        else{
            cout<<dist[i]<<"\n";
        }
        
    }
    
}
