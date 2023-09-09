#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int A[51],B[51];

int main(){
    fast;
    cin>>N;
    
    for(int i=1;i<=N;++i)
        cin>>A[i];
    
    for(int i=1;i<=N;++i)
        cin>>B[i];
    
    sort(A+1, A+N+1);
    sort(B+1, B+N+1,greater<>());
    
    int sum = 0;
    for(int i=1; i<=N; ++i) {
        sum += A[i] * B[i];
    }
    
    cout<<sum<<"\n";
}