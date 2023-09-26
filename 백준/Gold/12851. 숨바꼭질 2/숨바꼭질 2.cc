#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
#define MAX 1'000'001

using namespace std;

int N, K;
queue<pair<int, int>> q;
bool check[MAX];
int minMove = INT_MAX;
int cnt = 0;


void find(){
       
    while (!q.empty()) {
        auto [move, now] = q.front();
        q.pop();
        
        check[now] = true;
        
        if(cnt and now == K and minMove == move){
            cnt++;
        }
        
        if(!cnt and now == K){
            cnt++;
            minMove = move;
        }
        
        if(now*2 <= MAX and now*2 >= 0 and !check[now*2])
            q.push({move+1, now*2});
        
        if(now+1 <= MAX and now+1 >= 0 and !check[now+1])
            q.push({move+1, now+1});
        
        if(now-1 <= MAX and now-1 >= 0 and !check[now-1])
            q.push({move+1, now-1});
        
    }
}

int main(){
    fast;
    
    cin>>N>>K;
    
    q.push({0,N});
    check[N] = true;
    find();
    cout<<minMove<<"\n";
    cout<<cnt<<"\n";
}
