#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<int> input;
bool check[2001];

int main(){
    fast;
    
    int N; cin>>N;
    
    for(int i=0; i<N; ++i) {
        int a; cin>>a;
        input.push_back(a);
    }
        
    sort(input.begin(), input.end());
    
    int res = 0;
    
    for(int i=1; i<N; ++i) {
        if(input[i] > 0) break;
        if(check[i] or check[i-1]) continue;
        res += (input[i-1] * input[i]);
        check[i] = true;
        check[i-1] = true;
    }
  
    for(int i= N-2; i>=0; --i) {
        if(input[i] <= 0) break;
        if(check[i] or check[i+1]) continue;
        if(input[i] == 0 or input[i+1] == 0) continue;
        if(input[i] == 1 or input[i+1] == 1) continue;
        res += (input[i] * input[i+1]);
        check[i] = true;
        check[i+1] = true;
    }
    
    for(int i=0; i<N; ++i) {
        if(!check[i]) {
            res += input[i];
        }
    }
    cout<<res<<"\n";
}