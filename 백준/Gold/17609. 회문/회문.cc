#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

string a;

int palindrome(int start, int end, bool check) {
    
    while(start < end){
        if(a[start] != a[end]){
            if(check)
                if(palindrome(start+1, end, false) == 0 or palindrome(start, end-1, false) == 0)
                    return 1;
            return 2;
        }
        start++;
        end--;
    }
    return 0;
}

int main(){
    fast;
    
    int N; cin>>N;
    
    while(N--){
        cin>>a;
        cout<<palindrome(0, a.length()-1, true)<<"\n";
    }
}