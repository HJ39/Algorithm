#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);

    vector<int> array;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        array.push_back(num);
    }

    vector<int> lis;
    vector<int> backTrace;
    lis.push_back(array[0]);

    for(int i=0;i<n;i++){
        if(lis.back() < array[i]){
            lis.push_back(array[i]);
            backTrace.push_back(lis.size() - 1);
        }
        else{
            long index = distance(lis.begin(), lower_bound(lis.begin(), lis.end(), array[i]));
            backTrace.push_back(index);
            lis[index] = array[i];
        }
    }

    printf("%d\n",lis.size());
    
    int temp = lis.size()-1;
    vector<int> result;
    for(int i= backTrace.size()-1; i>=0;i--){
        if(backTrace[i] == temp){
            temp--;
            result.push_back(array[i]);
        }
    }
  
    sort(result.begin(),result.end());
    
    for(int i=0;i<result.size();i++)
        printf("%d ",result[i]);
    printf("\n");
    
}