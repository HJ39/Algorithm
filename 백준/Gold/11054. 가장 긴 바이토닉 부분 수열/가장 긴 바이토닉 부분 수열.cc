#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fast;
    
    int N; cin>>N;
    
    int input[N+1];
    for(int i=1; i<=N; ++i)
        cin>>input[i];
    
    int dpU[N+1];
    int dpD[N+1];
    for(int i=1; i<=N; ++i) {
        dpU[i] = 1;
        dpD[N-i+1] = 1;
        for(int j=1; j<i; ++j)
            if(input[i] > input[j])
                dpU[i] = max(dpU[i], dpU[j] + 1);
        
        for(int j=N; j>N-i+1; --j)
            if(input[N-i+1] > input[j])
                dpD[N-i+1] = max(dpD[N-i+1], dpD[j] + 1);
    }
    
    int res = 0;
    for(int i=1; i<=N; ++i)
        res = max(res, dpD[i] + dpU[i]);
    cout<<res-1<<"\n";
}
