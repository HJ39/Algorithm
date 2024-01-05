#include <bits/stdc++.h>
#define WEIGHT 0
#define VALUE 1

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k;
    cin>>n>>k;

    int arr[n+1][2];
    int dp[n+1][k+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            dp[i][j] = 0;
    

    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        arr[i][WEIGHT] = a;
        arr[i][VALUE] = b;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j - arr[i][WEIGHT] >= 0){
                dp[i][j] = max(dp[i-1][j-arr[i][WEIGHT]] + arr[i][VALUE], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout<<dp[n][k]<<endl;
    
}

