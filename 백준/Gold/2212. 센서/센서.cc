#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long ll;
vector<int> dis, input;

int main(){
    fast;
    
    int N; cin>>N;
    int K; cin>>K;
    
    for(int i=0; i<N; ++i) {
        int a; cin>>a;
        input.push_back(a);
    }
    
    sort(input.begin(), input.end());
    
    for(int i=1; i<N; ++i)
        dis.push_back(abs(input[i] - input[i-1]));
    
    sort(dis.begin(), dis.end(), greater<int>());

    ll res = 0;
    for(int i=dis.size()-1; i>=K-1; --i) {
        res += dis[i];
    }
    
    cout<<res<<"\n";
}
