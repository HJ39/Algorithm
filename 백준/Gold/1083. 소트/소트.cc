#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N1083, S1083;
vector<int> input1083(51,0);

int main(){
    fast;
    cin>>N1083;
    
    for(int i=1; i<=N1083;++i)
        cin>>input1083[i];
    
    cin>>S1083;

    
    
    
    for(int i=1; i<N1083; ++i){
        int maxNum = input1083[i];
        int maxIndex = i;
        
        for(int j=i+1; j<=N1083; ++j){
            if((S1083 - (j - i) >= 0) and maxNum < input1083[j]){
                maxNum = input1083[j];
                maxIndex = j;
            }
        }
        
        for(int j=maxIndex; j>i; j--){
            swap(input1083[j], input1083[j-1]);
        }
        S1083 -= maxIndex - i;
        if(S1083 <= 0)
            break;
    }
    
    for(int i=1; i<=N1083;++i)
        cout<<input1083[i]<<" ";
    
}