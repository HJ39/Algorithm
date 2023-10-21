#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main(){
    fast;
    
    string a,b; cin>>a>>b;
    
    int lcs[1001][1001];
    int aLength = a.size();
    int bLength = b.size();
    
    for(int i=0; i<=aLength; ++i){
        for(int j=0; j<=bLength; ++j){
            if(i == 0 or j == 0)
                lcs[i][j] = 0;
            else if(a[i-1] == b[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    
    cout<<lcs[aLength][bLength]<<"\n";    
}
