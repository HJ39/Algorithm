#include <bits/stdc++.h>
#define MAXSIZE 101
using namespace std;
int toM3,toN3,toH3;
int inBoxSizeV3[MAXSIZE][MAXSIZE][MAXSIZE]; //면, 행, 열 순서
queue<tuple<int,int,int>> tomatoQV3;    //면, 행, 열 순서
int tomatoMaxTimeV3 = 0;

void toBFSV3(){
    int dX[] = {1,-1,0,0,0,0};
    int dY[] = {0,0,1,-1,0,0};
    int dZ[] = {0,0,0,0,1,-1};
    
    
    while (!tomatoQV3.empty()) {
        int z = get<0>(tomatoQV3.front());
        int x = get<1>(tomatoQV3.front());
        int y = get<2>(tomatoQV3.front());
        tomatoQV3.pop();
        
        for(int i=0;i<6;i++){
            int mx = x + dX[i];
            int my = y + dY[i];
            int mz = z + dZ[i];
            
            if(mx < 0 || mx > toN3 - 1 || my < 0 || my > toM3 - 1 || mz < 0 || mz> toH3 - 1 )
                continue;
            
            if(inBoxSizeV3[mz][mx][my] == 0){
                inBoxSizeV3[mz][mx][my] = inBoxSizeV3[z][x][y] + 1;
                if(tomatoMaxTimeV3 < inBoxSizeV3[mz][mx][my])
                    tomatoMaxTimeV3 = inBoxSizeV3[mz][mx][my];
                tomatoQV3.push({mz,mx,my});
            }
            
        }
        
    }
    
}


int main(){
    cin>>toM3>>toN3>>toH3;
    
    for(int k=0;k<toH3;k++){
        for(int i=0; i<toN3;i++){
            for(int j=0;j<toM3;j++){
                int input;
                scanf("%d",&input);
                inBoxSizeV3[k][i][j] = input;
                if(input == 1)
                    tomatoQV3.push({k,i,j});
            }
        }
    }
    
    toBFSV3();
    
    bool tomatoExist = false;
    for(int k=0;k<toH3;k++){
        for(int i=0;i<toN3;i++){
            int *p;
            p = find(&inBoxSizeV3[k][i][0], &inBoxSizeV3[k][i][toM3], 0);
            if(p != &inBoxSizeV3[k][i][toM3]){
                tomatoExist = true;
                break;
            }
        }
    }
    
    if(tomatoExist)
        cout<<"-1"<<endl;
    else if( tomatoMaxTimeV3 == 0)
        cout<<"0"<<endl;
    else
        cout<<tomatoMaxTimeV3 - 1<<endl;
    
}



