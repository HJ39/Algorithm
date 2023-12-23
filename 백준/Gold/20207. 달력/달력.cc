#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<pair<int,int>> input;
int check[1001];

int main(){
    fast;
    
    int N; cin>>N;
    
    int res = 0;
    int finalLast = 0;
    for(int i=0; i<N; ++i) {
        int s,e; cin>>s>>e;
        input.push_back({s,e});
        for(int j=s; j<=e; ++j) {
            check[j]++;
        }
        finalLast = max(finalLast, e);
    }
    
    int s = 1;
    int height = 0;
    for(int i=1; i<=finalLast+1; ++i) {
        if(check[i] != 0) {
            height = max(height, check[i]);
        } else {
            res += (i-s) * height;
            s = i+1;
            height = 0;
        }
    }
    
    cout<<res<<"\n";
}
