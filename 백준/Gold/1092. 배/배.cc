#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long ll;

vector<int> crane, box;
int N,M, res = 0;

void greedy() {
    int t = 0;
    
    while (t != M) {
        res++;
        int craneIndex = 0;
        
        for(int i=0; i<M; ++i) {
            if(box[i] == 0)
                continue;
            if(craneIndex >= N)
                break;
            if(crane[craneIndex] >= box[i]) {
                t++;
                craneIndex++;
                box[i] = 0;
                if(t>M)
                    return;
            }
        }
    }
}

int main(){
    fast;
        
    
    cin>>N;
    for(int i=0; i<N; ++i) {
        int a; cin>>a;
        crane.push_back(a);
    }
    
    cin>>M;
    for(int i=0; i<M; ++i) {
        int a; cin>>a;
        box.push_back(a);
    }
    
    sort(crane.begin(), crane.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());
    
    if(crane[0] < box[0]){
        cout<<"-1\n";
        return 0;
    }
    
    greedy();
    
    cout<<res<<"\n";
}
