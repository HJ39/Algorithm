#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<int> input;

int main() {
    fast;
    
    int N; cin>>N;
    
    int res = 0;
    for(int i=0; i<N; ++i) {
        int a; cin>>a;
        input.push_back(a);
    }

    while (true) {
        int zero = 0;
        for(auto &i: input) {
            if(i%2 != 0) {
                i--;
                res++;
            }
            if(i==0)
                zero++;
        }
        
        if(zero ==  N)
            break;
        
        res++;
        for(auto &i: input) {
            i /= 2;
        }
    }
    
    cout<<res<<"\n";
}