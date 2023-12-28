#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
bool check[10001];

int main(){
    fast;
        
    int N; cin>>N;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>> q;
    
    for(int i=0; i<N; ++i) {
        int a,b; cin>>a>>b;
        q.push({a,b});
    }
    
    int res = 0;
    while (!q.empty()) {
        auto[p, d] = q.top();
        q.pop();

        while(d) {
            if(!check[d]) {
                res += p;
                check[d] = true;
                break;
            }
            else
                d--;
        }
    }
   
    cout<<res<<"\n";
}
