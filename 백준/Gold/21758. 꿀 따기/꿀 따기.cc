#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int sum[100'001], input[100'001];
int res = 0;

void firstCase() {  // 꿀통 왼쪽
    for (int i=2; i<N; ++i) {
        int cnt = sum[N-1] + sum[i-1] - input[i];
        res = max(res, cnt);
    }
}

void secondCase() {  // 꿀통 오른쪽
    for (int i=2; i<N; ++i) {
        int cnt = sum[N] - input[i] - sum[1] + sum[N] - sum[i];
        res = max(res, cnt);
    }
}

void thirdCase() { // 꿀통 가운데
    for(int i=2; i<N; ++i) {
        int cnt = sum[i] - sum[1] + sum[N-1] - sum[i-1];
        res = max(res, cnt);
    }
}

int main(){
    fast;
    
    cin>>N;
    
    for(int i=1; i<=N; ++i) {
        int a; cin>>a;
        input[i] = a;
        sum[i] = sum[i-1] + a;
    }
    
    firstCase();
    secondCase();
    thirdCase();
    
    cout<< res<<"\n";
}

