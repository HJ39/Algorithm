#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

int main(){
    fast;
    
    cin>>N;
    
    string pattern;
    
    cin>>pattern;
    
    int starPoint = pattern.find('*');
    string first, last;
    for(int i=0; i<starPoint; ++i)
        first.push_back(pattern[i]);
    for(int i=starPoint+1; i<pattern.length(); ++i)
        last.push_back(pattern[i]);
  
    
    for(int i=0; i<N; ++i){
        string input, comp1, comp2;
        cin>>input;
        
        for(int i=0; i<first.length(); ++i)
            comp1.push_back(input[i]);
        for(int i=input.length()-last.length(); i<input.length(); ++i)
            if( i >= first.length())
                comp2.push_back(input[i]);
        
        if(first == comp1 and last == comp2)
            cout<<"DA\n";
        else
            cout<<"NE\n";
    }
    
}
