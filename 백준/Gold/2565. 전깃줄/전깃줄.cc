#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    
    vector<int> lis;
    vector<pair<int, int>> array(n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&array[i].first,&array[i].second);
    
    sort(array.begin(),array.end());
    
    lis.push_back(array[0].second);
    for(int i=0;i<array.size();i++){
        if(lis.back() < array[i].second){
            lis.push_back(array[i].second);
        }
        else{
            long index = lower_bound(lis.begin(), lis.end(), array[i].second) - lis.begin();
            lis[index] = array[i].second;
        }
    }
    
    printf("%d\n",n-lis.size());
}
