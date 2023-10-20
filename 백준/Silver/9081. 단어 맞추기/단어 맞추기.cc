#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fast;
    int N;
    cin>>N;
    
    for(int i=0; i<N; ++i){
        string input; cin>>input;
        
        bool check = next_permutation(input.begin(), input.end());
        if(!check)
            prev_permutation(input.begin(), input.end());
        cout<<input<<"\n";
    }
    
}
