#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N,M;
priority_queue<int, vector<int>, greater<int>> q;
priority_queue<int, vector<int>> qPlus;
vector<int> arr;
int main(){
    fast;
    
    cin>>N>>M;
    
    for(int i=0; i<N; ++i) {
        int a; cin>>a;
        if(a > 0)
            qPlus.push(a);
        else
            q.push(a);
    }
    
    while (!q.empty()) {
        int item = q.top(); q.pop();
        int book = M-1;

        while (book-- and !q.empty()) {
            q.pop();
        }
        arr.push_back(item);
    }
    
    while (!qPlus.empty()) {
        int item = qPlus.top(); qPlus.pop();
        int book = M-1;
        
        while (book-- and !qPlus.empty()) {
            qPlus.pop();
        }
        arr.push_back(item);
    }
    
    int maxNum = 0;
    int res = 0;
    for(int i=0; i<arr.size(); ++i) {
        res += (abs(arr[i]) * 2);
        maxNum = max(maxNum, abs(arr[i]));
    }
    cout<< res - maxNum<< "\n";
}
