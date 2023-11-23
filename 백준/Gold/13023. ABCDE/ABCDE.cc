#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N,M;
vector<int> input[2001];
bool check[2001];
bool ans = false;
void back(int cnt, int s) {
    if (cnt == 4) {
        ans = true;
        return;
    }
    
    for(int i=0; i<input[s].size(); ++i) {
        if (!check[input[s][i]]) {
            check[input[s][i]] = true;
            back(cnt+1, input[s][i]);
            check[input[s][i]] = false;
        }
    }
}

int main() {
    fast;
    
    cin>>N>>M;
    
    for(int i=0; i<M; ++i) {
        int a,b;
        cin>>a>>b;
        input[a].push_back(b);
        input[b].push_back(a);
    }
    
    for(int i=0; i<M; ++i) {
        check[i] = true;
        back(0, i);
        check[i] = false;
        if(ans) break;
    }
    cout<<ans<<"\n";
}
