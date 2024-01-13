#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int* search(vector<int> &timeList, vector<int> &degree, vector<int> nodes[10'001], int endTime[], queue<int> &q) {
    
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        
        for(int i=0; i<nodes[top].size(); ++i) {
            int node = nodes[top][i];
            degree[node]--;
            endTime[node] = max(endTime[node], endTime[top] + timeList[node]);
            if(degree[node] == 0)
                q.push(node);
        }
    }
    
    return endTime;
}

int main() {
    fast;
    
    int N; cin>>N;
    vector<int> nodes[10001];
    vector<int> timeList(N+1);
    vector<int> degree(N+1);
    int endTime[N+1];
    queue<int> q;
    fill_n(endTime, degree.size(), 0);
    
    for(int i=1; i<=N; ++i) {
        int cnt;
        cin>>timeList[i]>>cnt;
        
        for(int j=1; j<=cnt; ++j) {
            int node; cin>>node;
            degree[i]++;
            nodes[node].push_back(i);
        }
    }
    
    for(int i=1; i<=N; ++i) {
        if(degree[i] == 0) {
            q.push(i);
            endTime[i] = timeList[i];
        }
    }
    
    int* list = search(timeList, degree, nodes, endTime, q);
    
    int res = 0;
    for(int i=1; i<=N; ++i)
        res = max(res, list[i]);
    cout<<res<<"\n";
        
}
