#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main(){
    fast;
    
    int N,M;
    cin>>N>>M;
    string input;
    cin>>input;
    
    string pattern = "I";
    for(int i=0; i<N; ++i)
        pattern.append("OI");

    
    int cnt = 0;
    for(int i=0 ;i<=input.size()-pattern.length(); ++i){
        if (pattern == input.substr(i,pattern.length())){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    
}
