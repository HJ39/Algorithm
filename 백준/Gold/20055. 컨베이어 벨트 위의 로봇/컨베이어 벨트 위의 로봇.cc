#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N20055,K20055;
deque<bool> belt20055;
deque<int> level20055;

void movingBelt20055(){
    
    belt20055.push_front(belt20055.back());
    belt20055.pop_back();
    
    level20055.push_front(level20055.back());
    level20055.pop_back();
    belt20055[N20055-1] = false;
}

void movingBobot20055(){
    
    for(int i= N20055-2; i>=0; i--){
        if(level20055[i+1] > 0 and !belt20055[i+1] and belt20055[i]){
            belt20055[i+1] = true;
            belt20055[i] = false;
            level20055[i+1]--;
        }
    }
    belt20055[N20055-1] = false;
}

void putRobot20055(){
    
    if(!belt20055[0] and level20055[0]>0){
        level20055[0]--;
        belt20055[0] = true;
    }
    
}

int checking20055(){
    int count = 0;
    for(int i=0;i<2*N20055;++i){
        if(level20055[i] == 0){
            count++;
        }
    }
    return count;
}

int main(){
    fast;
    
    cin>>N20055>>K20055;
    
    
    
    for(int i=0;i<2*N20055;++i){
        int a;
        cin>>a;
        level20055.push_back(a);
        belt20055.push_back(false);
    }
    
    
    int count = 1;
    while(1){
        movingBelt20055();
        movingBobot20055();
        putRobot20055();
        int check = checking20055();
        
        if(check >= K20055){
            cout<<count<<"\n";
            break;
        }
        count++;
    }   
}