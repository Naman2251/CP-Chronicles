//Problem Link- https://codeforces.com/problemset/problem/1997/C
//Submission Link- https://codeforces.com/problemset/submission/1997/355848236
//checked greedy pairing of current index with last one in stack
//time complexity- O(n)

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    stack <pair<char,int>> s1;
    int cost=0;
    for(int i=0;i<n;i++){
        if(s1.empty()){
            s1.push({s[i],i});
        }else{
            if(s[i]==')'&&s1.top().first=='_'){
                cost+=(i-s1.top().second);
                s1.pop();
            }else if(s[i]=='('&&s1.top().first=='_'){
                s1.push({s[i],i});
            }else if(s[i]=='_'&&s1.top().first=='('){
                cost+=(i-s1.top().second);
                s1.pop();            
            }
        }
    }

     cout<<cost<<endl;
}

signed main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
