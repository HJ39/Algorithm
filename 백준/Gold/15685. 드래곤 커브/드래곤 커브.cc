#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N15685;
int input15686[101][101];
int res15685 = 0;
int x15685, y15685, d15685, g15685;
vector<int> direct;

void curveMoving15685(){
    int dx[] = {1,0,-1,0};
    int dy[] = {0,-1,0,1};

    int size = (int)direct.size();
    for(int i=size-1; i>=0; --i){
        int d = (direct[i]+1) % 4;

        x15685 += dx[d];
        y15685 += dy[d];
        input15686[x15685][y15685] = 1;
        direct.push_back(d);
    }

}

void getCount(){
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++) {
            if (input15686[i][j] == 1 && input15686[i][j + 1] == 1 && input15686[i + 1][j + 1] && input15686[i + 1][j] == 1)
                res15685++;
        }
    }
}

int main(){
    fast;
    int dx[] = {1,0,-1,0};
    int dy[] = {0,-1,0,1};

    cin>>N15685;

    for(int i=0;i<N15685;++i){
        direct.clear();

        cin>>x15685>>y15685>>d15685>>g15685;

        input15686[x15685][y15685] = 1;

        x15685 += dx[d15685];
        y15685 += dy[d15685];
        input15686[x15685][y15685] = 1;
        direct.push_back(d15685);

        while (g15685--) {
            curveMoving15685();
        }
    }
    
    getCount();
    cout<<res15685<<"\n";

}
