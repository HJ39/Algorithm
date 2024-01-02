#include <bits/stdc++.h>

using namespace std;

bool check(int a, int b){return a>b; }

int main(){
    int n;
    scanf("%d",&n);
    
    vector<int> array;
    vector<int> lis;
    
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        array.push_back(num);
    }
    
    lis.push_back(array[0]);
    for(int i=0;i<n;i++){
        if(array[i] < lis.back()){
            lis.push_back(array[i]);
        }
        else{
            long index = lower_bound(lis.begin(), lis.end(), array[i], check) - lis.begin();
            lis[index] = array[i];
        }
    }
    
    printf("%d\n",lis.size());
    
}