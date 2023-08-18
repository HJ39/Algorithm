#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    
    vector<int> lis;
    vector<pair<int, int>> array(n);
    vector<int> backTrace;
    
    for(int i=0;i<n;i++)
        scanf("%d%d",&array[i].first,&array[i].second);
    
    sort(array.begin(),array.end());
    
    lis.push_back(array[0].second);
    for(int i=0;i<array.size();i++){
        if(lis.back() < array[i].second){
            lis.push_back(array[i].second);
            backTrace.push_back(lis.size() - 1);
        }
        else{
            long index = lower_bound(lis.begin(), lis.end(), array[i].second) - lis.begin();
            lis[index] = array[i].second;
            backTrace.push_back(index);
        }
    }
    
    printf("%d\n",n-lis.size());
    
    vector<int> result;
    int temp = lis.size() - 1;
    for(int i= backTrace.size() - 1; i>=0; i--){
        if(temp == backTrace[i]){
            temp--;
            result.push_back(array[i].first);
        }
    }
    
    
    for(int i=0;i<array.size();i++){
        if(find(result.begin(),result.end(),array[i].first) == result.end()){
            printf("%d\n",array[i].first);
        }
    }
    
}

