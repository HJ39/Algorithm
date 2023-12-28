#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<char> arr;

int main(){
    fast;
    int N, K; cin >> N >> K;
    
    string input; cin>>input;
    if(N == K)
        cout<<"0\n";
    else {
        for(int i=0; i<input.length(); ++i) {
            while (K and !arr.empty() and arr.back() < input[i]) {
                arr.pop_back();
                K--;
            }
            arr.push_back(input[i]);
        }
        
        for(int i=0; i<arr.size()-K; ++i)
            cout<<arr[i];
        cout<<"\n";
    }
}