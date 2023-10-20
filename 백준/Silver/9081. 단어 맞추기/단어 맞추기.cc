#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

// ABCDEFGHIJKLMNOPQRSTUVWXYZ

/*
 HELLO
 HELOL
 
 DRINK
 DRKIN
 
 SHUTTLE
 SLEHTTU
 
 DCBA
 DCBA
 
 ZOO
 
 */

int main(){
    fast;
    
    int N; cin>>N;
    
    
    for(int i=0; i<N; ++i){
        string input; cin>>input;
        vector<int> arr;
        
        int legnth = input.size();
        for(int i=0; i<legnth; ++i)
            arr.push_back(input[i]-'A');
        
        bool flag = false;
        int index = 0;
        int minValue = INT_MAX;
        int minIndex = 0;
        
        for(int i=legnth-1; i>0; --i){
            char next = arr[i-1];
            if(arr[i] > next){
                index = i-1;
                flag = true;
                break;
            }
        }
        
        for(int i=index+1; i<legnth; ++i){
            if(minValue > arr[i]){
                if(arr[i] > arr[index]){
                    minValue = arr[i];
                    minIndex = i;
                }
            }
            
        }
        
        if(flag){
            vector<int> rest;
            for(int i=0;i<index; ++i)
                cout<<input[i];
            cout<<input[minIndex];
            
            for(int i=index; i<legnth; ++i){
                if(i == minIndex) continue;
                rest.push_back(arr[i]);
            }
            sort(rest.begin(), rest.end());
            for(int i=0; i<rest.size(); ++i){
                char a = rest[i] + 65;
                cout<<a;
            }
            cout<<"\n";
            
        }
        else
            cout<<input<<"\n";
        
    }
    
    
}
