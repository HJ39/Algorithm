#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

queue<int> q;
int n,m,k,x;
vector<int> arr[300'001];
int d[300'001];

void dijkstra(){
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int i=0; i<arr[cur].size(); ++i){
            int next = arr[cur][i];
            
            if(d[next] > d[cur] + 1){
                d[next] = d[cur] + 1;
                q.push(next);
            }
        }
        
    }
    
}

int main(){
    fast;
    
    cin>>n>>m>>k>>x;

    fill_n(d, n+1, INT_MAX);
    
    for(int i=0; i<m; ++i){
        int s,e;
        cin>>s>>e;
        arr[s].push_back(e);
    }
    
    q.push(x);
    d[x] = 0;
    dijkstra();
    
    bool check = false;
    for(int i=1; i<=n; ++i){
        if(d[i] == k){
            check = true;
            cout<<i<<"\n";
        }
    }
    
    if(!check)
        cout<<"-1\n";
        
}
