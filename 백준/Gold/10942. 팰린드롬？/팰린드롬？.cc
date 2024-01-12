#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int input[2001];
bool dp[2001][2001];

int main() {
    fast;
    int N; cin>>N;
    
    for(int i=1; i<=N; ++i) {
        cin>>input[i];
        dp[i][i] = true;
    }
    
    for(int i=1; i<=N; ++i)
        if(input[i] == input[i+1])
            dp[i][i+1] = true;
    
    for(int i=N; i>0; --i) {
        for(int j=N; j>=i; --j) {
            if(input[i] == input[j] and dp[i+1][j-1] == true)
                dp[i][j] = true;
        }
    }

    int M; cin>>M;
    while (M--) {
        int S,E; cin>>S>>E;
        dp[S][E] == 1 ? cout<<"1\n" : cout<<"0\n";
    }
    
}
