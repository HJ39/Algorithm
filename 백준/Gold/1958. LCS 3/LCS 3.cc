#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main(){
    fast;
    
    string a,b,c; cin>>a>>b>>c;
    
    int lcs[101][101][101];
    int aLength = a.size();
    int bLength = b.size();
    int cLength = c.size();
    
    for(int i=0; i<=aLength; ++i){
        for(int j=0; j<=bLength; ++j){
            for(int k=0; k<=cLength; ++k){
                if(i == 0 or j == 0 or k == 0)
                    lcs[i][j][k] = 0;
                else if(a[i-1] == b[j-1] and b[j-1] == c[k-1])
                    lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
                else{
                    lcs[i][j][k] = max(lcs[i-1][j][k], lcs[i][j-1][k]);
                    lcs[i][j][k] = max(lcs[i][j][k], lcs[i][j][k-1]);
                }
            }
        }
    }
    
    cout<<lcs[aLength][bLength][cLength]<<"\n";
    
}
