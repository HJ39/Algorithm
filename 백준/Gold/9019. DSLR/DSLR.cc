#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int A, B;
queue<tuple<int,string>> q;
bool check[10001];
char d[] = {'D','S','L','R'};

int D(int num) { return (num*2)%10000; }
int S(int num) { return num-1 < 0 ?  9999 : num-1; }
int L(int num) { return (num%1000)*10 + (num/1000); }
int R(int num) { return (num%10)*1000 + num/10; }

void bfs(){
    
    while (!q.empty()) {
        auto [A,order] = q.front();
        q.pop();
        string n_order = order;
        
        
        int dnum = D(A);
        if(dnum == B){
            cout<<n_order<<"D\n";
            return;
        }
        else if(!check[dnum]){
            check[dnum] = true;
            n_order.push_back('D');
            q.push({dnum,n_order});
        }
        
        n_order = order;
        int snum = S(A);
        if(snum == B){
            cout<<n_order<<"S\n";
            return;
        }
        else if(!check[snum]){
            check[snum] = true;
            n_order.push_back('S');
            q.push({snum,n_order});
        }
        
        n_order = order;
        int lnum = L(A);
        if(lnum == B){
            cout<<n_order<<"L\n";
            return;
        }
        else if(!check[lnum]){
            check[lnum] = true;
            n_order.push_back('L');
            q.push({lnum,n_order});
        }
        
        n_order = order;
        int rnum = R(A);
        if(rnum == B){
            cout<<n_order<<"R\n";
            return;
        }
        else if(!check[rnum]){
            check[rnum] = true;
            n_order.push_back('R');
            q.push({rnum,n_order});
        }
    }
    
    
}

int main(){
    fast;
    
    int T;
    cin>>T;
    
    for(int i=0; i<T; ++i){
        cin>>A>>B;
        q.push({A,""});
        bfs();
        memset(check, false, sizeof(check));
        while (!q.empty()) {
            q.pop();
        }
    }
}