#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;
typedef long long ll;

int N;
vector<ll> result;

void back(int cnt, ll num) {
    if (cnt > 10)
        return;
    result.push_back(num);
    for(int i=0; i<10; ++i)
        if(num%10>i)
            back(cnt+1, num*10+i);
}

int main(){
    fast;
    cin>>N;
    
    for(int i=0; i<10; ++i)
        back(1,i);

    sort(result.begin(), result.end());

    if (result.size() <= N)
        cout<<"-1\n";
    else
        cout<<result[N]<<"\n";
}