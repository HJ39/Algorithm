#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<int> input;
priority_queue<int, vector<int>, greater<int>> q;
int main(){
    fast;
    
    int N; cin>>N;
    
    for(int i=0; i<N; ++i) {
        int a; cin>>a;
        q.push(a);
    }
    
    int res = 0;
    while (q.size() != 1) {
        int f = q.top(); q.pop();
        int s = q.top(); q.pop();
        
        res += f+s;
        q.push(f+s);
    }
    cout<<res<<"\n";
}