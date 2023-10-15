#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string arr1, arr2;
    cin >> arr1 >> arr2;
    
    int LCS[1001][1001] = {0};
    
    
    for(int i=0;i<=arr1.size();i++){
        for(int j=0;j<=arr2.size();j++){
            if( i==0 || j == 0){
                LCS[i][j] = 0;
            }
            else if( arr1[i-1] == arr2[j-1]){
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else{
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
    
    cout<<LCS[arr1.size()][arr2.size()]<<endl;
}
