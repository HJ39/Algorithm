#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int input[100'001];

int main(){
    fast;
    
    cin >> N;
    
    for(int i=1; i<=N; ++i){
        cin>>input[i];
    }

    sort(input+1, input+1+N, greater<int>());
    
    int result = 0;
    for(int i=1; i<=N; ++i){
        result = max(result, input[i]*i);
    }
    
    cout<<result<<"\n";
}