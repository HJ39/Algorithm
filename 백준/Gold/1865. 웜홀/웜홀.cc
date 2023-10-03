#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
#define MAX 501
using namespace std;

int N,M,W;
long long dist[MAX];
vector<tuple<int,int,int>> edge;

bool bellMan(){
    dist[1] = 0;
    for(int i=1; i<N; ++i){
        for(int j=0; j<edge.size(); ++j){
            auto[start, end, value] = edge[j];
            
            if( dist[start] + value < dist[end]){
                dist[end] = dist[start] + value;
            }
        }
    }
    
    for(int j=0; j<edge.size(); ++j){
        auto[start, end, value] = edge[j];
        if(dist[start] + value < dist[end]){
            return false;
        }
    }
    return true;
}

int main(){
    fast;
    int testCase;
    cin>>testCase;
    
    while(testCase--){
        edge.clear();
        fill_n(dist, MAX, INT_MAX);
        
        cin>>N>>M>>W;
        
        for(int i=0; i<M; ++i){
            int a,b,c;
            cin>>a>>b>>c;
            edge.push_back({a,b,c});
            edge.push_back({b,a,c});
        }
        
        for(int i=0; i<W; ++i){
            int a,b,c;
            cin>>a>>b>>c;
            edge.push_back({a,b,-c});
        }
        
        if (bellMan()){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
        
    }
    
}
