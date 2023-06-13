#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N1991;
struct Node{
    char left;
    char right;
};
Node input1991[27];

void forwardRecursive(char root){
    if(root == '.') return;
    cout<<root;
    forwardRecursive(input1991[root].left);
    forwardRecursive(input1991[root].right);
}

void middleRecursive(char root){
    if(root == '.') return;
    middleRecursive(input1991[root].left);
    cout<<root;
    middleRecursive(input1991[root].right);
}

void backRecursive(char root){
    if(root == '.') return;
    backRecursive(input1991[root].left);
    backRecursive(input1991[root].right);
    cout<<root;
}

int main(){
    fast;
    
    cin>>N1991;
    
    for(int i=1; i<=N1991; ++i){
        char a,b,c;
        cin>>a>>b>>c;
        
        input1991[a].left = b;
        input1991[a].right = c;
        
    }
    forwardRecursive('A');
    cout<<"\n";
    middleRecursive('A');
    cout<<"\n";
    backRecursive('A');
    cout<<"\n";
}