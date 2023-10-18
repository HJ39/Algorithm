#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
map<string, int> input;
string output[1001];

int main(){
    fast;
    
    cin>>N;
    
    for(int i=0; i<N; ++i){
        string a; cin>>a;
        input[a] = i;
    }
    for(int i=0; i<N; ++i)
        cin>>output[i];
    
    int cnt = 0;
    for(int i=0; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            if(input[output[i]] > input[output[j]]){
                cnt++;
                break;
            }
        }
    }

    cout<<cnt<<"\n";
}
