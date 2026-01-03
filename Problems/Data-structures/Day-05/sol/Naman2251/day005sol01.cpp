//Submission Link: https://cses.fi/problemset/result/15792090/

/*
we are going through the array ans checking if the number right left to it is smaller to it then answer for that is (i-1) else we will check position ans[i-1]
if we encounter ans[i]=-1 we know there is no number smaller than that so the ans is -1
*/

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<int> ans(n);
    ans[0]=-1;
    for(int i=1;i<n;i++){
        if(vec[i]>vec[i-1]){
            ans[i]=i-1;
        }else{
            int a=ans[i-1];
            bool ok=true;
            while(a>-1){
                if(vec[a]<vec[i]){
                    ans[i]=a;
                    ok=false;
                    break;
                }
                a=ans[a];
            }
            if(ok) {
                ans[i]=-1;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]+1<<" ";
    }
}
int main(){
    solve();
}
