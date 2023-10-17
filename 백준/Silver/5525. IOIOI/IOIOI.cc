#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main(){
    fast;
    
    int N,M;
    cin>>N>>M;
    string input;
    cin>>input;
    
    int cnt = 0;
    
    for(int i=0; i<M; ++i){
        int k=0;
        if(input[i] == 'O') continue;
        
        while(input[i+1] == 'O' and input[i+2] == 'I'){
            k++;
            
            if(k == N){
                cnt++;
                k--;
            }
            i+=2;
        }
        
    }
    cout<<cnt<<"\n";
    
}
