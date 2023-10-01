#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
#define MAX 10'001
using namespace std;

int n,d,c;
int dist[MAX];

void dijkstra(int start, vector<pair<int,int>> input[MAX]){
    priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> q;
    q.push({0,start});
    dist[start] = 0;
    
    while(!q.empty()){
        auto [time, now] = q.top();
        q.pop();
        
        if(time > dist[now])
            continue;
        
        for(auto &i: input[now]){
            auto[next, ntime] = i;
            ntime += time;
            
            if(ntime < dist[next]){
                dist[next] = ntime;
                q.push({ntime, next});
            }
        }
    }
    
}

int main(){
    fast;
    int testcase;
    cin>>testcase;
    
    while(testcase--){
        vector<pair<int,int>> input[MAX];
        cin>>n>>d>>c;
        
        for(int i=0; i<d; ++i){
            int a,b,s;
            cin>>a>>b>>s;
            input[b].push_back({a,s});
        }
        fill_n(dist, MAX, INT_MAX);
        
        dijkstra(c, input);
        
        int hackCnt = 0;
        int hackTime = 0;
        for(int i=1; i<=n; ++i){
            if(dist[i] != INT_MAX){
                hackCnt++;
                hackTime = max(dist[i],hackTime);
            }
        }
        cout<<hackCnt<<" "<<hackTime<<"\n";
    }
}