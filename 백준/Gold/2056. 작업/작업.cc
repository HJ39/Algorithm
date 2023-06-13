#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
#define MAXNUM 10'001

using namespace std;

int N2056;
vector<int> input2056[MAXNUM];
int workTime2056[MAXNUM];
int degree2056[MAXNUM];
queue<int> q2056;
int sumWork[MAXNUM];
int maxTime = 0;

void topologicalSort2056(){
    
    while(!q2056.empty()){
        int x = q2056.front();
        q2056.pop();
        
        for(int i=0;i<input2056[x].size(); ++i){
            int y = input2056[x][i];
            degree2056[y]--;
            sumWork[y] = max(sumWork[y], sumWork[x] + workTime2056[y]);

            if(degree2056[y] == 0){
                q2056.push(y);
            }
        }
    }
}

int main(){
    fast;
    
    cin>>N2056;

    for(int i=1;i<=N2056;++i){
        int a,b;
        cin>>a>>b;
        
        workTime2056[i] = a;
        for(int j=0;j<b;++j){
            int c;
            cin>>c;
            input2056[c].push_back(i);
            degree2056[i]++;
        }
        
    }
    for(int i=1;i<=N2056;++i){
        if(degree2056[i] == 0)
            q2056.push(i);
        sumWork[i] = workTime2056[i];
    }

    topologicalSort2056();
    
    for(int i=1;i<=N2056;++i){
        maxTime = max(maxTime, sumWork[i]);
    }
    
    cout<<maxTime<<"\n";
    
}