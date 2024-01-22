#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

bool compare(pair<int, int> first, pair<int, int> second) {
    return first.second < second.second;
}

int main() {
    fast;
    
    int N; cin>>N;
    vector<pair<int, int>> input;
    vector<int> list;
    for(int i=0; i<N; ++i) {
        int a; cin>>a;
        input.push_back({i,a});
        list.push_back(a);
    }
    
    int M; cin>>M;
    
    sort(input.begin(), input.end(), compare);
    
    string res = "";
    if(N==1){
        cout<<"0\n";
        return 0;
    }
    
    if(input[0].first == 0) {
        int m = M - input[1].second;
        if(m<0) {
            cout<<"0\n";
            return 0;
        }
        res += to_string(input[1].first);
        
        int cnt = m / input[0].second;
        
        for(int i=0; i<cnt; ++i)
            res += to_string(input[0].first);
        
        M = m - cnt * input[0].second;
    } else {
        int cnt = M/input[0].second;
        for(int i=0; i<cnt; ++i)
            res += to_string(input[0].first);
        M -= cnt*input[0].second;
    }
    
    for(int i=0; i<res.size(); ++i) {
        bool check = false;
        int now = list[res[i] - '0'];
        for(int j=N-1; j>=0; --j) {
            if(M-(list[j]-now) >= 0) {
                M -= list[j]-now;
                check = true;
                res[i] = j + '0';
                break;
            }
        }
        if(!check)
            break;
    }
    cout<<res<<"\n";
}