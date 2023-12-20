#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<pair<int, int>> input;

int main(){
    fast;
    
    int N; cin>>N;
    
    int finalTime = 0;
    for(int i=0; i<N; ++i) {
        int time, end; cin>>time>>end;
        input.push_back({end, time});
        finalTime = max(finalTime, end);
    }
    
    sort(input.begin(), input.end(), greater<pair<int,int>>());
    
    for(int i=0; i<N; ++i) {
        auto [end, time] = input[i];
        
        if(finalTime <= end) {
            finalTime -= time;
        } else {
            finalTime = end;
            finalTime -= time;
        }
    }
    
    if (finalTime >= 0)
        cout<<finalTime<<"\n";
    else
        cout<<"-1\n";
}