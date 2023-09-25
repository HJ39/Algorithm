#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
#define MAX 1'000'001

using namespace std;

int N, K;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
bool check[MAX];
    
void find2(){
    
    while(!q.empty()){
        auto[move, x] = q.top();
        check[x] = true;
        q.pop();
        
        if(x == K){
            cout<<move<<"\n";
            return;
        }
        
        if(x*2 < MAX and x*2 > 0 and !check[x*2]){
            check[x*2] = true;
            q.push({move, x*2});
        }
        
        if(x+1 < MAX and x+1 >= 0 and !check[x+1]){
            check[x+1] = true;
            q.push({move+1, x+1});
        }
        
        if(x-1 < MAX and x-1 >= 0 and !check[x-1]){
            check[x-1] = true;
            q.push({move+1, x-1});
        }
    }
}

int main(){
    fast;
    
    cin>>N>>K;
    
    q.push({0,N});
    find2();
}
