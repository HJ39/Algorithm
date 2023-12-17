#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main(){
    fast;
    int N; cin>>N;
    int sum = 0;
    int cnt = 0;
    for(int i=0; i<N; ++i) {
        int a; cin>>a;
        sum += a;
        cnt += a/2;
    }
    
    if(cnt >= sum/3 && sum % 3 == 0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
