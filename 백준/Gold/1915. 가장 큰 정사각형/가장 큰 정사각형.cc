#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int input[1001][1001];

int main() {
    fast;
    
    int N, M; cin>>N>>M;
    
    int res = 0;
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=M; ++j) {
            char a; cin>>a;
            int num = a - '0';
            if(num == 1) {
                input[i][j] = min(min(input[i-1][j], input[i][j-1]), input[i-1][j-1]) + 1;
                res = max(res, input[i][j]);
            }
        }
    }

    cout<<res*res<<"\n";
}