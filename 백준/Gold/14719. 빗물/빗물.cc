#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<int> input14719;

int main(){
    fast;
    
    int N,M;
    cin>>N>>M;
    
    for(int i=0;i<M;++i){
        int a;
        cin>>a;
        input14719.push_back(a);
    }
    
    int leftWall = 0;
    int res = 0;
    for(int i=0; i<M; ++i){
        leftWall = max(leftWall,input14719[i]);
        int rightWall = 0;
        for(int j=i; j<M; ++j){
            rightWall = max(rightWall, input14719[j]);
        }
        
        int maxHeight = min(leftWall,rightWall);
        if(leftWall != input14719[i] and rightWall != input14719[i]){
            res += maxHeight - input14719[i];
        }
    }
    
    cout<<res<<"\n";
    
}

