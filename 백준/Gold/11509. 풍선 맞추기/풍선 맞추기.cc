#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;
int arr[1'000'001];

int main(){
    fast;
    
    int N; cin>>N;
    
    int res = 0;
    for(int i=0; i<N; ++i) {
        int a; cin>>a;
        
        if(arr[a+1]) {
            arr[a+1]--;
            arr[a]++;
        } else {
            res++;
            arr[a]++;
        }
    }
    cout<<res<<"\n";
}
