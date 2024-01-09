#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INF 987654321

using namespace std;

int dpMax[4];
int dpMin[4];
int input[4];
int main() {
    fast;
    
    int N; cin>>N;
    
    for(int i=1; i<=N; ++i) {
        cin>>input[1]>>input[2]>>input[3];
        
        int a = dpMax[1];
        int b = dpMax[2];
        int c = dpMax[3];
        
        dpMax[1] = max(a,b) + input[1];
        dpMax[2] = max(max(a,b),c) + input[2];
        dpMax[3] = max(b,c) + input[3];
        
        a = dpMin[1];
        b = dpMin[2];
        c = dpMin[3];
        
        dpMin[1] = min(a,b) + input[1];
        dpMin[2] = min(min(a,b),c) + input[2];
        dpMin[3] = min(b,c) + input[3];
    }
    
    cout<< max(max(dpMax[1],dpMax[2]),dpMax[3])<<" "<< min(min(dpMin[1],dpMin[2]),dpMin[3])<<"\n";
}
