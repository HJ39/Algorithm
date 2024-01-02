#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long ll;
using namespace std;

ll dp[51][51][51];
int main(){
    fast;
    
    for(int i=0; i<=21; ++i) {
        for(int j=0; j<=21; ++j) {
            for(int k=0; k<=21; ++k) {
                if (i<=0 or j<=0 or k<=0)
                    dp[i][j][k] = 1;
                else if(i<j and j<k)
                    dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
                else
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
                
            }
        }
    }
                
    
    while (true) {
        int a,b,c; cin>>a>>b>>c;
        if(a == -1 and b == -1 and c == -1) break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = ";
        if(a<=0 or b<=0 or c<=0)
            cout<<"1\n";
        else if(a>20 or b>20 or c>20)
            cout<<dp[20][20][20]<<"\n";
        else
            cout<<dp[a][b][c]<<"\n";
        
    }
}
