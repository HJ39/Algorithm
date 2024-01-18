#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<int> input[51];
int removeNum;
int res;

int dfs(int node) {
    if(node == removeNum)
        return -1;
    
    if(input[node].size() == 0) {
        res++;
        return 0;
    }
    
    for(int i=0; i<input[node].size(); ++i)
        if(dfs(input[node][i]) == -1 and input[node].size() == 1)
            res++;
    
    return 0;
}

int main() {
    fast;
    
    int N; cin>>N;
    
    int start = 0;
    for(int i=0; i<N; ++i) {
        int a; cin>>a;
        if(a == -1) {
            start = i;
            continue;
        }
        input[a].push_back(i);
    }
    cin>>removeNum;
    
    dfs(start);
    cout<<res<<"\n";
}
