#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int dp[61][61][61];
int input[4];

int sol(int f, int s, int t) {
    
    if(f<0) return sol(0, s, t);
    if(s<0) return sol(f, 0, t);
    if(t<0) return sol(f, s, 0);
    
    if(f == 0 and s == 0 and t == 0) return 0;
    
    int &num = dp[f][s][t];
    if(num != -1)
        return num;
    
    num = 987654321;
    num = min(num, sol(f-9, s-3, t-1) + 1);
    num = min(num, sol(f-9, s-1, t-3) + 1);
    num = min(num, sol(f-3, s-9, t-1) + 1);
    num = min(num, sol(f-3, s-1, t-9) + 1);
    num = min(num, sol(f-1, s-3, t-9) + 1);
    num = min(num, sol(f-1, s-9, t-3) + 1);
    
    return num;
}

int main() {
    fast;
    
    int N; cin>>N;
    for(int i=1; i<=N; ++i)
        cin>>input[i];
    
    memset(dp, -1, sizeof(dp));
    cout<<sol(input[1], input[2], input[3])<<"\n";
    
}
