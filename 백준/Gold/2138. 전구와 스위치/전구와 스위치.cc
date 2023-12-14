#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
using namespace std;

int N, cnt = 0;
int res = 987654321;
string s, e, tmp;

void change(int index) {
    if (index > 0) {
        if (tmp[index-1] == '0') tmp[index-1] = '1';
        else tmp[index-1] = '0';
    }
    
    if (tmp[index] == '0') tmp[index] = '1';
    else tmp[index] = '0';
    
    if (index < N-1) {
        if (tmp[index+1] == '0') tmp[index+1] = '1';
        else tmp[index+1] = '0';
    }
}

void sol(int num) {
    tmp = s;
    cnt = 0;
    
    if(num == 0) {
        if (tmp[0] == '0') tmp[0] = '1';
        else tmp[0] = '0';
        
        if (tmp[1] == '0') tmp[1] = '1';
        else tmp[1] = '0';
        
        cnt++;
    }
    
    for(int i=1; i<N; ++i) {
        if (tmp[i-1] != e[i-1]) {
            change(i);
            cnt++;
        }
    }
    if(tmp == e)
        res = min(res, cnt);
}

int main() {
    fast;
    
    cin>>N;
    cin>>s>>e;
    
    sol(0);
    sol(1);
    
    if (res != 987654321)
        cout<<res<<"\n";
    else
        cout<<"-1\n";
    
}