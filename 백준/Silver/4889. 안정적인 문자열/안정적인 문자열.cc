#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main(){
    fast;
    
    int ans = 1;
    stack<char> st;
    
    while (true) {
        string input;
        cin>>input;
        
        if(input[0] == '-')
            break;
        
        for(int i=0; i<input.size(); ++i) {
            char ch = input[i];
            if(ch == '{')
                st.push(ch);
            else if(ch == '}') {
                if(st.empty() or st.top() != '{')
                    st.push(ch);
                else
                    st.pop();
            }
        }
        
        int res = 0;
        while (!st.empty()) {
            char top = st.top();
            st.pop();
            
            if(st.top() != top) {
                res += 2;
            }
            else
                res++;
            st.pop();
        }
        cout<<ans++<<". "<<res<<"\n";
    }
    
}
