// Submission Link: https://codeforces.com/contest/2014/submission/356013624
/*
It is only not possible to call robinhood if n is 2 or 1.
avg=(sum+k)/n.
Since we need strictly more than half of the total population strictly less than half of the average wealth
therefore we would just make our avg equal to a[n/2]+1 as then more than hal would be unhappy.
(sum+k)/(n*2)=a[n/2]+1
On solving, k=a[n/2]*n*2+1-sum
If k<0 then no need of any coin so k=0, therefore final ans is max(k, 0).
*/

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long t;
    cin>>t;
    while(t--) {
        long long n, sum=0;
        cin>>n;
        vector <long long> a(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
            sum+=a[i];
        }
        if(n<=2) {
            cout<<-1<<endl;
            continue;
        }
        sort(a.begin(), a.end());
        long long k= a[n/2]*n*2+1-sum;
        cout<<max(k, 0LL)<<endl;
    }
}
