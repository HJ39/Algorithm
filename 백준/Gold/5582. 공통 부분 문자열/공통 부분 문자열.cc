#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int input[4001][4001];
string a,b;

int main(){
    fast;
    
    
    cin>>a>>b;
    
    int aLength = a.size();
    int bLength = b.size();
    
    int maxNum = 0;
    for(int i=0; i<=aLength; ++i){
        for(int j=0; j<=bLength; ++j){
            if(i == 0 or j==0)
                input[i][j] = 0;
            
            else if(a[i-1] == b[j-1]){
                input[i][j] = input[i-1][j-1] + 1;
            }
            
            if(input[i][j] > maxNum){
                maxNum = input[i][j];
            }
        }
    }
    cout<<maxNum<<"\n";
}
