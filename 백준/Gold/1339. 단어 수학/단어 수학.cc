#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int alpha[27];

int main(){
    fast;
    
    int N; cin>>N;
    for(int i=0; i<N; ++i) {
        string a; cin>>a;
        
        int pow = 1;
        for(int j= a.size()-1; j>=0; --j) {
            alpha[a[j] - 'A'] += pow;
            pow *= 10;
        }
    }
    
    sort(alpha, alpha+26, greater<int>());
    
    int maxNum = 9;
    int res = 0;
    for(int i=0; i<27; ++i) {
        if(alpha[i] == 0)
            break;
        res += alpha[i] * maxNum--;
        maxNum = maxNum<0 ? 0 : maxNum;
    }
    cout<<res<<"\n";
}
