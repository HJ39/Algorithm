#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
bool check[1001];

int main(){
    fast;
        
    int N; cin>>N;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>> q;
    
    for(int i=0; i<N; ++i) {
        int a,b; cin>>a>>b;
        q.push({b,a});
    }
    
    int res = 0;
    while (!q.empty()) {
        auto[w, d] = q.top();
        q.pop();
       
        while(d) {
            if(!check[d]) {
                res += w;
                check[d] = true;
                break;
            }
            else
                d--;
        }
    }

    cout<<res<<"\n";
}
