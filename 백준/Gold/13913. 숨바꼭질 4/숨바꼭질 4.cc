#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
#define MAX 1'000'001

using namespace std;

int N, K;
queue<pair<int, int>> q;
int backTracking[MAX];
bool check[MAX];
vector<int> path;

void find(){
    
    while(!q.empty()){
        auto[move, x] = q.front();
        check[x] = true;
        q.pop();
        
        if(x == K){
            int a = x;
            while(a != N){
                path.push_back(a);
                a = backTracking[a];
            }
            path.push_back(N);
            cout<<move<<"\n";
            return;
        }
        
        if(x+1 < MAX and x+1 >= 0 and !check[x+1]){
            backTracking[x+1] = x;
            check[x+1] = true;
            q.push({move+1, x+1});
        }
        
        if(x-1 < MAX and x-1 >= 0 and !check[x-1]){
            backTracking[x-1] = x;
            check[x-1] = true;
            q.push({move+1, x-1});
        }
        
        if(x*2 < MAX and x*2 > 0 and !check[x*2]){
            backTracking[x*2] = x;
            check[x*2] = true;
            q.push({move+1, x*2});
        }
    }
    
}

int main(){
    fast;
    
    cin>>N>>K;
    
    q.push({0,N});
    find();
    
    reverse(path.begin(), path.end());

    for(auto &i: path){
        cout<<i<<" ";
    }
}
