#include <bits/stdc++.h>
using namespace std;

int main() {
     int t;
    cin >> t;
    while(t--) {
        int n;
        cin>>n;
        long long a[n];
        for (int i = 0; i < n; ++i) {
            cin >>a[i];
        }
        sort(a,a+n);
        long long cnt_s=0;
        for (int i = 0; i < n; ++i) {
            if(a[i]==a[0]){
                cnt_s++;
            }
            else{
                break;
            }
        }
        long long cnt_l=0;
        for (int i = n-1; i >=0 ; --i) {
            if(a[i]==a[n-1]){
                cnt_l++;
            }
            else{
                break;
            }
        }
        if(cnt_s==n){
            cout << 1LL*(n)*(n-1) <<'\n';
        }
        else{
            cout <<2LL*(cnt_s)*(cnt_l)<<'\n';
        }
    }
    
    return 0;
}
//time complexity O(nlogn)
