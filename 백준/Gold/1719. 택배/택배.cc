#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
#define MAX 201
#define INF 987654321
using namespace std;

int graph[MAX][MAX];
int result[MAX][MAX];
int n,m;

int main(){
    fast;
    
    cin>>n>>m;
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if( i == j ){
                graph[i][j] = 0;
            }
            else
                graph[i][j] = INF;
        }
    }
    
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        graph[a][b] = c;
        graph[b][a] = c;
        result[a][b] = b;
        result[b][a] = a;
    }
    
    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                    result[i][j] = result[i][k];
                }
            }
        }
    }
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(i == j)
                cout << "- ";
            else
                cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}
