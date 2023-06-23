#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main(){
    fast;
    
    string S;
    string T;
    cin>>S>>T;
    
    while (1) {
        
        if(S.length() == T.length()){
            if(S==T) cout<<"1\n";
            else cout<<"0\n";
            break;
        }
        
        if(T[T.length()-1] == 'A'){
            T.pop_back();
        }
        else{
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }
}