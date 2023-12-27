#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
typedef long long ll;

vector<pair<int, int>> input;

int main(){
    fast;
    
    int N; cin>>N;
    
    for(int i=0; i<N; ++i) {
        ll a,b; cin>>a>>b;
        input.push_back({a,b});
    }
    
    sort(input.begin(), input.end());

    priority_queue<int, vector<int>, greater<int>> q;
    
    q.push(input[0].second);
    int res = 1;
    for(int i=1; i<N; ++i) {
        auto [s, e] = input[i];

        while (!q.empty() && q.top() <= s) {
            q.pop();
        }
        q.push(e);
        
        res = max(res, (int)q.size());
    }
    cout<<res<<"\n";
}

