#include <bits/stdc++.h>
using namespace std;
int mazeN,mazeM;
int mazeList[100][100]{0};

void bfs2178(int x,int y){
    queue<pair<int, int>> mazeQ;
    int mvX[] = {-1,1,0,0};
    int mvY[] = {0,0,-1,1};
    mazeQ.push({x,y});
    
    while (!mazeQ.empty()) {
        x = mazeQ.front().first;
        y = mazeQ.front().second;
        mazeQ.pop();
        
        for(int i=0;i<4;i++){
            int dX = mvX[i] + x;
            int dY = mvY[i] + y;
            
            if(dX < 0|| dY <0 || dX >= mazeN || dY >=mazeM )
                continue;
            
            if(mazeList[dX][dY] == 0)
                continue;
            
            if(mazeList[dX][dY] == 1){
                mazeQ.push({dX,dY});
                mazeList[dX][dY] = mazeList[x][y] + 1;
            }
        }
        
    }
}

int main(){
    scanf("%d%d",&mazeN,&mazeM);
    
    for(int i=0;i<mazeN;i++){
        for(int j=0;j<mazeM;j++){
            scanf("%1d",&mazeList[i][j]);
        }
    }
    
    bfs2178(0,0);
    cout<<mazeList[mazeN-1][mazeM-1]<<endl;
    
}
