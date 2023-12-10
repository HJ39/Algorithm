#include <bits/stdc++.h>

using namespace std;

/*
     매 도시를 진입한다고 생각하고 각 거리에 이전에 가장 저렴한 가격의 기름값을 곱한다.
*/
int main(){
    int n;  //도시 개수
    cin>> n;
    
    vector<unsigned long long> km;
    vector<unsigned long long> price;
    unsigned long long totaldis = 0;
    // 각 도시 사이의 거리 입력
    for(int i=0;i<n-1;i++){
        long long dis;
        cin>> dis;
        totaldis += dis;
        km.push_back(dis);
    }
    
    // 각 도시 주유소의 기름 가격
    for(int i=0;i<n;i++){
        long long pr;
        cin>>pr;
        price.push_back(pr);
    }
    
    unsigned long long result = 0;
    long long minOilPrice = price[0];
    
    for(int i=0 ;i<n-1;i++){
        
        // 가격이 지금보다 저렴한 기름 값 저장
        if(minOilPrice >= price[i]){
            minOilPrice = price[i];
        }
        
        result += km[i] * minOilPrice;
        
        
    }
    
    cout<<result<<endl;
    
}
